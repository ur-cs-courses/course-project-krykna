#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "libroom/room.hpp"
#include <catch.hpp>

/**
 * TESTING: Room Class
*/
TEST_CASE("Independent Class: Room") {
    SECTION("Concentation: Room Default Constructor") {
        Room myroom;
        REQUIRE(myroom.to_string_status() == "Room Status:\tUnknown");
        REQUIRE(myroom.to_string_size() == "Room Size:\tUnknown");
        REQUIRE(myroom.get_time_to_clean() == 0);
    }

    SECTION("Concentration: Room Constructor") {
        Room myroom("1", "Dirty", "Small", "12");
        REQUIRE(myroom.to_string_status() == "Room Status:\tDirty");
        REQUIRE(myroom.to_string_size() == "Room Size:\tSmall");
        REQUIRE(myroom.get_time_to_clean() == 12);
    }

    SECTION("Concentration: Room Constructor Edge Case") {
        Room myroom("1", "dirty", "small", "12");
        REQUIRE(myroom.to_string_status() == "Room Status:\tDirty");
        REQUIRE(myroom.to_string_size() == "Room Size:\tSmall");
        REQUIRE(myroom.get_time_to_clean() == 12);
    }
    
    SECTION("Concentration: Room Status") {
        SECTION("Normal Cases") {
            Room dirty("NA", "Dirty", "Small", "0");
            Room inprogress("NA", "In-progress", "Small", "0");
            Room clean("NA", "Clean", "Small", "0");
            REQUIRE(dirty.to_string_status() == "Room Status:\tDirty");
            REQUIRE(inprogress.to_string_status() == "Room Status:\tIn-progress");
            REQUIRE(clean.to_string_status() == "Room Status:\tClean");
        }

        SECTION("Edge Cases") {
            Room edgecase_dirty("NA", "dirty", "Small", "0");
            Room edgecase_inprogress("NA", "in-progess", "Small", "0");
            Room edgecase_inprogress2("NA", "in progess", "Small", "0");
            Room edgecase_inprogress3("NA", "IP", "Small", "0");
            Room edgecase_clean("NA", "clean", "Small", "0");
            REQUIRE(edgecase_dirty.to_string_status() == "Room Status:\tDirty");
            REQUIRE(edgecase_inprogress.to_string_status() == "Room Status:\tIn-progress");
            REQUIRE(edgecase_inprogress2.to_string_status() == "Room Status:\tIn-progress");
            REQUIRE(edgecase_inprogress3.to_string_status() == "Room Status:\tIn-progress");
            REQUIRE(edgecase_clean.to_string_status() == "Room Status:\tClean");
        }
    }

    SECTION("Concentration: Room") { 
        SECTION("Normal Cases") {
            Room small("NA", "Dirty", "Small", "0");
            Room med("NA", "Dirty", "Medium", "0");
            Room large("NA", "Dirty", "Large", "0");
            REQUIRE(small.to_string_size() == "Room Size:\tSmall");
            REQUIRE(med.to_string_size() == "Room Size:\tMedium");
            REQUIRE(large.to_string_size() == "Room Size:\tLarge");
        }

        SECTION("Edge Cases") {
            Room edgecase_small("NA", "Dirty", "small", "0");
            Room edgecase_med("NA", "Dirty", "medium", "0");
            Room edgecase_large("NA", "Dirty", "large", "0");
            REQUIRE(edgecase_small.to_string_size() == "Room Size:\tSmall");
            REQUIRE(edgecase_med.to_string_size() == "Room Size:\tMedium");
            REQUIRE(edgecase_large.to_string_size() == "Room Size:\tLarge");
        }
    }

    SECTION("Concentration: Throw Error") {
        REQUIRE_THROWS_WITH(
            Room("0", "d", "small", "5"),
            Catch::Contains("Invalid argument: Received an invalid status")
        );
        REQUIRE_THROWS_WITH(
            Room("0", "dirty", "x-large", "5"),
            Catch::Contains("Invalid argument: Received an invalid size")
        );
    } 
}