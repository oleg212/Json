cmake_minimum_required(VERSION 3.6)

project(Json.exe)

set(CMAKE_CXX_STANDART 17)

set(TARGET Json.exe)

set(Json_DIR "D:/git_reps/Json")

set(Json_LIB "/StatLibJson")

file(GLOB TARGET_SRC "*.c*")
file(GLOB TARGET_HD "*.h*")
add_executable(${TARGET} ${TARGET_SRC} ${TARGET_HD})

target_include_directories(${TARGET} PUBLIC ${Json_DIR}${Json_LIB})
target_link_libraries(${TARGET} StatLibJson)