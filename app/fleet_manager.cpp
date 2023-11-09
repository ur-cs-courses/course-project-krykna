#include <iostream> // Include the library that contains the standard input/output stream objects
#include <string> // Including the string library
#include <sstream>


using namespace std; // Use the standard namespace

int main() {
    string input;
    string size, type;
    //Introduction Message
    cout << "Welcome to your Robot Fleet Management System! "; 
    
    // Main loop for program to run
    while (true) {
        cout << "Please type a command (Add Robot, Add Room, Get Overall Room Status, Get Overall Robot Status) or type Exit to quit:";
        getline(cin, input); // Get the whole line as a command

        // Check the user input and respond accordingly
        if (input == "Add Robot") {
            cout << "What is the size and type?" << endl;
            getline(cin, input); // Expecting user to input size and type in "size type" format
            stringstream ss(input);
            ss >> size >> type; // Split the input into size and type
            cout << "New Robot: " << size << " and " << type << " has been added to Robot CSV file!" << endl;
        } else if (input == "Add Room") {
            cout << "Size of Room?" << endl;
            cin >> size;
            cin.ignore(); // To consume the newline character and avoid it being read in the next getline call
            cout << "New Room Size " << size << " is initialized to dirty and is now added to the Room CSV File" << endl;
        } else if (input == "Get Overall Room Status") {
            cout << "The backend will grab the to_string() from the Room class and use file line reading functionality to print out the updated contents of the entire Room CSV file " << endl;
        } else if (input == "Get Overall Robot Status") {
            cout << "The backend will grab the to_string() from the Robot class and use file line reading functionality to print out the updated contents of the entire Robot CSV file " << endl;
        } else if (input == "Exit") {
            break; // Exit the while loop and end the program
        } else {
            cout << "Invalid command. Please try again." << endl;
        }

    }

    cout << "Exiting Robot Fleet Management System." << endl;
    return 0; // End of the program

    return 0; // End of the program
}