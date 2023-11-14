#include "catch.hpp"
#include "manage/Management.hpp"

TEST_CASE("Testing Compatibility of Management with Room and Robot Classes") {
    const std::string test_csv_rooms = "tests/management_class/room_test.csv";
    const std::string test_csv_robots = "tests/management_class/robot_test.csv";

    const std::string require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 10 minutes\n\nRoom Name:\t2\nRoom Status:\tIP\nRoom Size:\tMedium\nEstimated Time to Clean: 20 minutes\n\nRoom Name:\t3\nRoom Status:\tDirty\nRoom Size:\tMedium\nEstimated Time to Clean: 20 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIP\nRoom Size:\tLarge\nEstimated Time to Clean: 30 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";

    const std::string require_robots = 
    "********** ROBOTS ************ \n \nRobot ID:\t0\nStatus:\tFree\nSize:\tSmall\nType:\tMop\n\nRobot ID:\t1\nStatus:\tBusy\nSize:\tSmall\nType:\tVaccuum\n\nRobot ID:\t2\nStatus:\tFree\nSize:\tMedium\nType:\tScrub\n\nRobot ID:\t3\nStatus:\tBusy\nSize:\tMedium\nType:\tMop\n\nRobot ID:\t4\nStatus:\tFree\nSize:\tLarge\nType:\tVaccuum\n\nRobot ID:\t5\nStatus:\tBusy\nSize:\tLarge\nType:\tScrub\n\nRobot ID:\t6\nStatus:\tFree\nSize:\tLarge\nType:\tMop\n\n";

    Management management(test_csv_rooms, test_csv_robots);
    CHECK(management.to_string_room_list() == require_rooms);
    CHECK(management.to_string_robot_list() == require_robots);
}

// #include "../../include/manage/Management.hpp"
// #include <vector>
// #include <string>
// #include <iostream>
// #include <fstream>
// #include <sstream>


// // void my_assert(bool condition, const std::string& message) {
// //     if (!condition) {
// //         std::cerr << "Test failed: " << message << std::endl;
// //     } else {
// //         std::cout << "Test passed." << std::endl;
// //     }
// // }

// // Test for initialize_room_list_from_csv_file
// void test_initialize_system_from_csv() {
//     const std::string test_csv_rooms = "tests/management_class/room_test.csv";
//     const std::string test_csv_robots = "tests/management_class/robot_test.csv";
//     Management management(test_csv_rooms, test_csv_robots);
//     std::cout << management.to_string_room_list() << std::endl;
//     std::cout << management.to_string_robot_list() << std::endl;
// }


// int main() {
//     test_initialize_system_from_csv();
//     return 0;
// }
