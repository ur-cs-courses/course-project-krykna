add_executable(fleet_manager
  fleet_manager.cpp
)

target_link_libraries(fleet_manager
  PRIVATE
    manage
    libRobot
    libroom
)

target_compile_features(fleet_manager PRIVATE cxx_std_20)
