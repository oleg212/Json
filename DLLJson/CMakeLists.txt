cmake_minimum_required(VERSION 3.6)

project(DLL)

set(CMAKE_CXX_STANDART 17)

set(TARGET "DLL")

file(GLOB TARGET_SRC "*.c*")
file(GLOB TARGET_HD "*.h*")
add_library(${TARGET} SHARED ${TARGET_SRC} ${TARGET_HD})

target_include_directories(${TARGET} PUBLIC "D:/git_reps/Json/StatLibJson")
target_link_libraries(${TARGET} StatLibJson)