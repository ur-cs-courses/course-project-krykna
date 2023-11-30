#ifndef LIBROOM_ROOM_HPP
#define LIBROOM_ROOM_HPP

#include <string>
#include <stdexcept>

enum Room_Status   {emp, dirty, in_progress, clean};
enum Room_Size     {emp2, small, medium, large};

class Room {
    private:
        std::string room_name_;
        int     estimated_time_;
        Room_Status  room_status_;
        Room_Size    room_size_;

    public:
        /**
        * PURPOSE: Default Constructor
        * PARAMS:  None
        * RETURN:  None
        */
        Room();

        /**
        * PURPOSE: Room Constructor
        * PARAMS:  String name, status, size, time
        * RETURN:  None
        */
        Room(std::string name, std::string status, std::string size, std::string time);
        
        /**
        * PURPOSE: Copy Room Constructor
        * PARAMS:  Reference to Room object
        * RETURN:  None
        */
        Room(const Room &other);

        /**
        * PURPOSE: Room Deconstructor
        * PARAMS:  None
        * RETURN:  None
        */
        ~Room();

        /**
        * PURPOSE: Modifier - converts lowercase string to status and sets room status
        * PARAMS:  String status
        * RETURN:  None
        */
        void convert_to_status(std::string& status_string_);

        /**
        * PURPOSE: Modifier - converts lowercase string to size and set room size
        * PARAMS:  String size
        * RETURN:  None
        */
        void convert_to_size(std::string& size_string_);

        /**
        * PURPOSE: Helper - converts string to lowercase
        * PARAMS:  None
        * RETURN:  lowercase string
        */
        std::string to_lower(std::string& string_to_convert);

        inline void set_status(Room_Status status) {this->room_status_ = status;}
        inline void set_time_to_clean(int time) {this->estimated_time_ = time;}
        inline int get_time_to_clean() const {return this->estimated_time_;}

        /**
        * PURPOSE: Helper - Converts enum class Status value to string
        * PARAMS:  None
        * RETURN:  String conversion of the enum status
        */
        std::string to_string_status();

        /**
        * PURPOSE: Helper - Converts enum class Size value to string
        * PARAMS:  None
        * RETURN:  String conversion of the enum size
        */
        std::string to_string_size();

        /**
        * PURPOSE: Helper - Converts estimated time to string
        * PARAMS:  None
        * RETURN:  String conversion of the int estimated_time
        *          "Estimated Time to Clean: [estimated_time] minutes"
        * NOTE:    Assumes unit of time is minutes
        */
        std::string to_string_time();

        /**
        * PURPOSE: Acts as a to_string() method to return the room data
        * PARAMS:  None
        * RETURN:  String providing the information of the room
        * HELPERS: status_to_string(), size_to_string(), time_to_string()
        */
        std::string to_string();

        Room_Status get_status();

};

#endif
