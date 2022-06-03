#include "LogEvent.hpp"

#include "../gfx/Display.hpp"

LogEvent::LogEvent(int errorID, int errorSource) {
    this->errorID = errorID;
    this->errorSource = errorSource;
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