#include "../include/manage/Management.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Default constructor
Management::Management() {
    this->csv_path_room_ = "";
    this->csv_path_robot_ = "";
    robot_list_.clear();
    room_list_.clear();
    assignment_map.clear();
}

//Parameterized constructor
Management::Management(const std::string& csv_path_room_, const std::string& csv_path_robot_){
    this->csv_path_room_ = csv_path_room_;
    this->csv_path_robot_ = csv_path_robot_;
    initialize_robot_list_from_csv_file(csv_path_robot_);
    initialize_room_list_from_csv_file(csv_path_room_);
    assignment_map.clear(); // for now, this will need to change
}

// Private methods
void Management::initialize_robot_list_from_csv_file(const std::string& csv_path) {
    std::ifstream csvFile(csv_path);
    
    if (!csvFile.is_open()) {
        std::cerr << "Could not open the file: " << csv_path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(csvFile, line)) {
        std::istringstream iss(line);
        std::string ID;
        std::string size;
        std::string clean_type;
        std::string online_status;
        std::getline(iss, ID, ',');
        std::getline(iss, online_status, ',');
        std::getline(iss, size, ',');
        std::getline(iss, clean_type, ',');
        
        add_new_robot(ID, online_status, size, clean_type);
    }
    
    csvFile.close();
}


void Management::initialize_room_list_from_csv_file(const std::string& csv_path) {
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

// Public methods
void Management::add_new_robot(const std::string& ID, const std::string& online_status, const std::string& size, const std::string& clean_type) {
    // Create a new Robot object with the given parameters
    Robot new_bot = Robot(ID, online_status, size, clean_type);
    robot_list_.push_back(new_bot);
}

void Management::add_new_room(const std::string& ID,  const std::string& clean_status, const std::string& size, const std::string& time_till_clean) {
    // add a new room
    Room new_room = Room(ID, clean_status, size, time_till_clean);
    room_list_.push_back(new_room);
}

std::string Management::to_string_room_list() {
    std::string output = "********** ROOMS ************ \n \n";
    for (auto& room : room_list_) {
        output += room.to_string() + "\n" + "\n";
    }
    return output;
}

std::string Management::to_string_robot_list() {
    std::string output = "********** ROBOTS ************ \n \n";
    for (auto& robot : robot_list_) {
         output += robot.to_string() + "\n" + "\n";
    }
    return output;
}

void Management::cleaning_assignment(Robot& robot, Room& room){
    assignment_map[robot] = room;
    int time = 0;

    if (robot.get_size() == Large) {
        time = room.get_time_to_clean();
    } else if (robot.get_size() == Medium) {
        time = room.get_time_to_clean() * 2;
    } else {
        time = room.get_time_to_clean() * 3;
    }

    room.set_status(in_progress);
    robot.set_status("Busy");
    std::thread([this, &robot, &room, time]() {
        std::this_thread::sleep_for(std::chrono::seconds(time)); // Simulate cleaning time
        room.set_status(clean);
        robot.set_status("Free");
    }).detach();

    assignment_map.erase(robot);
}

// std::map<Robot, Room> Management::get_map(){
//     return this->assignment_map;
// }

    // RoTimer(std::vector<Robot> robot_list, std::vector<Room> room_list){
    //     int assigned_room;
    //     for (int i = 0; i < robot_list.size(); i++){
    //         assigned_room = robot_list[i].get_room();

    //     }
    // }