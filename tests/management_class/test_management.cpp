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
void test_initialize_room_list_from_csv() {
    const std::string testCsvPath = "tests/management_class/room_test.csv";
    Management management(testCsvPath);
    std::cout << management.to_string_room_list() << std::endl;
}


int main() {
    test_initialize_room_list_from_csv();
    return 0;
}
