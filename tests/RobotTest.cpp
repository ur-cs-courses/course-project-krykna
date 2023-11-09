#define CATCH_CONFIG_MAIN
#include "../include/libRobot/Robot.hpp"
#include <iostream>

int main() {
    Robot testRobot(0, "Free", "Small", "Mop");
    TEST_CASE("Basic data fetching methods test") {
        CHECK(testRobot.typeToString() == "Mop");
        CHECK(testRobot.statusToString() == "Free");
        CHECK(testRobot.sizeToString() == "Small");
    }
}