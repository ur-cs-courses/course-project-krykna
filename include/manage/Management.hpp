#ifndef MANAGE_MANAGEMENT_HPP
#define MANAGE_MANAGEMENT_HPP

#include "../libroom/room.hpp"
#include "../libRobot/Robot.hpp"
#include <stdexcept>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <thread>
#include <chrono>

class Management {
private:
    std::map<std::string, Robot> robot_list_;
    std::map<std::string, Room> room_list_;
    std::string csv_path_room_;
    std::string csv_path_robot_;
    std::map<Robot, Room> assignment_map;

    // Initializes the robots with the respective attributes in a given csv file path
    // Throws error if the given pathway is not valid
    void initialize_robot_list_from_csv_file(const std::string& csv_path);

    // Initializes the rooms with the respective attributes in a given csv file path
    // Throws error if the given pathway is not valid
    void initialize_room_list_from_csv_file(const std::string& csv_path);

public:
    // Default constructor
    // Constructs a management instance with empty rooms and robots
    Management();

    // Parameterized constructor
    // Constructs a management instance given a file path for robot and room csv
    Management(const std::string& csv_path_robot, const std::string& csv_path_room);

    // Public methods

    // Adds a new robot with the given id, status, size, type, and room id
    void add_new_robot(std::string& ID,  std::string& online_status, std::string& size, std::string& clean_type, std::string& room_id);
    
    // Adds a new room with the given id, status, size, and time
    void add_new_room(std::string& ID, std::string& clean_status, std::string& size, std::string& time_till_clean);
    
    // Returns a string of all the rooms and their attributes
    std::string to_string_room_list();
    
    // Returns a string of all the robots and their attributes
    std::string to_string_robot_list();

    // Sends the given robot to the given room for the given amount of time.
    //  Simulates the cleaning of the robot and sets the status of the room to clean
    //  and sends the robot back home afterwards. 
    void cleaning(Robot&, Room&, int);


    // Sends the given robot to the given room for the given amount of time.
    //  Simulates the cleaning of the robot and sets the status of the room to clean
    //  and sends the robot back home afterwards. 
    void cleaning_assignment(std::string bot, std::string rm);
};

#endif
