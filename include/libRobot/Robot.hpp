#ifndef LIBROBOT_ROBOT_HPP
#define LIBROBOT_ROBOT_HPP
#include <string>
#include <stdexcept>

enum Robot_Status {Free, Busy};
enum Robot_Size {Small, Medium, Large};
enum Type {Mop, Vac, Scrub};

class Robot {
    private:
        std::string id_;
        Robot_Size size_;
        Robot_Status status_;
        Type type_;
        std::string room_id_;
    
    public:
        // Constructors
        Robot();

        Robot(std::string ID, std::string status_, std::string size_, std::string type_, std::string room_id_);

        Robot(const Robot& other);

        // Destructor
        ~Robot();

        void set_type(std::string& bot_type_);
        void set_size(std::string& bot_size_);

        // Room
        void set_room(std::string room);
        inline std::string get_room() const {return this->room_id_;}

        // Status
        // NOTE: Would recommend avoiding any change to this as it is used by Robot Constructor
        void set_status(std::string status);
    
        // Robot activities
        void go_home();

        std::string to_string_type();
        std::string to_string_status();
        std::string to_string_size();
        std::string to_string();

        inline Robot_Size get_size() const {return this->size_;}

        bool operator<(const Robot& other) const;
};

#endif