set(ipc_src IPCManager.cpp)

message("-- Adding target \"ipc\"")

add_library(ipc STATIC ${ipc_src})