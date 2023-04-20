set(fixtureSrc Fixture.cpp)

message("-- Adding target \"fixture\"")

add_subdirectory(channel)
add_subdirectory(gdtf)
add_library(fixture STATIC ${fixtureSrc})
