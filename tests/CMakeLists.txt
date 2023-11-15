find_package(Catch2 REQUIRED)

IF (${Catch2_FOUND})
    MESSAGE(STATUS "Found Catch2")
ELSE (${Catch2_FOUND})
    MESSAGE(STATUS "Cound not find Catch2. Check to make sure its installed on your system!")
ENDIF (${Catch2_FOUND})

add_executable(manage_test test_management.cpp)
add_executable(room_class_test room_class_test.cpp)
add_executable(robot_class_test robot_class_test.cpp)

set(room_input_csv ${CMAKE_CURRENT_SOURCE_DIR}/room_test.csv)
set(robot_input_csv ${CMAKE_CURRENT_SOURCE_DIR}/robot_test.csv)

target_link_libraries(manage_test
  PRIVATE
    Catch2::Catch2WithMain
    manage
)

target_link_libraries(room_class_test
  PRIVATE
    Catch2::Catch2WithMain
    libroom
)

target_link_libraries(robot_class_test
  PRIVATE
    Catch2::Catch2WithMain
    libRobot
)

target_compile_features(manage_test PRIVATE cxx_std_20)
target_compile_features(room_class_test PRIVATE cxx_std_20)
target_compile_features(robot_class_test PRIVATE cxx_std_20)