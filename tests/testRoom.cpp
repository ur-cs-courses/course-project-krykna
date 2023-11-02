#define CATCH_CONFIG_MAIN
#include "libroom/room.hpp"
#include <iostream>

int main() {
    Room myroom("Conference", "dirty", "small", "5");
    TEST_CASE("Basic data fetching methods test") {
        const std::string expected_string = "Room Name:\tConference\nRoom Status:\tDirty\nRoom Size:\tSmall\nEstimated Time to Clean: 5 minutes";
        CHECK(myroom.get_estimated_clean_time() == 5);
        CHECK(myroom.get_room_size() == Size::small);
        CHECK(myroom.get_room_status() == Status::dirty);
        CHECK(myroom.get_room_data() == expected_string);
    }

    Room empty;
    TEST_CASE("Testing empty room") {
        CHECK(empty.get_room_data() == "Room Name:\tTBD\nRoom Status:\tTBD\nRoom Size:\tTBD\nEstimated Time to Clean: 0 minutes");
    }
}
