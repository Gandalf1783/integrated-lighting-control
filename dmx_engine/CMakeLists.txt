set(engineSrc DMXEngine.cpp Universe.cpp)

message("-- Adding target \"dmx_engine\"")

add_subdirectory(effects)
add_library(dmxengine STATIC ${engineSrc})
