#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <vector>
#include <string>

// Forward declarations for Robots, Rooms, and Cleaner. 
// You would typically include the appropriate header files.
class Robots;
class Rooms;
enum class Cleaner;

class Management {
private:
    std::vector<Robots> robot_list;
    std::vector<Rooms> room_list;
    std::string csv_path;

    void initialize_robot_list_from_csv_file();
    void initialize_room_list_from_csv_file();

public:
    // Default constructor
    Management();

    // Parameterized constructor
    Management(const std::string& csv_path);

    // Public methods
    void add_new_robot(int size, const std::string& clean_type, bool online_status, bool update_csv = true);
    void add_new_room(int size);
    std::string to_string_room_list();
    std::string to_string_robot_list();
};

#endif // MANAGEMENT_H
