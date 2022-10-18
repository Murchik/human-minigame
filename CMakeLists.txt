cmake_minimum_required(VERSION 3.1)

project(human-minigame)

# sources
file(GLOB all_SRCS "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${all_SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC include)

# OpenGl
find_package(OpenGL REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})

# GLAD
add_subdirectory(lib/glad glad_opengl_4.6)
target_include_directories(${PROJECT_NAME} PRIVATE lib/glad/include)
target_link_libraries(${PROJECT_NAME} glad_opengl_4.6)

# GLFW options
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

# GLFW
add_subdirectory(lib/GLFW glfw)
target_include_directories(${PROJECT_NAME} PRIVATE lib/GLFW/include)
target_link_libraries(${PROJECT_NAME} glfw)

# MSVC setup
if(MSVC)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif()

if(MSVC)
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0")
        message("\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set '${PROJECT_NAME}' as StartUp Project in Visual Studio.\n")
    else()
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
    endif()
endif()
