#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

#include <zmqpp/zmqpp.hpp>

#include "../logger/Log.hpp"
#include "../config/Config.hpp"

#ifndef IPCMANAGER_HPP
#define IPCMANAGER_HPP

class IPCManager {
    private: 
        bool shouldThreadStop;
        std::shared_ptr<Log> logger;
        std::shared_ptr<zmqpp::context> context;
        zmqpp::socket_type type; // No PTR needed, just an enum
        std::shared_ptr<zmqpp::socket> socket;
        std::thread zmqppThread;
    public:
        IPCManager(std::shared_ptr<Log> logger);
        void start();
        void receiveLoop();
        ~IPCManager();

};

#endif