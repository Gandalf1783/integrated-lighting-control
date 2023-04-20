set(channelSrc Channel.cpp)

message("-- Adding target \"fixture\\channel\"")

add_library(channel STATIC ${channelSrc})
