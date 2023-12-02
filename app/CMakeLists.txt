add_executable(fleet_manage_app
  fleet_management.cpp
)

target_link_libraries(fleet_manage_app
  PRIVATE manage
  PRIVATE libRobot
  PRIVATE libroom
)

target_compile_features(fleet_manage_app PRIVATE cxx_std_20)
