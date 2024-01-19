set(log_src Log.cpp LogEvent.cpp)

message("-- Adding target \"log\"")

add_library(log STATIC ${log_src})