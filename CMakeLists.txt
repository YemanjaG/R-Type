#cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
#
## Set project name and version
#project(R-Type VERSION 0.1)
#
## Set C++ standard
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
#
## Enable debug symbols by default
#if(NOT CMAKE_BUILD_TYPE)
#    set(CMAKE_BUILD_TYPE Debug
#            CACHE STRING
#            "Choose the type of build (Debug or Release)"
#            FORCE
#            )
#endif()
#
## Generate config.h
## configure_file(config.h.in config.h)
#
## Find SFML shared libraries
#find_package(SFML 2.5.1
#        COMPONENTS
#        system window graphics network audio REQUIRED
#        )
#
#include(FetchContent)
#
##Asio Fetch
#FetchContent_Declare(asio-cmake
#        GIT_REPOSITORY https://github.com/kingsamchen/asio-cmake.git
#        GIT_TAG        origin/master
#        )
#
## Specify asio version
##set(ASIO_CMAKE_ASIO_TAG asio-1-12-2)
##FetchContent_MakeAvailable(asio-cmake)
#
## ...
#
#
## Compile executable
#add_executable(R-Type Src/main.cpp)
## Set include directory search paths
#
#
## Link executable to required SFML libraries
#target_link_libraries(R-Type sfml-graphics)
##Asio link
## target_link_libraries(R-Type asio)
#
##target_include_directories($/Users/gabrieldetaxis/Documents/Library/FrameWorks/SFML.framework/Versions/2.5.1/Headers)
#
## target_include_directories(R-Type
##        PRIVATE
##       "${PROJECT_BINARY_DIR}"
##      )
#
#
#
## Install target
#install(TARGETS R-Type DESTINATION bin)

cmake_minimum_required(VERSION 3.14)
project(R-Type)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Src/main.cpp)
add_executable(R-Type ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(R-Type sfml-system sfml-window sfml-graphics sfml-audio sfml-network)