set(effectsSrc Waveform.cpp Effect.cpp)

message("-- Adding target \"dmx_engine\\effects\"")

add_library(effects STATIC ${effectsSrc})
