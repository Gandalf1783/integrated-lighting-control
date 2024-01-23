#include "IPCManager.hpp"


IPCManager::IPCManager(std::shared_ptr<Log> logger) {
    this->logger = logger;
    printf("[IPCManager] Initiating IPC...\n");
    std::string defaultPort = currentConfig.get<std::string>("ipc.defaultPort");
};

void IPCManager::start() {
    const std::string endpoint = "tcp://*:5555";

    this->context = std::make_unique<zmqpp::context>();

    this->type = zmqpp::socket_type::reply;
    this->socket = std::make_unique<zmqpp::socket>(*(this->context.get()),this->type);

    this->socket->bind(endpoint);

    //TODO: Start Thread to listen
};

IPCManager::~IPCManager() {
    printf("[IPCManager] Closing IPC...\n");
};