#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/manage/Management.hpp"

/**
 * For Constructing Expected Results for Room and Robot to_string_list()
 * Room Display String Format:
    Room Name:\t
    \nRoom Status:\t
    \nRoom Size:\t
    \nEstimated Time to Clean: 0 minutes\n\n

    0,Clean,Small,0
    1,Dirty,Small,2
    2,IP,Medium,4
    3,IP,Medium,4
    4,Clean,Large,0
    5,IP,Large,6
    6,Clean,Large,0

    Room Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\n
    Room Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 2 minutes\n\n
    Room Name:\t2\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\n
    Room Name:\t3\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\n
    Room Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n
    Room Name:\t5\nRoom Status:\tIn-progress\nRoom Size:\tLarge\nEstimated Time to Clean: 6 minutes\n\n
    Room Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n
---------------------------------
 * Robot Display String Format:
    ID:\t
    \nStatus:\t
    \nRoom:\t
    \nSize\t
    \nType:\t
    \n\n

    0,Free,Small,Mop,NA
    1,Busy,Small,Vac,2
    2,Free,Medium,Scrub,NA
    3,Busy,Medium,Mop,5
    4,Free,Large,Vac,NA
    5,Busy,Large,Scrub,3
    6,Free,Large,Mop,NA

    ID:\t0\nStatus:\tFree\nRoom:\tNA\nSize:\tSmall\nType:\tMop\n\n
    ID:\t1\nStatus:\tBusy\nRoom:\t2\nSize:\tSmall\nType:\tVaccuum\n\n
    ID:\t2\nStatus:\tFree\nRoom:\tNA\nSize:\tMedium\nType:\tScrub\n\n
    ID:\t3\nStatus:\tBusy\nRoom:\t5\nSize:\tMedium\nType:\tMop\n\n
    ID:\t4\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tVaccuum\n\n
    ID:\t5\nStatus:\tBusy\nRoom:\t3\nSize:\tLarge\nType:\tScrub\n\n
    ID:\t6\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tMop\n\n
*/

TEST_CASE("Testing Add New Robot and Room Functions") {
    // Expansion required
    SECTION("Add New Room") {
        Management room_managing;
        std::string room_id = "1";
        std::string room_status = "Dirty";
        std::string room_size = "Medium";
        std::string time = "6";
        room_managing.add_new_room(room_id, room_status, room_size, time);
    }

    SECTION("Add New Robot") {
        Management robot_managing;
        std::string bot_id = "0";
        std::string bot_status = "Free";
        std::string bot_size = "Small";
        std::string bot_type = "Mop";
        std::string bot_room = "NA";
        robot_managing.add_new_robot(bot_id, bot_status, bot_size, bot_type, bot_room);
    }
}

TEST_CASE("Test a Pair") {
    Management single_pair;
    std::string room_id = "1";
    std::string room_status = "Dirty";
    std::string room_size = "Medium";
    std::string time = "6";
    single_pair.add_new_room(room_id, room_status, room_size, time);

    std::string bot_id = "0";
    std::string bot_status = "Free";
    std::string bot_size = "Small";
    std::string bot_type = "Mop";
    std::string bot_room = "NA";
    single_pair.add_new_robot(bot_id, bot_status, bot_size, bot_type, bot_room);
    CHECK(single_pair.to_string_room_list() == "********** ROOMS ************ \n \nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tMedium\nEstimated Time to Clean: 6 minutes\n\n");
    CHECK(single_pair.to_string_robot_list() == "********** ROBOTS ************ \n \nID:\t0\nStatus:\tFree\nRoom:\tNA\nSize:\tSmall\nType:\tMop\n\n");

    single_pair.cleaning_assignment("0", "1");
    CHECK(single_pair.to_string_room_list() == "********** ROOMS ************ \n \nRoom Name:\t1\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 6 minutes\n\n");
    CHECK(single_pair.to_string_robot_list() == "********** ROBOTS ************ \n \nID:\t0\nStatus:\tBusy\nRoom:\t1\nSize:\tSmall\nType:\tMop\n\n");

    std::this_thread::sleep_for(std::chrono::seconds(20));
    CHECK(single_pair.to_string_room_list() == "********** ROOMS ************ \n \nRoom Name:\t1\nRoom Status:\tClean\nRoom Size:\tMedium\nEstimated Time to Clean: 0 minutes\n\n");
    CHECK(single_pair.to_string_robot_list() == "********** ROBOTS ************ \n \nID:\t0\nStatus:\tFree\nRoom:\tNA\nSize:\tSmall\nType:\tMop\n\n");
}

