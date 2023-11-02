#ifndef LIBROOM_ROOM_HPP
#define LIBROOM_ROOM_HPP

#include <string>

enum class Status   {tbd, dirty, in_progress, clean};
enum class Size     {tbd, small, medium, large};

class Room {
    public:
        std::string room_name;

    private:
        int     estimated_time;
        Status  room_status;
        Size    room_size;

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
        * PURPOSE: Update the status of a room object
        * PARAMS:  enum Status updated_status - the desired status change
        * RETURN:  None
        * NOTE:    Expected to be used by either robot or management class
        */
        void update_room_status(Status updated_status);

        /**
        * PURPOSE: Modifier methods for convenience
        * PARAMS:  String - passed values to be converted
        * RETURN:  None
        * NOTE:    Assumes values will be passed as strings to be converted to proper types.
        */
        void set_room_name(std::string name);
        void set_room_size(std::string set_to_size);
        void set_room_time(std::string time);

        inline Status get_room_status() const {return this->room_status;}
        inline Size get_room_size() const {return this->room_size;}
        inline int get_estimated_clean_time() const {return this->estimated_time;}

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
        std::string get_room_data();
};

#endif
