add_executable(catch2Run catch2Testing.cpp)

file(GLOB CSV_FILES "*.csv") 
file(COPY ${CSV_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(catch2Run 
    PRIVATE manage 
    PRIVATE libRobot
    PRIVATE libroom
)

target_compile_features(catch2Run PRIVATE cxx_std_20)