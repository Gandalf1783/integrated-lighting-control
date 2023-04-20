#include "SessionAPI.hpp"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"

#define ANSI_COLOR_RESET   "\x1b[0m"



SessionAPI::SessionAPI() {
    this->shouldThreadStop = false;
};

void SessionAPI::init(interfaceMeta interface) {
    int broadcastEnable = 1;
    int sessionID = currentConfig.get<int>("session.sessionID");
    
    std::string sessionNameStr = currentConfig.get<std::string>("session.sessionName");
    const char * sessionName = sessionNameStr.c_str();

    this->currentInterface = interface;

    socketFD = socket(AF_INET, SOCK_DGRAM, 0);

    if (socketFD < 0) {
        perror("[SessionAPI] Could not create UDP-Socket for SessionAPI Output!");
        exit(1);
    }


    if(setsockopt(this->socketFD, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable)) < 0 ) {
        printf("[SessionAPI] Socket Options failed!\n");
        exit(2);
    }



    /* set up local address and port of the socket*/
    memset(&localAddress,0,sizeof(localAddress));
    localAddress.sin_family = AF_INET;
    localAddress.sin_port=htons(SESSION_UDP_PORT);
    localAddress.sin_addr = interface.ipAddr;

    

    if (bind(this->socketFD, (struct sockaddr *) &localAddress, sizeof(localAddress)) < 0) {
        perror("[SessionAPI] Error binding socket");
        exit(5);
    }

    /* set up broadcast address */
    memset(&broadcastAddress,0,sizeof(broadcastAddress));
    broadcastAddress.sin_family = AF_INET;
    broadcastAddress.sin_port=htons(SESSION_UDP_PORT);
    broadcastAddress.sin_addr = interface.broadcast;

    

    discover();
    
    createSession(sessionID, sessionName);
    broadcastStationAndState();

    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_MAGENTA "SessionAPI" ANSI_COLOR_RESET "] : ILCNET started on Interface with IP %s.\n", inet_ntoa(interface.ipAddr));
};

void SessionAPI::start() {
    this->receiveThread = std::thread(&SessionAPI::receiveLoop, this);
}

void SessionAPI::receiveLoop() {
    char buffer[MAX_MSG_LEN]; 

    pollfd pfd[1];
    pfd[0].fd = this->socketFD;
    pfd[0].events = POLLIN;

    struct sockaddr_in remoteAddr;
    socklen_t addrLen = sizeof(remoteAddr);

    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_MAGENTA "SessionAPI" ANSI_COLOR_RESET "] : Receiveloop started on PID %d\n", getpid());

    while(!this->shouldThreadStop) {

        if(poll(pfd, 1, 1000) <= 0) { // Sees if any data has been received in 1000ms. If not, just continue.
            broadcastStationAndState();
            continue;
        }
        
        int bytesReceived = recvfrom(this->socketFD, buffer, MAX_MSG_LEN, 0, (struct sockaddr *) &remoteAddr, &addrLen);
        
        printf("RECEIVED %d BYTES\n\n", bytesReceived);

        if (bytesReceived <= 0) {
            std::cerr << "Error receiving ILCNET-Message" << std::endl;
            continue;
        }

        in_addr remoteIp = remoteAddr.sin_addr;

        in_addr localIP = this->currentInterface.ipAddr;

        if(remoteIp.s_addr == localIP.s_addr) {
            // Broadcast from this station. Skip!
            continue;
        }     

        switch (buffer[0]) {
            case CREATE:
                printf("Someone created a Session!\n");
                break;
            case JOIN:
                printf("Someone wants to join this Session!\n");
                break;
            case DESTROY:
                printf("The Session you participated in has been destroyed!\n");
                break;
            case LEAVE:
                printf("A station has left the session!");
                break;
            case BEACON_STATION:
                printf("Station was found (BEACON_STATION received)!...\n");
                this->availableStations.push_back(new Station(remoteIp));
                break;
            case BEACON_SESSION:
                printf("Found another session!...\n");  
                break;
            case DISCOVER:
                printf("Replying to DISCOVER Request...\n");
                replyStation(&remoteAddr);
                break;
            case DISCOVER_RESPONSE:
                printf("Someone has replied to this stations discover request!\n");
                break;
            case SESSION_REQUEST:
                printf("Someone has askes for sessions!\n");
                break;
            case SESSION_RESPONSE:
                printf("Someone has replied to this stations session request!\n");
                break;
            default:
                break;
        }
    }
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_MAGENTA "SessionAPI" ANSI_COLOR_RESET "] : Receiveloop ended.\n");
};

