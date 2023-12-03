#include <iostream>
#include <string>
#include <sstream>
#include "../include/manage/Management.hpp" // Include Management Header File

int main() {
    // Paths to the CSV files
    std::string csvPathRobot = "../../tests/robot_test.csv";
    std::string csvPathRoom = "../../tests/room_test.csv";

    // Create an instance of Management
    Management management(csvPathRobot, csvPathRoom);

    std::string input;
    
    // Introduction Message
    std::cout << "Welcome to your Robot Fleet Management System! " << std::endl; 
    
    // Main loop for program to run
    while (true) {
        // Just added the Perform Cleaning Operation
        std::cout << "=================== Menu ===================\n\033[1;36m1\033[0m\tView All Room Statuses\n\033[1;36m2\033[0m\tView Robot Status\n\033[1;36m3\033[0m\tPerform Cleaning Operation\n\033[1;36m4\033[0m\tSelect Robot to Charge\n\033[1;36m5\033[0m\tSelect Robot for Maintenance" << std::endl;
        std::cout << "To select an option, enter the \033[1;36mcorresponding number assignment\033[0m: ";
        // std::cout << "Please type a command (1: Get Overall Room Status, 2: Get Overall Robot Status, 3: Perform Cleaning Operation, 4: Send Robot Home) or type 0 to Exit:";
        std::getline(std::cin, input); // Get the whole line as a command

        int command = std::stoi(input);

        // Check the user input and respond accordingly
        switch (command) {
            // case 1: {
            //     string robotId, robotStatus, robotSize, robotType;
            //     std::cout << "Enter: [Robot ID] [robotStatus] [robotSize] [robotType] (in this order):" << std::endl;
            //     getline(cin, input);
            //     stringstream ss(input);
            //     ss >> robotId >> robotStatus >> robotSize >> robotType;

            //     management.add_new_robot(robotId, robotStatus, robotSize, robotType);
            //     std::cout << "New Robot has been added!" << endl;
            //     break;
            // }
            // case 2: {
            //     string roomName, roomStatus, roomSize, estimatedTime;
            //     std::cout << "Enter: [Room Name] [Room Status] [Room Size] [Estimated Time] (in this order):" << endl;
            //     getline(cin, input);
            //     stringstream ss(input);
            //     ss >> roomName >> roomStatus >> roomSize >> estimatedTime;

            //     management.add_new_room(roomName, roomStatus, roomSize, estimatedTime);
            //     std::cout << "New Room has been added!" << endl;
            //     break;
            // }
            case 1: {
                std::cout << management.to_string_room_list() << std::endl;
                break;
            }
            case 2: {
                std::cout << "Enter \033[1;32m1\033[0m for all robot statuses or \033[1;32m2\033[0m for a specific robot: ";
                std::getline(std::cin, input);
                if (input == "1") { std::cout << management.to_string_robot_list() << std::endl; }
                else if (input == "2") { 
                    std::cout << "Enter Robot's ID to View: ";
                    std::getline(std::cin, input);
                    // std::cout << management.to_string_robot_individual(input) << std::endl;
                    std::cout << "\033[1;31mImplementation needed to request specific robot status:\n\tmanagement.to_string_robot_individual(std::string& robot_id)\033[0m" << std::endl;
                }
                else { std::cout << "Invalid entry." << std::endl;}
                break;
            }
            //Cleaning Operation
            case 3: {
                std::string robotId, roomId;
                std::cout << "Enter Robot ID and Room ID for cleaning operation (separated by space): ";
                std::getline(std::cin, input);
                std::stringstream ss(input);
                ss >> robotId >> roomId;


                management.cleaning_assignment(robotId, roomId);
                std::cout << "Cleaning operation initiated for Robot ID: " << robotId << " in Room ID: " << roomId << std::endl;
                break;
            }
            case 4: { // Hypothetical implementation for sending a robot home
                std::cout << "Enter the ID of the robot you'd like to charge: ";
                std::getline(std::cin, input);
                /**
                 * TODO: management.robot_charge(input);
                */
                std::cout << "\033[1;31mImplementation needed to send robot to charge:\n\tmanagement.robot_charge(std::string& robot_id)\033[0m" << std::endl;
                break;
            }
            case 5: {
                std::cout << "\033[1;32mNOTICE: Robot in maintenance will be taken offline.\033[0m" << std::endl;
                std::cout << "Enter the ID of the robot you'd like to send for maintenance: ";
                std::getline(std::cin, input);
                /**
                 * TODO: management.robot_maintenance(input);
                */
                std::cout << "\033[1;31mImplementation needed to send robot to charge:\n\tmanagement.robot_maintenance(std::string& robot_id)\033[0m" << std::endl;
                break;
            }
            case 0: {
                std::cout << "Exiting Robot Fleet Management System." << std::endl;
                return 0; // Exit the while loop and end the program
            }
            default: {
                std::cout << "Invalid command. Please try again." << std::endl;
                break;
            }
        }
    }

    return 0; // End of the program
}
