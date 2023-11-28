#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/manage/Management.hpp"

TEST_CASE("Testing Compatibility of Management with Room and Robot Classes") {
    const std::string test_csv_rooms = "input_test_files/room_test.csv";
    const std::string test_csv_robots = "input_test_files/robot_test.csv";

    std::string require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 2 minutes\n\nRoom Name:\t2\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t3\nRoom Status:\tDirty\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIn-progress\nRoom Size:\tLarge\nEstimated Time to Clean: 6 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";
    std::string require_robots = 
    "********** ROBOTS ************ \n \nRobot ID:\t0\nStatus:\tFree\nSize:\tSmall\nType:\tMop\n\nRobot ID:\t1\nStatus:\tBusy\nSize:\tSmall\nType:\tVaccuum\n\nRobot ID:\t2\nStatus:\tFree\nSize:\tMedium\nType:\tScrub\n\nRobot ID:\t3\nStatus:\tBusy\nSize:\tMedium\nType:\tMop\n\nRobot ID:\t4\nStatus:\tFree\nSize:\tLarge\nType:\tVaccuum\n\nRobot ID:\t5\nStatus:\tBusy\nSize:\tLarge\nType:\tScrub\n\nRobot ID:\t6\nStatus:\tFree\nSize:\tLarge\nType:\tMop\n\n";

    Management management(test_csv_robots, test_csv_rooms);
    CHECK(management.to_string_room_list() == require_rooms);
    CHECK(management.to_string_robot_list() == require_robots);

    SECTION("Test Timer") {
        std::this_thread::sleep_for(std::chrono::seconds(12));
        require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 2 minutes\n\nRoom Name:\t2\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t3\nRoom Status:\tDirty\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIn-progress\nRoom Size:\tLarge\nEstimated Time to Clean: 6 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";
        require_robots = 
    "********** ROBOTS ************ \n \nRobot ID:\t0\nStatus:\tFree\nSize:\tSmall\nType:\tMop\n\nRobot ID:\t1\nStatus:\tBusy\nSize:\tSmall\nType:\tVaccuum\n\nRobot ID:\t2\nStatus:\tFree\nSize:\tMedium\nType:\tScrub\n\nRobot ID:\t3\nStatus:\tBusy\nSize:\tMedium\nType:\tMop\n\nRobot ID:\t4\nStatus:\tFree\nSize:\tLarge\nType:\tVaccuum\n\nRobot ID:\t5\nStatus:\tBusy\nSize:\tLarge\nType:\tScrub\n\nRobot ID:\t6\nStatus:\tFree\nSize:\tLarge\nType:\tMop\n\n";

        CHECK(management.to_string_room_list() == require_rooms);
        CHECK(management.to_string_robot_list() == require_robots);
    }

    SECTION("Test Cleaning") {
        management.cleaning_assignment("0", "1");
        require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 10 minutes\n\nRoom Name:\t2\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 20 minutes\n\nRoom Name:\t3\nRoom Status:\tDirty\nRoom Size:\tMedium\nEstimated Time to Clean: 20 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIn-progress\nRoom Size:\tLarge\nEstimated Time to Clean: 30 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";

        require_robots = 
    "********** ROBOTS ************ \n \nRobot ID:\t0\nStatus:\tFree\nSize:\tSmall\nType:\tMop\n\nRobot ID:\t1\nStatus:\tBusy\nSize:\tSmall\nType:\tVaccuum\n\nRobot ID:\t2\nStatus:\tFree\nSize:\tMedium\nType:\tScrub\n\nRobot ID:\t3\nStatus:\tBusy\nSize:\tMedium\nType:\tMop\n\nRobot ID:\t4\nStatus:\tFree\nSize:\tLarge\nType:\tVaccuum\n\nRobot ID:\t5\nStatus:\tBusy\nSize:\tLarge\nType:\tScrub\n\nRobot ID:\t6\nStatus:\tFree\nSize:\tLarge\nType:\tMop\n\n";
        CHECK(management.to_string_room_list() == require_rooms);
        CHECK(management.to_string_robot_list() == require_robots);

        std::this_thread::sleep_for(std::chrono::seconds(6)); // TIMER INCREMENT
        require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 10 minutes\n\nRoom Name:\t2\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 20 minutes\n\nRoom Name:\t3\nRoom Status:\tDirty\nRoom Size:\tMedium\nEstimated Time to Clean: 20 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIn-progress\nRoom Size:\tLarge\nEstimated Time to Clean: 30 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";

        require_robots = 
    "********** ROBOTS ************ \n \nRobot ID:\t0\nStatus:\tFree\nSize:\tSmall\nType:\tMop\n\nRobot ID:\t1\nStatus:\tBusy\nSize:\tSmall\nType:\tVaccuum\n\nRobot ID:\t2\nStatus:\tFree\nSize:\tMedium\nType:\tScrub\n\nRobot ID:\t3\nStatus:\tBusy\nSize:\tMedium\nType:\tMop\n\nRobot ID:\t4\nStatus:\tFree\nSize:\tLarge\nType:\tVaccuum\n\nRobot ID:\t5\nStatus:\tBusy\nSize:\tLarge\nType:\tScrub\n\nRobot ID:\t6\nStatus:\tFree\nSize:\tLarge\nType:\tMop\n\n";
        CHECK(management.to_string_room_list() == require_rooms);
        CHECK(management.to_string_robot_list() == require_robots);     
    }
}
