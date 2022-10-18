cmake_minimum_required(VERSION 3.1)

project(glad_opengl_4.6)

file(GLOB all_SRCS "${PROJECT_SOURCE_DIR}/src/*.c")

add_library(${PROJECT_NAME} ${all_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC include)
