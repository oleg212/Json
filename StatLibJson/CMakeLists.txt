cmake_minimum_required(VERSION 3.6)

project(StatLibJson)

set(CMAKE_CXX_STANDART 17)

set(TARGET "StatlibJson")

set(ANTLR_DIR "C:/Users/Main/Desktop/ANTLR/tmp")

set(ANTLR_INCLUDE "/include/antlr4-runtime")
set(ANTLR_LIB "/lib/antlr-runtime.lib")

file(GLOB TARGET_SRC "*.c*")
file(GLOB TARGET_HD "*.h*")
add_library(${TARGET} ${TARGET_SRC} ${TARGET_HD})

target_include_directories(${TARGET} PUBLIC ${ANTLR_DIR}${ANTLR_INCLUDE})
target_link_libraries(${TARGET} ${ANTLR_DIR}${ANTLR_LIB})