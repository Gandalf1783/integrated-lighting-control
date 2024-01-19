#include "SessionManager.hpp"

SessionManager::SessionManager(NetworkManager *networkManager) {
    this->sessionAPI = new SessionAPI();
    this->networkManager = networkManager;
};

SessionManager::~SessionManager() {
    this->sessionAPI->stop();
    delete this->sessionAPI;
};

void SessionManager::init() {
    this->sessionAPI->init(this->networkManager->retrieveInterfaces().at(0));
    this->sessionAPI->start();
}

void SessionManager::createSession(unsigned int sessionID, char* sessionName) {
    
}

void SessionManager::leaveSession() {
    if(this->currentState != CONNECTED) {
        return;
    }

}

void SessionManager::destroySession() {
    if(this->currentState != MASTER) {
        return;
    }

}