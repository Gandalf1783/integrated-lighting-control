set(gdtfSrc GDTF_Fixture.cpp)

message("-- Adding target \"fixture\\gdtf\"")

add_library(gdtf STATIC ${gdtfSrc})
