#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "../libroom/room.hpp"
#include "../libRobot/Robot.hpp"

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

    void initialize_robot_list_from_csv_file(const std::string& csv_path);
    void initialize_room_list_from_csv_file(const std::string& csv_path);
    void robot_list_pushback(std::string& ID, Robot& bot);
    void room_list_pushback(std::string& ID, Room& room);
public:
    // Default constructor
    Management();

    // Parameterized constructor
    Management(const std::string& csv_path_robot, const std::string& csv_path_room);

    // Public methods
    void add_new_robot(std::string& ID,  std::string& online_status, std::string& size, std::string& clean_type);
    void add_new_room(std::string& ID, std::string& clean_status, std::string& size, std::string& time_till_clean);
    std::string to_string_room_list();
    std::string to_string_robot_list();

    void cleaning_assignment(Robot& bot, Room& room);
    // std::map<Robot, Room> get_map();
};

#endif
