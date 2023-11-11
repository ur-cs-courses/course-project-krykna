# Add an executable for the main application
add_executable(MainApp main.cpp ../src/Management.cpp ../src/Robot.cpp ../src/Room.cpp)

target_link_libraries(MainApp
  fmt::fmt
)
