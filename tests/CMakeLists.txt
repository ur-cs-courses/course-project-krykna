find_package(Catch2 REQUIRED)

IF (${Catch2_FOUND})
    MESSAGE(STATUS "Found Catch2")
ELSE (${Catch2_FOUND})
    MESSAGE(STATUS "Cound not find Catch2. Check to make sure its installed on your system!")
ENDIF (${Catch2_FOUND})

add_executable(manage_test test_management.cpp)
add_executable(room_class_test room_class_test.cpp)
add_executable(robot_class_test robot_class_test.cpp)

# Add .csv files to the build; file path for testing: "input_test_files/[filename].csv"
file(COPY ${PROJECT_SOURCE_DIR}/tests/room_test.csv ${PROJECT_SOURCE_DIR}/tests/robot_test.csv DESTINATION input_test_files)

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