# Root CMakeLists.txt file for Configuration
cmake_minimum_required(VERSION 3.16)
project(RobotFleetManager)

# Include dependencies
include(dependencies.cmake)

# Include directories for header files
include_directories(include/manage include/libRobot include/libroom)

# Add subdirectory for the main application
add_subdirectory(app)
