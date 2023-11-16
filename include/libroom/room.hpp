#ifndef LIBROOM_ROOM_HPP
#define LIBROOM_ROOM_HPP

#include <string>

enum Status   {emp, dirty, in_progress, clean};
enum Size     {emp2, small, medium, large};

class Room {
    private:
        std::string room_name_;
        int     estimated_time_;
        Status  room_status_;
        Size    room_size_;

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
        * PURPOSE: Helper - converts string to lowercase
        * PARAMS:  None
        * RETURN:  lowercase string
        */
        std::string to_lower(std::string& string_to_convert);

        /**
        * PURPOSE: Helper - Converts enum class Status value to string
        * PARAMS:  None
        * RETURN:  String conversion of the enum status
        */
        std::string status_to_string();

        /**
        * PURPOSE: Helper - Converts enum class Size value to string
        * PARAMS:  None
        * RETURN:  String conversion of the enum size
        */
        std::string size_to_string();

        /**
        * PURPOSE: Helper - Converts estimated time to string
        * PARAMS:  None
        * RETURN:  String conversion of the int estimated_time
        *          "Estimated Time to Clean: [estimated_time] minutes"
        * NOTE:    Assumes unit of time is minutes
        */
        std::string time_to_string();

        /**
        * PURPOSE: Acts as a to_string() method to return the room data
        * PARAMS:  None
        * RETURN:  String providing the information of the room
        * HELPERS: status_to_string(), size_to_string(), time_to_string()
        */
        std::string to_string();

        void set_status(Status);

        int get_time_to_clean();
};

#endif
