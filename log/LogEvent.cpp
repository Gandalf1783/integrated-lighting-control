#include "LogEvent.hpp"

LogEvent::LogEvent(int errorID, int errorSource) {

};

int LogEvent::getErrorID() {
    return this->errorID;
};

int LogEvent::getErrorSource() {
    return this->errorSource;
};

void LogEvent::stop() {
    if(errorDescription != NULL) {
        free(errorDescription);
    }
}