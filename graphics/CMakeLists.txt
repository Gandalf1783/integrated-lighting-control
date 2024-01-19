set(uiSrc UI.cpp Display.cpp)

message("-- Adding target \"graphics\"")

add_subdirectory(objects)
add_library(ui STATIC ${uiSrc})