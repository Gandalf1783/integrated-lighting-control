set(session_src SessionManager.cpp Session.cpp Station.cpp SessionAPI.cpp)

message("-- Adding target \"session\"")

add_library(session STATIC ${session_src})