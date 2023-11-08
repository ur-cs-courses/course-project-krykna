#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "Robot.h"

#include <vector>
#include <string>

class Management {
private:
    std::vector<Robot> robot_list;
    std::vector<Room> room_list;
    std::string csv_path;

    void initialize_robot_list_from_csv_file();
    void initialize_room_list_from_csv_file();

public:
    // Default constructor
    Management();

    // Parameterized constructor
    Management(const std::string& csv_path);

    // Public methods
    void add_new_robot(const std::string& ID, const std::string& size, const std::string& clean_type, const std::string& online_status);
    void add_new_room(const std::string& ID, const std::string& size, const std::string& clean_status, const std::string& time_till_clean);
    std::string to_string_room_list();
    std::string to_string_robot_list();
};

#endif
