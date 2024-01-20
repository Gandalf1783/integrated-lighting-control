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
        std::shared_ptr<Log> logger;
             
    public:
        IPCManager(std::shared_ptr<Log> logger);
        void start();
        ~IPCManager();

};

#endif