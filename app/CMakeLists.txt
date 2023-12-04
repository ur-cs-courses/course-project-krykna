set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(fleet_manager
  fleet_manager.cpp
)

target_link_libraries(fleet_manager
  PRIVATE
    manage
    libRobot
    libroom
    Threads::Threads
)

target_compile_features(fleet_manager PRIVATE cxx_std_20)