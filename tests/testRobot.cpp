#include "../include/libRobot/Robot.hpp"
#include <iostream>


// Comment
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