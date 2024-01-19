#include "IPCManager.hpp"


IPCManager::IPCManager(Log* logger) {
    printf("[IPCManager] Initiating IPC...\n");
    std::string defaultPort = currentConfig.get<std::string>("ipc.defaultPort");
};

IPCManager::~IPCManager() {
    printf("[IPCManager] Closing IPC...\n");
};