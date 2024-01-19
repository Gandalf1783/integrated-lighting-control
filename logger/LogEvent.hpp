#include <stdio.h>
#include <stdlib.h>

#ifndef LOG_EVENT_HPP
#define LOG_EVENT_HPP

class LogEvent {
    private:
        int errorID;
        int errorSource;
        char *errorDescription;
    public:
        LogEvent(int errorID, int errorSource);
        int getErrorID();
        int getErrorSource();
        void stop();
};

#endif