#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../logger/Log.hpp"
#include "../config/Config.hpp"

#ifndef IPCMANAGER_HPP
#define IPCMANAGER_HPP

class IPCManager {
    private: 
        
    public:
        IPCManager(Log* logger);
        ~IPCManager();

};

#endif