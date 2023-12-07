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
        /**
         * Default Constructor
         * @param  None
         * @return  None
        */
        Robot();

        /**
         * Parameterized Constructor
         * @param  String name, status, size, time
         * @return  None
        */
        Robot(std::string ID, std::string status_, std::string size_, std::string type_, std::string room_id_);

        /**
         * Copy Constructor
         * @param  Const reference to another Robot object
         * @return  None
        */
        Robot(const Robot& other);

        /**
         * Robot Destructor
         * @param  None
         * @return  None
        */
        ~Robot();
        
        /**
         * Modifier - set Robot_Status
         * @param  String desired status
         * @return  void
         * @throws  std::invalid_argument if no match is found
         * @note    Would recommend avoiding any change to this as it is used by Robot Constructor
        */
        void set_status(std::string status);
        
        /**
         * Modifier - set Robot_Size
         * @param  String reference size
         * @return  void
         * @throws  std::invalid_argument if no match is found
        */
        void set_size(std::string& bot_size_);

        /**
         * Modifier - set Type of robot
         * @param  String reference type
         * @return  void
         * @throws  std::invalid_argument if no match is found
        */
        void set_type(std::string& bot_type_);

        /**
         * Modifier - set assigned room to clean
         * @param  String assigned room
         * @return  void
        */
        void set_room(std::string givenRoom);

        /**
         * Modifier - resets room assignment and Robot_Status
         * @param  None
         * @return  None
        */
        void go_home();

        /**
         * Helper - converts enum Type to string
         * @param  None
         * @return  String Type
        */
        std::string to_string_type();

        /**
         * Helper - converts enum Robot_Status to string
         * @param  None
         * @return  String Robot_Status
        */
        std::string to_string_status();

        /**
         * Helper - converts enum Robot_Size to string
         * @param  None
         * @return  String Robot_Size
        */
        std::string to_string_size();

        /**
         * Format desired to_string() output of Robot object
         * @param  None
         * @return  String providing Robot details
        */
        std::string to_string();

        /**
         * Accessor - get assigned room
         * @param  None
         * @return  String: room_id_
        */
        inline std::string get_room() const {return this->room_id_;}

        /**
         * Accessor - get Robot_Size
         * @param  None
         * @return  enum Robot_Size
        */
        inline Robot_Size get_size() const {return this->size_;}

        /**
         * Override comparison boolean
         * @param  Robot reference
         * @return  boolean
        */
        bool operator<(const Robot& other) const;
};

#endif