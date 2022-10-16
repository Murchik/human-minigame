cmake_minimum_required(VERSION 3.1)

project(human-minigame)

file(GLOB all_SRCS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${all_SRCS})

find_package(OpenGL REQUIRED)

add_subdirectory(lib/GLFW)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

target_include_directories(${PROJECT_NAME}
    PUBLIC include
    PUBLIC lib/GLFW/include
    ${OPENGL_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME}
    PRIVATE lib/GLFW/src
)

target_link_libraries(${PROJECT_NAME}
    glfw
    ${OPENGL_LIBRARIES}
)
