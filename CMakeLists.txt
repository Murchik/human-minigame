cmake_minimum_required(VERSION 3.1)

project(human-minigame)

file(GLOB all_SRCS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${all_SRCS})


add_subdirectory(lib/GLFW)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

target_include_directories(${PROJECT_NAME}
    PUBLIC include
    PUBLIC lib/GLFW/include
)

target_link_directories(${PROJECT_NAME} PRIVATE lib/GLFW/src)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME}
    glfw
    opengl32 # TODO: change to PACKAGE_FIND_NAME found by find_package(OpenGL REQUIRED)
)