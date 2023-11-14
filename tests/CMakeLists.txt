add_executable(manage_test test_management.cpp robot_test.csv room_test.csv)
add_executable(room_class_test room_class_test.cpp)
add_executable(robot_class_test robot_class_test.cpp)

# file(GLOB CSV_FILES "*.csv") 
# file(COPY ${CSV_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

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

add_subdirectory(management_class)