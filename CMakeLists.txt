cmake_minimum_required(VERSION 3.6)

project(Json)

set(CMAKE_CXX_STANDART 17)

include_directories(StatLibJson)
include_directories(Json.exe)
include_directories(DLLJson)

add_subdirectory(StatLibJson)
add_subdirectory(Json.exe)
add_subdirectory(DLLJson)