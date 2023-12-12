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
#include <random>

class Management {
private:
    std::map<std::string, Robot> robot_list_;
    std::map<std::string, Room> room_list_;
    std::string csv_path_room_;
    std::string csv_path_robot_;
    std::map<Robot, Room> assignment_map;

    void initialize_robot_list_from_csv_file(const std::string& csv_path);
    void initialize_room_list_from_csv_file(const std::string& csv_path);
public:
    /**
     * Default Constructor
     * @param  None
     * @return  None
    */
    Management();

    /**
     * Parameterized Constructor
     * @param  String const references: csv_path_robot, csv_path_room
     * @return  None
    */
    Management(const std::string& csv_path_robot, const std::string& csv_path_room);

    /**
     * Modifier - add new robot objects to std::map robot_list_
     * @param   String robot id, availability status, size, type, room assignment
     * @return  void
    */
    void add_new_robot(std::string& ID,  std::string& online_status, std::string& size, std::string& clean_type, std::string& room_id);
    
    /**
     * Modifier - add new room objects to std::map room_list_
     * @param   String room id, cleanliness status, size, estimated time to clean
     * @return  void
    */
    void add_new_room(std::string& ID, std::string& clean_status, std::string& size, std::string& time_till_clean);
    
    /**
     * Accessor - prints the Room objects in room_list_
     * @param   None
     * @return  String
    */
    std::string to_string_room_list();

    /**
     * Accessor - prints the Robot objects in robot_list_
     * @param   None
     * @return  String
    */
    std::string to_string_robot_list();

    void maintenance(std::string bot);

    /**
     * Helper - perform cleaning and sends robot home, changes room status and time to clean
     * @param   Robot reference
     * @param   Room reference
     * @param   int time
     * @return  void
    */
    void cleaning(Robot&, Room&, int);

    /**
     * Assigns a specified robot to a specified room and calculates time for cleaning
     * @param   String specified robot and room
     * @return  void
    */
    void cleaning_assignment(std::string bot, std::string rm);

    /**
     * Accessor - retrieves requested robot from robot_list_
     * @param   String id of robot
     * @return  Robot
    */
    inline Robot& get_bot(std::string id) { return this->robot_list_[id]; }

    /**
     * Accessor - retrieves requested room from room_list_
     * @param   String id of room
     * @return  Room
    */
    inline Room get_room(std::string id) { return this->room_list_[id]; }

    void charge(std::string bot);
};

#endif
