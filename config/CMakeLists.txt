set(config_src Config.cpp)

message("-- Adding target \"config\"")

add_library(config STATIC ${config_src})