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
        // Inititalizes an instance of the robot with default attributes
        Robot();


        // Robot constructor that takes the parameters ID, status, size, type, and room id.
        // Constructs an instance of a robot with the given parameters
        // Throws error if the given type or size is not valid  
        Robot(string ID, string status_, string size_, string type_, string room_id_);


        // Copy constructor
        // Initializes an instance of a robot given a reference of another robot
        Robot(const Robot& other);

        // Destructor
        ~Robot();


        // Takes in a string type and sets the robot type to given type
        // Throws Invalid argument error if given type is invalid
        void set_type(string& bot_type_);

        // Takes in a string size and sets the robot size to given size
        // Throws Invalid argument error if given size is invalid
        void set_size(string& bot_size_);

        // Given a string of room, assigns the robot to the room, setting the
        //  status as busy
        void set_room(string room);
        inline string get_room() const {return this->room_id_;}


        // NOTE: Would recommend avoiding any change to this as it is used by Robot Constructor
        // Takes in a string status and sets the robot status to given status
        // Throws Invalid argument error if given status is invalid
        void set_status(string status);
    
        // Sends the robot home and frees robot assignment from room
        void go_home();


        // Returns a string of the robot type.
        // Returns type "Unknown" if the type is not existent
        string to_string_type();

        // Returns a string of the status of the robot
        // Returns status "Unknown" if the status is not existent
        string to_string_status();

        // Returns a string of the size of the robot
        // If robot size is not existent, returns "Unknown"
        string to_string_size();

        // Returns a string of Robot ID, status, room ID, size, and type
        string to_string();

        // Returns robot size
        inline Robot_Size get_size() const {return this->size_;}

        // Given a reference to another robot, returns a boolean comparing 
        // if the robot id is less than the id of the given robot
        bool operator<(const Robot& other) const;
};

#endif