#include "IPCManager.hpp"


IPCManager::IPCManager(std::shared_ptr<Log> logger) {
    this->logger = logger;
    printf("[IPCManager] Initiating IPC...\n");
    std::string defaultPort = currentConfig.get<std::string>("ipc.defaultPort");
};

void IPCManager::start() {
    const std::string endpoint = "tcp://*:5555";

    zmqpp::context context;
};

IPCManager::~IPCManager() {
    printf("[IPCManager] Closing IPC...\n");
};