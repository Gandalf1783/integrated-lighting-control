set(effectsSrc Effect.cpp SineWave.cpp)

message("-- Adding target \"dmx_engine\\effects\"")

add_library(effects STATIC ${effectsSrc})