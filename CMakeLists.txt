cmake_minimum_required(VERSION 3.16)
project(FleetManagement)

include(dependencies.cmake)

add_library(manage src/Management.cpp)
add_library(libRobot src/Robot.cpp)
add_library(libroom src/room.cpp)

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

# add_subdirectory(app)
add_subdirectory(tests)
