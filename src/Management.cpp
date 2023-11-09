#include "../include/manage/Management.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Default constructor
Management::Management() : csv_path("") {
    // robot_list.clear();
    room_list.clear();
}

//Parameterized constructor
Management::Management(const std::string& csv_path) : csv_path(csv_path) {
    // initialize_robot_list_from_csv_file();
    initialize_room_list_from_csv_file();
}

// Private methods
// void Management::initialize_robot_list_from_csv_file() {
//     std::ifstream csvFile(csv_path);
    
//     if (!csvFile.is_open()) {
//         std::cerr << "Could not open the file: " << csv_path << std::endl;
//         return;
//     }

//     std::string line;
//     while (std::getline(csvFile, line)) {
//         std::istringstream iss(line);
        
//         std::string ID;
//         std::string size;
//         std::string clean_type;
//         std::string online_status;
        
//         iss >> ID >> online_status >> size >> clean_type;
        
//         add_new_robot(ID, size, clean_type, online_status);
//     }
    
//     csvFile.close();
// }


void Management::initialize_room_list_from_csv_file() {
    std::ifstream csvFile(csv_path);
    
    if (!csvFile.is_open()) {
        std::cerr << "Could not open the file: " << csv_path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(csvFile, line)) {
        std::istringstream iss(line);
        std::string name;
        std::string status;
        std::string size;
        std::string time;
        std::getline(iss, name, ',');
        std::getline(iss, status, ',');
        std::getline(iss, size, ',');
        std::getline(iss, time, ',');
        
        add_new_room(name, status, size, time);
    }

    
    csvFile.close();
}

// // Public methods
// void Management::add_new_robot(const std::string& ID, const std::string& size, const std::string& clean_type, const std::string& online_status) {
//     // Create a new Robot object with the given parameters
//     //Robot new_bot = new Robot(ID, online_status, size, clean_type);
//     std::string new_bot = ID + online_status + size + clean_type;
//     robot_list.push_back(new_bot);

// }

void Management::add_new_room(const std::string& ID,  const std::string& clean_status, const std::string& size, const std::string& time_till_clean) {
    // add a new room
    Room new_room = Room(ID, clean_status, size, time_till_clean);
    //std::string new_room = ID + size + clean_status + time_till_clean;
    room_list.push_back(new_room);
}

std::string Management::to_string_room_list() {
    std::string output;
    for (auto& room : room_list) {
        output += room.get_room_data() + "\n" + "\n";
    }
    return output;
}

// std::string Management::to_string_robot_list() {
//     std::string output;
//     for (const auto& robot : robot_list) {
//          output += robot.to_string() + "\n";
//     }
//     return output;
// }