TEST_CASE("Testing Management Read CSVs") {
    const std::string test_csv_rooms = "input_test_files/room_test.csv";
    const std::string test_csv_robots = "input_test_files/robot_test.csv";
    Management management(test_csv_robots, test_csv_rooms);
    std::string require_rooms = "";
    std::string require_robots = "";

    SECTION("Test Compatibility with Room and Robot Classes") {
        require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 2 minutes\n\nRoom Name:\t2\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t3\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIn-progress\nRoom Size:\tLarge\nEstimated Time to Clean: 6 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";
        require_robots = 
    "********** ROBOTS ************ \n \nID:\t0\nStatus:\tFree\nRoom:\tNA\nSize:\tSmall\nType:\tMop\n\nID:\t1\nStatus:\tBusy\nRoom:\t2\nSize:\tSmall\nType:\tVaccuum\n\nID:\t2\nStatus:\tFree\nRoom:\tNA\nSize:\tMedium\nType:\tScrub\n\nID:\t3\nStatus:\tBusy\nRoom:\t5\nSize:\tMedium\nType:\tMop\n\nID:\t4\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tVaccuum\n\nID:\t5\nStatus:\tBusy\nRoom:\t3\nSize:\tLarge\nType:\tScrub\n\nID:\t6\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tMop\n\n";
        CHECK(management.to_string_room_list() == require_rooms);
        REQUIRE(management.to_string_robot_list() == require_robots);
    }

    SECTION("Test Timer") {
        std::this_thread::sleep_for(std::chrono::seconds(12));
        require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 2 minutes\n\nRoom Name:\t2\nRoom Status:\tClean\nRoom Size:\tMedium\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t3\nRoom Status:\tClean\nRoom Size:\tMedium\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";
        require_robots = 
    "********** ROBOTS ************ \n \nID:\t0\nStatus:\tFree\nRoom:\tNA\nSize:\tSmall\nType:\tMop\n\nID:\t1\nStatus:\tBusy\nRoom:\t2\nSize:\tSmall\nType:\tVaccuum\n\nID:\t2\nStatus:\tFree\nRoom:\tNA\nSize:\tMedium\nType:\tScrub\n\nID:\t3\nStatus:\tBusy\nRoom:\t5\nSize:\tMedium\nType:\tMop\n\nID:\t4\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tVaccuum\n\nID:\t5\nStatus:\tBusy\nRoom:\t3\nSize:\tLarge\nType:\tScrub\n\nID:\t6\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tMop\n\n";
        REQUIRE(management.to_string_room_list() == require_rooms);
        REQUIRE(management.to_string_robot_list() == require_robots);
    }

    SECTION("Test Cleaning") {
        management.cleaning_assignment("0", "1");
        require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tIn-progress\nRoom Size:\tSmall\nEstimated Time to Clean: 2 minutes\n\nRoom Name:\t2\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t3\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIn-progress\nRoom Size:\tLarge\nEstimated Time to Clean: 6 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";
        require_robots = 
    "********** ROBOTS ************ \n \nID:\t0\nStatus:\tBusy\nRoom:\t1\nSize:\tSmall\nType:\tMop\n\nID:\t1\nStatus:\tBusy\nRoom:\t2\nSize:\tSmall\nType:\tVaccuum\n\nID:\t2\nStatus:\tFree\nRoom:\tNA\nSize:\tMedium\nType:\tScrub\n\nID:\t3\nStatus:\tBusy\nRoom:\t5\nSize:\tMedium\nType:\tMop\n\nID:\t4\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tVaccuum\n\nID:\t5\nStatus:\tBusy\nRoom:\t3\nSize:\tLarge\nType:\tScrub\n\nID:\t6\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tMop\n\n";
        REQUIRE(management.to_string_room_list() == require_rooms);
        REQUIRE(management.to_string_robot_list() == require_robots);

        std::this_thread::sleep_for(std::chrono::seconds(6)); // TIMER INCREMENT
        require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t2\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t3\nRoom Status:\tClean\nRoom Size:\tMedium\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIn-progress\nRoom Size:\tLarge\nEstimated Time to Clean: 6 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";
        require_robots = 
    "********** ROBOTS ************ \n \nID:\t0\nStatus:\tFree\nRoom:\tNA\nSize:\tSmall\nType:\tMop\n\nID:\t1\nStatus:\tBusy\nRoom:\t2\nSize:\tSmall\nType:\tVaccuum\n\nID:\t2\nStatus:\tFree\nRoom:\tNA\nSize:\tMedium\nType:\tScrub\n\nID:\t3\nStatus:\tBusy\nRoom:\t5\nSize:\tMedium\nType:\tMop\n\nID:\t4\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tVaccuum\n\nID:\t5\nStatus:\tBusy\nRoom:\t3\nSize:\tLarge\nType:\tScrub\n\nID:\t6\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tMop\n\n";
        REQUIRE(management.to_string_room_list() == require_rooms);
        REQUIRE(management.to_string_robot_list() == require_robots);     
    }
}