#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <catch.hpp>
#include "libRobot/Robot.hpp"

TEST_CASE("Robot Class") {
    SECTION("Concentration: Robot Size") {
        // Robot robot_small_nocap("Bubbles", "free", "small", "mop");
        // Robot robot_med_nocap("Bubbles", "free", "medium", "mop");
        // Robot robot_large_nocap("Bubbles", "free", "large", "mop");
        Robot robot_small_cap("Bubbles", "Free", "Small", "Mop");
        Robot robot_med_cap("Bubbles", "Free", "Medium", "Mop");
        Robot robot_large_cap("Bubbles", "Free", "Large", "Mop");

        // CHECK(robot_small_nocap.to_string() == "Robot ID:\tBubbles\nStatus:\tFree\nSize:\tSmall\nType:\tMop");
        // CHECK(robot_med_nocap.to_string() == "Robot ID:\tBubbles\nStatus:\tFree\nSize:\tMedium\nType:\tMop");
        // CHECK(robot_large_nocap.to_string() == "Robot ID:\tBubbles\nStatus:\tFree\nSize:\tLarge\nType:\tMop");
        CHECK(robot_small_cap.to_string() == "Robot ID:\tBubbles\nStatus:\tFree\nSize:\tSmall\nType:\tMop");
        CHECK(robot_med_cap.to_string() == "Robot ID:\tBubbles\nStatus:\tFree\nSize:\tMedium\nType:\tMop");
        CHECK(robot_large_cap.to_string() == "Robot ID:\tBubbles\nStatus:\tFree\nSize:\tLarge\nType:\tMop");
    }

    SECTION("Concentration: Robot Types") {
        // Robot robot_mop_nocap("Bubbles", "free", "large", "mop");
        // Robot robot_vac_nocap("Kirbbuum", "free", "large", "vac");
        // Robot robot_scrub_nocap("Scrubby", "free", "large", "scrub");
        Robot robot_mop_cap("Bubbles", "Free", "Large", "Mop");
        Robot robot_vac_cap("Kirbbuum", "Free", "Large", "Vac");
        Robot robot_scrub_cap("Scrubby", "Free", "Large", "Scrub");

        // CHECK(robot_mop_nocap.to_string() == "Robot ID:\tBubbles\nStatus:\tFree\nSize:\tLarge\nType:\tMop");
        // CHECK(robot_vac_nocap.to_string() == "Robot ID:\tKirbbuum\nStatus:\tFree\nSize:\tLarge\nType:\tVaccuum");
        // CHECK(robot_scrub_nocap.to_string() == "Robot ID:\tScrubby\nStatus:\tFree\nSize:\tLarge\nType:\tScrub");
        CHECK(robot_mop_cap.to_string() == "Robot ID:\tBubbles\nStatus:\tFree\nSize:\tLarge\nType:\tMop");
        CHECK(robot_vac_cap.to_string() == "Robot ID:\tKirbbuum\nStatus:\tFree\nSize:\tLarge\nType:\tVaccuum");
        CHECK(robot_scrub_cap.to_string() == "Robot ID:\tScrubby\nStatus:\tFree\nSize:\tLarge\nType:\tScrub");
    }

    SECTION("Concentration: Throw Error") {
        REQUIRE_THROWS_WITH(
            Robot("Bubbles", "Free", "Large", "asldkfjslkfjselkfj"),
            Catch::Contains("Invalid argument: Received an invalid type")
        );
        REQUIRE_THROWS_WITH(
            Robot("Bubbles", "Free", "slkfjlsekfjslfkjwf", "mop"),
            Catch::Contains("Invalid argument: Received an invalid size")
        );
    } 

    Robot testRobot("SpongeBot", "Free", "Small", "Scrub");
    SECTION("Robot is successfully assigned to a room + Sent back home") {
        testRobot.set_room("Cruddy Crawfish");
        CHECK(testRobot.get_room() == "Cruddy Crawfish");
        testRobot.go_home();
        CHECK(testRobot.get_room() == "");
        CHECK(testRobot.to_string_status() == "Status:\tFree");
    }
}

// Comment
/**
void test_initialize_Robot() {
    Robot testRobot(0, "Free", "Small", "Mop");
    std::cout << testRobot.typeToString() << std::endl;
    std::cout << testRobot.statusToString() << std::endl;
    std::cout << testRobot.sizeToString() << std::endl;
    testRobot.setRoom("BOOOOOOOOOOOOOOOOOOOM");
    std::cout << testRobot.getRoom() << std::endl;
    std::cout << testRobot.statusToString() << std::endl;
    testRobot.goHome();
    std::cout << testRobot.getRoom() << std::endl;
    std::cout << testRobot.statusToString() << std::endl;
}

int main() {
    test_initialize_Robot();
    return 0;
}
*/