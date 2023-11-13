#include "../../include/manage/Management.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


// void my_assert(bool condition, const std::string& message) {
//     if (!condition) {
//         std::cerr << "Test failed: " << message << std::endl;
//     } else {
//         std::cout << "Test passed." << std::endl;
//     }
// }

// Test for initialize_room_list_from_csv_file
void test_initialize_system_from_csv() {
    const std::string test_csv_rooms = "tests/management_class/room_test.csv";
    const std::string test_csv_robots = "tests/management_class/robot_test.csv";
    Management management(test_csv_rooms, test_csv_robots);
    std::cout << management.to_string_room_list() << std::endl;
    std::cout << management.to_string_robot_list() << std::endl;
}


int main() {
    test_initialize_system_from_csv();
    return 0;
}
