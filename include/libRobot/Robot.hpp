#ifndef LIBROBOT_ROBOT_HPP
#define LIBROBOT_ROBOT_HPP
#include <string>
#include <stdexcept>
using namespace std;

enum Robot_Status {Free, Busy};
enum Robot_Size {Small, Medium, Large};
enum Type {Mop, Vac, Scrub};

class Robot {
    private:
        string id_;
        Robot_Size size_;
        Robot_Status status_;
        Type type_;
        string room_id_;
    
    public:
        // Constructors
        Robot();

        Robot(string ID, string status_, string size_, string type_, string room_id_);

        Robot(const Robot& other);

        // Destructor
        ~Robot();

        // Room
        void set_room(string room);
        string get_room() const;


        // Status
        void set_status(string status);
    

        // Robot activities
        void go_home();

        string to_string_type();
        string to_string_status();
        string to_string_size();
        string to_string();

        Robot_Size get_size();

        bool operator<(const Robot& other) const;
};

#endif