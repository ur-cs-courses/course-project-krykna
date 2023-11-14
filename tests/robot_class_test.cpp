#include <libRobot/Robot.hpp>

#include "catch.hpp"
#include "libRobot/Robot.hpp"

TEST_CASE("Independent Class: Robot Class") {
    Robot robot_failed_1("Bubbles", "free", "large", "mop");
    Robot robot_passed_2("Bubbles", "Free", "Large", "Mop");
    std::string expected_robot = "Robot ID:\tBubbles\nStatus:\tFree\nSize:\tLarge\nType:\tMop";
    CHECK(robot_failed_1.to_string() == expected_robot);
    CHECK(robot_passed_2.to_string() == expected_robot);
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