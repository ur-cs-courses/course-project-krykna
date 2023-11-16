#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "libroom/room.hpp"
#include <catch.hpp>

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


    SECTION("Concentration: Throw Error") {
        REQUIRE_THROWS_WITH(
            Room("Conference", "sdkfjslfdkajlfkwjf", "small", "5"),
            Catch::Contains("Invalid argument: Received an invalid status")
        );
        REQUIRE_THROWS_WITH(
            Room("Conference", "dirty", "sldfkjslefkejweflkj", "5"),
            Catch::Contains("Invalid argument: Received an invalid size")
        );
    } 
}