void SessionAPI::replyStation(struct sockaddr_in* remoteAddress) {
    char finalArray[1];

    finalArray[0] = BEACON_STATION;
    
    int res = sendto(socketFD, &finalArray, sizeof(finalArray), 0,(struct sockaddr *) &remoteAddress, sizeof(remoteAddress)); 
    
    if (res < 0) {
        printf("RES: %d\n", res);
        perror("sendto");
        exit(1);
    }
}

void SessionAPI::discover() {
    char* finalArray = (char*) malloc(7);

    *(finalArray + 0) = 'I';
    *(finalArray + 1) = 'L';
    *(finalArray + 2) = 'C';
    *(finalArray + 3) = 'N';
    *(finalArray + 4) = 'E';
    *(finalArray + 5) = 'T';
    *(finalArray + 6) = DISCOVER;
    
    
    int res = sendto(socketFD, finalArray, 7, 0,(struct sockaddr *) &(this->broadcastAddress), sizeof(this->broadcastAddress)); 
    
    if (res < 0) {
        printf("RES: %d\n", res);
        perror("sendto");
        exit(1);
    }

    if(finalArray == nullptr)
        return;

    free(finalArray);
    finalArray = nullptr;
}

void SessionAPI::createSession(unsigned int sessionID, const char * sessionName) {
    unsigned char sessionNameLength = std::min((int) strlen(sessionName), 255);

    int length = sessionNameLength + 9;

    char* finalArray = (char*) malloc(length);

    *(finalArray + 0) = 'I';
    *(finalArray + 1) = 'L';
    *(finalArray + 2) = 'C';
    *(finalArray + 3) = 'N';
    *(finalArray + 4) = 'E';
    *(finalArray + 5) = 'T';
    *(finalArray + 6) = CREATE;
    *(finalArray + 7) = sessionID;
    *(finalArray + 8) = sessionNameLength;
    

    for(int i = 0; i < sessionNameLength; i++) {
        *(finalArray +i + 9) = *(sessionName +i);
    }

    this->sessionID = sessionID;

    int res = sendto(socketFD, finalArray, length, 0,(struct sockaddr *) &(this->broadcastAddress), sizeof(this->broadcastAddress)); 
    
    if (res < 0) {
        printf("RES: %d\n", res);
        perror("sendto");
        exit(1);
    }
    // free(sessionName);
    if(finalArray == nullptr)
        return;

    free(finalArray);
    finalArray = nullptr;
}

void SessionAPI::broadcastStationAndState() {
    char* finalArray = (char*) malloc(8);

    *(finalArray + 0) = 'I';
    *(finalArray + 1) = 'L';
    *(finalArray + 2) = 'C';
    *(finalArray + 3) = 'N';
    *(finalArray + 4) = 'E';
    *(finalArray + 5) = 'T';
    *(finalArray + 6) = BEACON_SESSION;
    *(finalArray + 7) = this->sessionID;
    
    int res = sendto(socketFD, finalArray, sizeof(finalArray), 0,(struct sockaddr *) &(this->broadcastAddress), sizeof(this->broadcastAddress)); 
    
    if (res < 0) {
        printf("[SESSION] - RES: %d\n", res);
        perror("sendto");
        exit(1);
    }

    if(finalArray == nullptr)
        return;

    free(finalArray);
    finalArray = nullptr;
}

void SessionAPI::stop() {
    this-> shouldThreadStop = true;
    //close(this->socketFD);
    receiveThread.join();
    close(this->socketFD);
};