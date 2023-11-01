#include "management/Management.hpp"  // Include the corresponding header file
#include <iostream>
#include <fstream>

// Default constructor implementation
Management::Management() : csv_path("") {
    // Initialize robot_list and room_list to empty
    robot_list.clear();
    room_list.clear();
}

// Parameterized constructor implementation
Management::Management(const std::string& csv_path) : csv_path(csv_path) {
    initialize_robot_list_from_csv_file();
    initialize_room_list_from_csv_file();
}

// Private methods
void Management::initialize_robot_list_from_csv_file() {
    std::ifstream csvFile(csv_path);
    
    if (!csvFile.is_open()) {
        std::cerr << "Could not open the file: " << csv_path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(csvFile, line)) {
        std::istringstream iss(line);
        
        int size;
        std::string clean_type;
        bool online_status;
        
        iss >> size >> clean_type >> online_status;
        
        // Add a new robot with the parsed attributes
        add_new_robot(size, clean_type, online_status, false);
    }
    
    csvFile.close();
}


void Management::initialize_room_list_from_csv_file() {
    // Implement CSV reading logic to populate room_list
    // For example:
    // std::ifstream csvFile(csv_path);
    // ... read data and populate room_list
    continue
}


// Public methods

void Management::add_new_robot(int size, const std::string& clean_type, bool online_status, bool update_csv) {
    // Create a new Robot object with the given parameters
    Robots new_robot(size, clean_type, online_status);

    // Add the new Robot object to the robot_list
    robot_list.push_back(new_robot);

    if (update_csv) {
        // Open the CSV file in append mode
        std::ofstream csvFile(csv_path, std::ios_base::app);

        if (!csvFile.is_open()) {
            std::cerr << "Could not open the file: " << csv_path << std::endl;
            return;
        }

        // Write the new robot information to the CSV file
        csvFile << size << " " << clean_type << " " << online_status << std::endl;
        
        csvFile.close();
    }
}



void Management::add_new_room(int size) {
    // Implement logic to add a new room
    // For example:
    // room_list.push_back(Rooms(size));
    continue
}

std::string Management::to_string_room_list() {
    std::string output;
    // Implement logic to create a string representation of room_list
    // For example:
    // for (const auto& room : room_list) {
    //     output += room.to_string() + "\n";
    // }
    return output;
}

std::string Management::to_string_robot_list() {
    std::string output;
    // Implement logic to create a string representation of robot_list
    // For example:
    // for (const auto& robot : robot_list) {
    //     output += robot.to_string() + "\n";
    // }
    return output;
}
