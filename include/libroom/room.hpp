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
         * Default Constructor
         * @param  None
         * @return None
        */
        Room();

        /**
         * Parameterized Constructor
         * @param  String name, status, size, time
         * @return  None
        */
        Room(std::string name, std::string status, std::string size, std::string time);
        
        /**
         * Copy Room Constructor
         * @param  Reference to Room object
         * @return  None
        */
        Room(const Room &other);

        /**
         * Room Deconstructor
         * @param  None
         * @return  None
        */
        ~Room();

        /**
         * Modifier - converts lowercase string to status and sets room status
         * @param  String status passed from constructor
         * @return  None
         * @throws  std::invalid_argument if no match is found
        */
        void convert_to_status(std::string& status_string_);

        /**
         * Modifier - converts lowercase string to size and set room size
         * @param  String size passed from constructor
         * @return  None
         * @throws  std::invalid_argument if no match is found
        */
        void convert_to_size(std::string& size_string_);

        /**
         * Helper - converts string to lowercase
         * @param  String passed from constructor
         * @return  String
        */
        std::string to_lower(std::string& string_to_convert);

        /**
         * Modifier - set Room_Status
         * @param  enum Room_Status
         * @return  None
        */
        inline void set_status(Room_Status status) {this->room_status_ = status;}

        /**
         * Modifier - set estimated_time_
         * @param  int: time
         * @return  None
        */
        inline void set_time_to_clean(int time) {this->estimated_time_ = time;}

        /**
         * Accessor - get estimated_time_
         * @param  None
         * @return  int: estimated_time_
        */
        inline int get_time_to_clean() const {return this->estimated_time_;}
        inline std::string get_id() const {return this->room_name_;}
        inline Room_Status get_status() const {return this->room_status_;}

        /**
         * Helper - Converts enum class Status value to string
         * @param  None
         * @return  String conversion of the enum status
        */
        std::string to_string_status();

        std::string to_string_csv();

        /**
         * Helper - Converts enum class Size value to string
         * @param  None
         * @return  String conversion of the enum size
        */
        std::string to_string_size();

        /**
         * Helper - Converts estimated time to string
         * @param  None
         * @return  String conversion of the int estimated_time
         *          "Estimated Time to Clean: [estimated_time] minutes"
         * @note    Assumes unit of time is minutes
        */
        std::string to_string_time();

        /**
         * Acts as a to_string() method to return the room data
         * @param  None
         * @return  String providing the information of the room
         * @note Calls to_string_status(), to_string_size(), to_string_time()
        */
        std::string to_string();

};

#endif
