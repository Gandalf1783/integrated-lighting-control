#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <thread>

#include "Session.hpp"
#include "Station.hpp"
#include "SessionAPI.hpp"
#include "../network/NetworkManager.hpp"


#ifndef SESSIONMANAGER_HPP
#define SESSIONMANAGER_HPP

enum SessionState { ALONE, MASTER, CONNECTED, CREATING, DESTROYING };

class SessionManager {
    public:
        SessionManager(NetworkManager* networkManager);
        ~SessionManager();
        void init();
        void createSession(unsigned int sessionID, char* sessionName);
        void leaveSession();
        void destroySession(); 
    private:
        Session* currentSession;
        SessionState currentState;
        SessionAPI* sessionAPI;

        std::thread sessionBroadcastThread;
        std::thread sessionDiscoverThread;
        NetworkManager* networkManager;

};

#endif
