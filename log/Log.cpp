#include "Log.hpp"


Log::Log() {
    this->logLength = 0;
};

void Log::createLog(int logLength) {

    if(logLength >= LOG_EVENT_LENGTH_MAX) {
        printf("[LOG] Could not create log with a size of %d. Creating one with %d now.", logLength, LOG_EVENT_LENGTH_DEFAULT);
        logEvents = (LogEvent*) malloc(sizeof(LogEvent) * LOG_EVENT_LENGTH_DEFAULT);
    } else {
        logEvents = (LogEvent*) malloc(sizeof(LogEvent) * logLength);
    }

    if(logEvents != NULL) {
        this->logLength = logLength; // Shows that the log has been created!
    }
};

void Log::test() {
    printf("LOG TEST \n");
}

void Log::logException(int errorID) {
    printf("[LOG] A EXCEPTION WITH STATUS %d OCCURED.", errorID);
    this->writeLogToDisk(); // Save Log Entries
    exit(errorID);
};

void Log::stop() {
    if(logLength > 0 && logEvents != NULL) {
        
        for(int i = 0; i < loggedEvents; i++) {
            LogEvent* currentLog = (logEvents + (sizeof(LogEvent) * i));
            currentLog->stop();
        }

        free(logEvents);
    }
}

void Log::writeLogToDisk() {
    
}