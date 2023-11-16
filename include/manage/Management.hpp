#ifndef MANAGE_MANAGEMENT_HPP
#define MANAGE_MANAGEMENT_HPP

//#include "../libroom/room.hpp"
//#include "../libRobot/Robot.hpp"
#include "libroom/room.hpp"
#include "libRobot/Robot.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class Management {
private:
    std::vector<Robot> robot_list_;
    std::vector<Room> room_list_;
    std::string csv_path_room_;
    std::string csv_path_robot_;

    void initialize_robot_list_from_csv_file(const std::string& csv_path);
    void initialize_room_list_from_csv_file(const std::string& csv_path);

public:
    // Default constructor
    Management();

    // Parameterized constructor
    Management(const std::string& csv_path_robot, const std::string& csv_path_room);

    // Public methods
    void add_new_robot(const std::string& ID, const std::string& online_status, const std::string& size, const std::string& clean_type);
    void add_new_room(const std::string& ID, const std::string& clean_status, const std::string& size, const std::string& time_till_clean);
    std::string to_string_room_list();
    std::string to_string_robot_list();
};

#endif
