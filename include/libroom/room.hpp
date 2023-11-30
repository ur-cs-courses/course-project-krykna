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
        
        // Default room constructor
        // Initializes an instance of the room class with the default attributes
        Room();

        // Room constructor that initializes an instance of the room class with the given
        // name, status, size, and time
        // Throws an error if the status or size are not valid
        Room(std::string name, std::string status, std::string size, std::string time);
        
        // Room constructor that creates an instance with the same attributes
        // as the given room
        Room(const Room &other);

        // Deconstructor
        ~Room();

        // Given a string of the status, converts the string
        // to the corresponding status enum
        void convert_to_status(std::string& status_string_);

        // Given a string of the size, converts the string
        // to the corresponding size enum
        void convert_to_size(std::string& size_string_);

        // Given a reference to a string, returns a the string but all lowercase
        std::string to_lower(std::string& string_to_convert);

        // Given a status, sets the status of the room to the given status
        inline void set_status(Room_Status status) {this->room_status_ = status;}
        
        // Returns an integer of the estimated time to clean the room
        inline void set_time_to_clean(int time) {this->estimated_time_ = time;}
        
        // Returns an integer of the estimated time to clean the room
        inline int get_time_to_clean() const {return this->estimated_time_;}

        // Returns a string of the status of the room
        // Returns status "Unknown" if status not existent
        std::string to_string_status();

        // Returns a string of the size of the room
        // Returns size "Unknown" if the size is not existent
        std::string to_string_size();

        // Returns a string of the estimated time to clean the room in minutes
        std::string to_string_time();

        // Returns a string of the room name, status, size, and time
        std::string to_string();

};

#endif
