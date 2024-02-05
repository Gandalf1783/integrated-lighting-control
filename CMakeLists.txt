### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 3.13)

project(CustomDMXEngine)

find_package(Threads REQUIRED)
find_package(ZeroMQ REQUIRED)

#add_compile_options(-fsanitize=undefined,address)
#add_link_options(-fsanitize=undefined,address)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)


message("-- The build directory is " ${CMAKE_BINARY_DIR})

message("-- Adding libraries/classes: ") 
add_subdirectory(dmx_engine)
add_subdirectory(dmx_output)
add_subdirectory(logger)
add_subdirectory(fixture)
add_subdirectory(session)
add_subdirectory(network)
add_subdirectory(config)
add_subdirectory(ipc)


add_executable(ilc main.cpp)
target_include_directories(effects PUBLIC ${CMAKE_CURRENT_LIST_DIR}/dmx_engine/effects)
target_link_libraries(ilc ipc effects dmxengine config network log session dmx_outputs fixture channel Threads::Threads zmq zmqpp)


message("### CMake has completed! ###")