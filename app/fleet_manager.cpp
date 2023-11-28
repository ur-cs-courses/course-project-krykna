#include <iostream>
#include <string>
#include <sstream>
#include "../include/manage/Management.hpp" // Include Management Header File

using namespace std;

int main() {
    // Paths to the CSV files
    string csvPathRobot = "/home/ws4wd/course-project-krykna/course-project-krykna-2/tests/management_class/robot_test.csv";
    string csvPathRoom = "/home/ws4wd/course-project-krykna/course-project-krykna-2/tests/management_class/room_test.csv";

    // Create an instance of Management
    Management management(csvPathRoom, csvPathRobot);

    string input;
    
    // Introduction Message
    cout << "Welcome to your Robot Fleet Management System! " << endl; 
    
    // Main loop for program to run
    while (true) {
        // Just added the Perform Cleaning Operation
        cout << "Please type a command (1: Add Robot, 2: Add Room, 3: Get Overall Room Status, 4: Get Overall Robot Status, 5: Perform Cleaning Operation) or type 0 to Exit:";
        getline(cin, input); // Get the whole line as a command

        int command = stoi(input);

        // Check the user input and respond accordingly
        switch (command) {
            case 1: {
                string robotId, robotStatus, robotSize, robotType;
                cout << "Enter: [Robot ID] [robotStatus] [robotSize] [robotType] (in this order):" << endl;
                getline(cin, input);
                stringstream ss(input);
                ss >> robotId >> robotStatus >> robotSize >> robotType;

                management.add_new_robot(robotId, robotStatus, robotSize, robotType);
                cout << "New Robot has been added!" << endl;
                break;
            }
            case 2: {
                string roomName, roomStatus, roomSize, estimatedTime;
                cout << "Enter: [Room Name] [Room Status] [Room Size] [Estimated Time] (in this order):" << endl;
                getline(cin, input);
                stringstream ss(input);
                ss >> roomName >> roomStatus >> roomSize >> estimatedTime;

                management.add_new_room(roomName, roomStatus, roomSize, estimatedTime);
                cout << "New Room has been added!" << endl;
                break;
            }
            case 3: {
                cout << management.to_string_room_list() << endl;
                break;
            }
            case 4: {
                cout << management.to_string_robot_list() << endl;
                break;
            }
            //Cleaning Operation
            case 5: {
                string robotId, roomId;
                cout << "Enter Robot ID and Room ID for cleaning operation (separated by space):" << endl;
                cout << "Cleaning is done!" << endl;
            }
            case 0: {
                cout << "Exiting Robot Fleet Management System." << endl;
                return 0; // Exit the while loop and end the program
            }
            default: {
                cout << "Invalid command. Please try again." << endl;
                break;
            }
        }
    }

    return 0; // End of the program
}
