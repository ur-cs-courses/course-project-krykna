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

TEST_CASE("Testing Management") {
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

    SECTION("Test Timer CSV") {
        std::this_thread::sleep_for(std::chrono::seconds(12));
        require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 2 minutes\n\nRoom Name:\t2\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t3\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIn-progress\nRoom Size:\tLarge\nEstimated Time to Clean: 6 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";
        require_robots = 
    "********** ROBOTS ************ \n \nID:\t0\nStatus:\tFree\nRoom:\tNA\nSize:\tSmall\nType:\tMop\n\nID:\t1\nStatus:\tBusy\nRoom:\t2\nSize:\tSmall\nType:\tVaccuum\n\nID:\t2\nStatus:\tFree\nRoom:\tNA\nSize:\tMedium\nType:\tScrub\n\nID:\t3\nStatus:\tBusy\nRoom:\t5\nSize:\tMedium\nType:\tMop\n\nID:\t4\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tVaccuum\n\nID:\t5\nStatus:\tBusy\nRoom:\t3\nSize:\tLarge\nType:\tScrub\n\nID:\t6\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tMop\n\n";
        REQUIRE(management.to_string_room_list() == require_rooms);
        REQUIRE(management.to_string_robot_list() == require_robots);
    }

    SECTION("Test Cleaning") {
        management.cleaning_assignment("0", "1");
        require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 2 minutes\n\nRoom Name:\t2\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t3\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIn-progress\nRoom Size:\tLarge\nEstimated Time to Clean: 6 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";
        require_robots = 
    "********** ROBOTS ************ \n \nID:\t0\nStatus:\tFree\nRoom:\tNA\nSize:\tSmall\nType:\tMop\n\nID:\t1\nStatus:\tBusy\nRoom:\t2\nSize:\tSmall\nType:\tVaccuum\n\nID:\t2\nStatus:\tFree\nRoom:\tNA\nSize:\tMedium\nType:\tScrub\n\nID:\t3\nStatus:\tBusy\nRoom:\t5\nSize:\tMedium\nType:\tMop\n\nID:\t4\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tVaccuum\n\nID:\t5\nStatus:\tBusy\nRoom:\t3\nSize:\tLarge\nType:\tScrub\n\nID:\t6\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tMop\n\n";
        REQUIRE(management.to_string_room_list() == require_rooms);
        REQUIRE(management.to_string_robot_list() == require_robots);

        std::this_thread::sleep_for(std::chrono::seconds(6)); // TIMER INCREMENT
        require_rooms = 
    "********** ROOMS ************ \n \nRoom Name:\t0\nRoom Status:\tClean\nRoom Size:\tSmall\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t1\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 2 minutes\n\nRoom Name:\t2\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t3\nRoom Status:\tIn-progress\nRoom Size:\tMedium\nEstimated Time to Clean: 4 minutes\n\nRoom Name:\t4\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\nRoom Name:\t5\nRoom Status:\tIn-progress\nRoom Size:\tLarge\nEstimated Time to Clean: 6 minutes\n\nRoom Name:\t6\nRoom Status:\tClean\nRoom Size:\tLarge\nEstimated Time to Clean: 0 minutes\n\n";
        require_robots = 
    "********** ROBOTS ************ \n \nID:\t0\nStatus:\tFree\nRoom:\tNA\nSize:\tSmall\nType:\tMop\n\nID:\t1\nStatus:\tBusy\nRoom:\t2\nSize:\tSmall\nType:\tVaccuum\n\nID:\t2\nStatus:\tFree\nRoom:\tNA\nSize:\tMedium\nType:\tScrub\n\nID:\t3\nStatus:\tBusy\nRoom:\t5\nSize:\tMedium\nType:\tMop\n\nID:\t4\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tVaccuum\n\nID:\t5\nStatus:\tBusy\nRoom:\t3\nSize:\tLarge\nType:\tScrub\n\nID:\t6\nStatus:\tFree\nRoom:\tNA\nSize:\tLarge\nType:\tMop\n\n";
        REQUIRE(management.to_string_room_list() == require_rooms);
        REQUIRE(management.to_string_robot_list() == require_robots);     
    }

    SECTION("Test Status") {
        Management management2 = Management();
        std::string ID = "20";
        std::string online_status = "Free"; 
        std::string size = "Large"; 
        std::string clean_type = "Vac"; 
        std::string room_id = "NA";
        management2.add_new_robot(ID, online_status, size, clean_type, room_id);
        std::string ID2 = "21";
        std::string clean_status = "Dirty"; 
        std::string size2 = "Large"; 
        std::string time_to_clean = "5";       
        management2.add_new_room(ID2, clean_status, size2, time_to_clean);


        REQUIRE(management2.get_bot("20").get_status() == Robot_Status::Free);
        REQUIRE(management2.get_room("21").get_status() == Room_Status::dirty);
        management.cleaning_assignment("20", "21");
        REQUIRE(management2.get_bot("20").get_status() == Robot_Status::Busy);
        REQUIRE(management2.get_room("21").get_status() == Room_Status::in_progress);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        REQUIRE(management2.get_bot("20").get_status() == Robot_Status::Free);
        REQUIRE(management2.get_room("21").get_status() == Room_Status::clean);
    }
}
