#include <iostream> // Include the library that contains the standard input/output stream objects
#include <string> // Including the string library
#include <sstream>
#include "../include/libRobot/Robot.hpp" // Include Robot Header File
#include "../include/libroom/room.hpp" //Include Room Header File



using namespace std; // Use the standard namespace

int main() {
    string input;
    
    //Introduction Message
    cout << "Welcome to your Robot Fleet Management System! "; 
    
    // Main loop for program to run
    while (true) {
        cout << "Please type a command (1: Add Robot, 2: Add Room, 3: Get Overall Room Status, 4: Get Overall Robot Status) or type 0 to Exit:";
        getline(cin, input); // Get the whole line as a command

        int command = stoi(input);

        // Check the user input and respond accordingly
        switch (command) {
            case 1: {
                string robotId, robotStatus, robotSize, robotType;
                cout << "Enter: [Robot ID] [robotStatus] [robotSize] [robotType] (in this order):" << endl;
                getline(cin, input); // Expecting user to input size and type in "size type" format
                stringstream ss(input);
                ss >> robotId >> robotStatus>> robotSize >> robotType; // Split the input into robot id, status, size, and 
                
                Robot newRobot(robotId, robotStatus, robotSize, robotType);
                cout << "Robot Details:\n" << newRobot.to_string() << endl;

                cout << "New Robot has been added to Robot CSV file! (NOT INTEGRATED YET)" << endl;
                break;

            } case 2: {
                string roomName, roomStatus, roomSize, estimatedTime;
                cout << "Enter: [Room Name] [Room Status] [Room Size] [Estimated Time] (in this order):" << endl;
                getline(cin, input); // Expecting user to input details in "name status size time" format
                stringstream ss(input);
                ss >> roomName >> roomStatus >> roomSize >> estimatedTime;

                Room newRoom(roomName, roomStatus, roomSize, estimatedTime);
                cout << "Room Details:\n" << newRoom.to_string() << endl;

                cout << "New Room has been added to Room CSV file! (NOT INTEGRATED YET)" << endl;
                break;

            } case 3: {
                cout << "The backend will grab the to_string() from the Room class and use file line reading functionality to print out the updated contents of the entire Room CSV file " << endl;
                break;
            } case 4: {
                cout << "The backend will grab the to_string() from the Robot class and use file line reading functionality to print out the updated contents of the entire Robot CSV file " << endl;
                break;
            } case 0: {
                cout << "Exiting Robot Fleet Management System." << endl;
                return 0; // Exit the while loop and end the program
            } default: {
                cout << "Invalid command. Please try again." << endl;
                break;
            }
        }
        
    }

    return 0; // End of the program
}