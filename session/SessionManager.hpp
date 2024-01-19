#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <memory>

#include "Session.hpp"
#include "Station.hpp"
#include "SessionAPI.hpp"
#include "../network/NetworkManager.hpp"


#ifndef SESSIONMANAGER_HPP
#define SESSIONMANAGER_HPP

enum SessionState { ALONE, MASTER, CONNECTED, CREATING, DESTROYING };

class SessionManager {
    public:
        SessionManager(std::shared_ptr<NetworkManager> networkManager);
        ~SessionManager();
        void init();
        void createSession(unsigned int sessionID, char* sessionName);
        void leaveSession();
        void destroySession(); 
    private:
        std::unique_ptr<Session> currentSession;
        SessionState currentState; // No Pointer needed, since this is an enum
        std::unique_ptr<SessionAPI> sessionAPI;

        std::thread sessionBroadcastThread;
        std::thread sessionDiscoverThread;
        std::shared_ptr<NetworkManager> networkManager;

};

#endif
