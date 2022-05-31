#include <stdio.h>
#include <stdlib.h>

#include "LogEvent.hpp"

#define LOG_EVENT_LENGTH_DEFAULT 100

#ifndef LOG_EVENT_LENGTH_MAX
#define LOG_EVENT_LENGTH_MAX 200
#endif



#ifndef LOG_HPP
#define LOG_HPP



class Log {
	private:
		LogEvent* logEvents;
		int logLength;
		int loggedEvents;
	public:
		Log();
		void createLog(int logLength);
		void logException(int errorID);
		void stop();
		void test();
		void writeLogToDisk();
};


#endif
