cmake_minimum_required(VERSION 3.16)
project(FleetManagement)
set(CMAKE_CXX_STANDARD 17) # Replace 17 with the standard you need
set(CMAKE_CXX_STANDARD_REQUIRED True)
include(dependencies.cmake)

add_library(catch2 INTERFACE)
add_library(manage src/Management.cpp)
add_library(libRobot src/Robot.cpp)
add_library(libroom src/room.cpp)

target_include_directories(catch2
  INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_include_directories(manage
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)
target_include_directories(libRobot
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)
target_include_directories(libroom
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_link_libraries(manage
  PUBLIC libRobot
  PUBLIC libroom
)

add_subdirectory(app)
add_subdirectory(tests)
