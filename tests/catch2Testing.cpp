#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <manage/Management.hpp>
#include <libroom/room.hpp>
#include <libRobot/Robot.hpp>

TEST_CASE("Independent Class: Room Class") {
    Room myroom("Conference", "dirty", "small", "5");
    std::string expected_room = 
    "Room Name:\tConference\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 5 minutes";
    CHECK(myroom.to_string() == expected_room);
}

TEST_CASE("Independent Class: Robot Class") {
    Robot myrobot("Bubbles", "free", "large", "mop");
    std::string expected_robot = "Robot ID:\tBubbles\nStatus:\tFree\nSize:\tLarge\nType:\tMop";
    CHECK(myrobot.to_string() == expected_robot);
}

TEST_CASE("Integration: Management + Room and Robot Classes") {
    const std::string test_csv_rooms = "tests/management_class/room_test.csv";
    const std::string test_csv_robots = "tests/management_class/robot_test.csv";

    const std::string require_rooms =
    "********** ROOMS ************ \n \n
    Room Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\n
    Room Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 10 minutes\n\n
    Room Name:\t2\nRoom Status:\tIP\nRoom Size:\tMedium\nEstimated Time to Clean: 20 minutes\n\n
    Room Name:\t3\nRoom Status:\tDirty\nRoom Size:\tMedium\nEstimated Time to Clean: 20 minutes\n\n
    Room Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n
    Room Name:\t5\nRoom Status:\tIP\nRoom Size:\tLarge\nEstimated Time to Clean: 30 minutes\n\n
    Room Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";

    const std::string require_robots = 
    "********** ROBOTS ************ \n \n
    Robot ID:\t0\nStatus:\tFree\nSize:\tSmall\nType:\tMop\n\n
    Robot ID:\t1\nStatus:\tBusy\nSize:\tSmall\nType:\tVaccuum\n\n
    Robot ID:\t2\nStatus:\tFree\nSize:\tMedium\nType:\tScrub\n\n
    Robot ID:\t3\nStatus:\tBusy\nSize:\tMedium\nType:\tMop\n\n
    Robot ID:\t4\nStatus:\tFree\nSize:\tLarge\nType:\tVaccuum\n\n
    Robot ID:\t5\nStatus:\tBusy\nSize:\tLarge\nType:\tScrub\n\n
    Robot ID:\t6\nStatus:\tFree\nSize:\tLarge\nType:\tMop\n\n";

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