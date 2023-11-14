#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <manage/Management.hpp>
#include <libroom/room.hpp>
#include <libRobot/Robot.hpp>

/**
 * TESTING: Room Class
*/
TEST_CASE("Independent Class: Room Class") {
    Room room_passed_1("Conference", "dirty", "small", "5");
    Room room_passed_2("Conference", "Dirty", "Small", "5");
    std::string expected_room = 
    "Room Name:\tConference\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 5 minutes";
    CHECK(room_passed_1.to_string() == expected_room);
    CHECK(room_passed_2.to_string() == expected_room);
}

/**
 * TESTING: Robot Class
*/
TEST_CASE("Independent Class: Robot Class") {
    Robot robot_failed_1("Bubbles", "free", "large", "mop");
    Robot robot_passed_2("Bubbles", "Free", "Large", "Mop");
    std::string expected_robot = "Robot ID:\tBubbles\nStatus:\tFree\nSize:\tLarge\nType:\tMop";
    CHECK(robot_failed_1.to_string() == expected_robot);
    CHECK(robot_passed_2.to_string() == expected_robot);

}

/**
 * TESTING: Management Class
*/
TEST_CASE("Integration: Management + Room and Robot Classes") {
    // const std::string test_csv_rooms = "tests/management_class/room_test.csv";
    // const std::string test_csv_robots = "tests/management_class/robot_test.csv";
    const std::string test_csv_rooms = "tests/room_test.csv";
    const std::string test_csv_robots = "tests/robot_test.csv";

    const std::string require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 10 minutes\n\nRoom Name:\t2\nRoom Status:\tIP\nRoom Size:\tMedium\nEstimated Time to Clean: 20 minutes\n\nRoom Name:\t3\nRoom Status:\tDirty\nRoom Size:\tMedium\nEstimated Time to Clean: 20 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIP\nRoom Size:\tLarge\nEstimated Time to Clean: 30 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";

    const std::string require_robots = 
    "********** ROBOTS ************ \n \nRobot ID:\t0\nStatus:\tFree\nSize:\tSmall\nType:\tMop\n\nRobot ID:\t1\nStatus:\tBusy\nSize:\tSmall\nType:\tVaccuum\n\nRobot ID:\t2\nStatus:\tFree\nSize:\tMedium\nType:\tScrub\n\nRobot ID:\t3\nStatus:\tBusy\nSize:\tMedium\nType:\tMop\n\nRobot ID:\t4\nStatus:\tFree\nSize:\tLarge\nType:\tVaccuum\n\nRobot ID:\t5\nStatus:\tBusy\nSize:\tLarge\nType:\tScrub\n\nRobot ID:\t6\nStatus:\tFree\nSize:\tLarge\nType:\tMop\n\n";

    Management management(test_csv_rooms, test_csv_robots);
    CHECK(management.to_string_room_list() == require_rooms);
    CHECK(management.to_string_robot_list() == require_robots);
}

/**
 * TODO: Test Cases that require implementations
 * CLEANING_TIMER():- accessed by Manager Action Class: relies on Room and Robot classes
 * -> REQUIRES: [room |-> inline int get_estimated_clean_time() const {return this->estimated_time_;}] 
 *              [robot |-> inline Robot_Size get_robot_size() const {return this->size_;}]
*/
// TEST_CASE("Integration: Cleaning Time - Management, Room, Robot interaction") {}