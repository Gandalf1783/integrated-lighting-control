#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <csignal>

#include "config/Config.hpp"

#include "logger/Log.hpp"

#include "state/State.hpp"

#include "dmx_engine/DMXEngine.hpp"
#include "dmx_output/ArtNet.hpp"

#include "session/SessionManager.hpp"
#include "network/NetworkManager.hpp"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"

#define ANSI_COLOR_RESET   "\x1b[0m"

using namespace std;

void signalHandler( int signum ) {
    printf("\n\n[" ANSI_COLOR_RED "ILC" ANSI_COLOR_RESET "] RECEIVED SIGNAL %d\n", signum);
    
    if(signum == SIGTERM) {
        printf("[\n\n" ANSI_COLOR_RED "ILC" ANSI_COLOR_RESET "] " ANSI_COLOR_RED "SIGTERM - STOPPING" ANSI_COLOR_RESET "\n\n");
        currentState = STOPPING;
    }

    if(signum == SIGINT) {
        printf("\n\n[" ANSI_COLOR_RED "ILC" ANSI_COLOR_RESET "] " ANSI_COLOR_YELLOW "INTERRUPT - STOPPING" ANSI_COLOR_RESET "\n\n");
        currentState = STOPPING;
    }
}

int main() {
    DMXEngine* engine; 
    Log* logger;
    SessionManager *sessionManager;
    NetworkManager *networkManager;
    
    readConfig();

    signal(SIGTERM, signalHandler); // Handle incoming Signals
    logger = new Log();

    networkManager = new NetworkManager();
    sessionManager = new SessionManager(networkManager); // Pass networkManager for IP-Addresses

    engine = new DMXEngine(); // Start the DMX-Engine
    
    networkManager->updateIPs();
    
    sessionManager->init();

    //engine->addOutput(new ArtNet());
    engine->start();

    
    // The Engine has prepared for everything. Now we can show the window since it blocks the main-thread.

    currentState = RUNNING;
    // std::this_thread::sleep_for(10000ms); // Demo Timeout
    while(currentState != STOPPING) {

        if(currentState == STOP_REQUEST) { // Internal console event (Stop-Request)
           currentState == STOPPING; // STOP PROGRAM
        }

        std::this_thread::sleep_for(500ms);
    }

    // Window/App has closed
    // Therefore, we stop and free the dmxengine 
    engine->stop();
    engine->freeMemory();


    // All threads have stopped. Exit:

    delete sessionManager;
    delete networkManager;
    delete engine;
    delete logger;

    return 0;
};
