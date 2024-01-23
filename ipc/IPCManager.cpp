#include "IPCManager.hpp"


IPCManager::IPCManager(std::shared_ptr<Log> logger) {
    this->logger = logger;
    printf("[IPCManager] Initiating IPC...\n");
    std::string defaultPort = currentConfig.get<std::string>("ipc.defaultPort");
};

void IPCManager::start() {
    const std::string endpoint = "tcp://*:5555";

    printf("[IPCManager[] Creating context...\n");
    this->context = std::make_shared<zmqpp::context>();

    printf("[IPCManager[] Setting socket-type...\n");
    this->type = zmqpp::socket_type::router;
    printf("[IPCManager[] Creating socket...\n");
    this->socket = std::make_shared<zmqpp::socket>(*(this->context.get()),this->type);

    printf("[IPCManager[] Binding...\n");
    this->socket->bind(endpoint);

    printf("[IPCManager[] Done lol \\o/\n");
    //TODO: Start Thread to listen
    this->shouldThreadStop = false;
    this->zmqppThread = std::thread(&IPCManager::receiveLoop, this);

};

void IPCManager::receiveLoop() {
    while(!this->shouldThreadStop) {
        
        //Receive ZMQ messages here
        zmqpp::message message;
        
        this->socket->receive(message, false);
        std::string s1 = message.get(0);
        std::string s2 = message.get(1);
        
        std::cout << s1 << " " << s2 << std::endl;
        
        //ATTENTION: S2 is a String Object and IS INDEED VALUE-COMPARED HERE!
        if(s2 == "LOGIN") {
            zmqpp::message response;
            response.add(s1);
            response.add("");
            response.add("OK");
            this->socket->send(response);
        }

    }
}

IPCManager::~IPCManager() {
    printf("[IPCManager] Closing IPC...\n");
};