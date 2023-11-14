add_executable(catch2Run catch2Testing.cpp)

target_link_libraries(catch2Run 
    PRIVATE manage 
    PRIVATE libRobot
    PRIVATE libroom
)

target_compile_features(catch2Run PRIVATE cxx_std_20)