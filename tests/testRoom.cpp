#define CATCH_CONFIG_MAIN
#include "libroom/room.hpp"
#include <iostream>

int main() {
    Room* myroom = new Room("Conference", "dirty", "small", "5");
    TEST_CASE("Basic data fetching methods test") {
        const std::string expected_string = "Room Name: Conference\nRoom Status: Dirty\nRoom Size: Small\nEstimated Time to Clean: 5 minutes";
        CHECK(myroom->get_estimated_clean_time() == 5);
        CHECK(myroom->get_room_size() == Size::small);
        CHECK(myroom->get_room_status() == Status::dirty);
        CHECK(myroom->get_room_data() == expected_string);
    }
}
