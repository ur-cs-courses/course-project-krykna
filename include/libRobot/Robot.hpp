#ifndef LIBROBOT_ROBOT_HPP
#define LIBROBOT_ROBOT_HPP
#include <string>
using namespace std;

enum Robot_Status {Free, Busy};
enum Robot_Size {Small, Medium, Large};
enum Type {Mop, Vac, Scrub};

class Robot {
    private:
        string id;
        Robot_Size size;
        string room;
        Robot_Status status;
        Type type;
    
    public:
        // Constructors
        //Robot();
        Robot(string ID, string status, string size, string type);

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
};

#endif