#include "IPCManager.hpp"


IPCManager::IPCManager(std::shared_ptr<Log> logger) {
    this->logger = logger;
    printf("[IPCManager] Initiating IPC...\n");
    std::string defaultPort = currentConfig.get<std::string>("ipc.defaultPort");
};

IPCManager::~IPCManager() {
    printf("[IPCManager] Closing IPC...\n");
};