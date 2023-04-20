set(output_src Output.cpp ArtNet.cpp)

message("-- Adding target \"dmx_outputs\"")

add_library(dmx_outputs STATIC ${output_src})