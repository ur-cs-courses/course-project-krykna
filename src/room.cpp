#include "../include/libroom/room.hpp"

// Default room constructor
// Initializes an instance of the room class with the default attributes
Room::Room() {
    room_name_ = "TBD";
    this->room_status_ = Status::emp;
    this->room_size_ = Size::emp2;
    this->estimated_time_ = 0;
}

// Room constructor that initializes an instance of the room class with the given
// name, status, size, and time
// Throws an error if the status or size are not valid
Room::Room(std::string name, std::string status, std::string size, std::string time)
    : room_name_(name)
{
    std::string stat_conv = to_lower(status);
    std::string size_conv = to_lower(size);

    if (stat_conv == "dirty") {
        this->room_status_ = Status::dirty;
    } else if (stat_conv == "in-progress" || stat_conv == "in progress" || stat_conv == "ip") {
        this->room_status_ = Status::in_progress;
    } else if (stat_conv == "clean") {
        this->room_status_ = Status::clean;
    } else {
        throw std::invalid_argument("Invalid argument: Received an invalid status");
    }

    if (size_conv == "small" || size_conv == "s") {
        this->room_size_ = Size::small;
    } else if (size_conv == "medium" || size_conv == "med" || size_conv == "m") {
        this->room_size_ = Size::medium;
    } else if (size_conv == "large" || size_conv == "lg" || size_conv == "l") {
        this->room_size_ = Size::large;
    } else {
        throw std::invalid_argument("Invalid argument: Received an invalid size");
    }

    this->estimated_time_ = std::stoi(time);

}

// Room constructor that creates an instance with the same attributes
// as the given room
Room::Room(const Room &other)
    : room_name_(other.room_name_),
      room_status_(other.room_status_),
      room_size_(other.room_size_),
      estimated_time_(other.estimated_time_)
{}

// Deconstructor
Room::~Room() {}

// Given a reference to a string, returns a the string but all lowercase
std::string Room::to_lower(std::string& string_to_convert) {
    std::string lowercase;
    for (char c : string_to_convert) {
        lowercase.push_back(std::tolower(c));
    }
    return lowercase;
}

// Returns a string of the status of the room
// Returns status "Unknown" if status not existent
std::string Room::status_to_string() {
    switch (this->room_status_) {
        case (Status::dirty):
            return "Room Status:\tDirty";
        case (Status::in_progress):
            return "Room Status:\tIn-progress";
        case (Status::clean):
            return "Room Status:\tClean";
    }

    return "Room Status:\tUnknown";
}

// Returns a string of the size of the room
// Returns size "Unknown" if the size is not existent
std::string Room::size_to_string() {
    switch (this->room_size_) {
        case (Size::small):
            return "Room Size:\tSmall";
        case (Size::medium):
            return "Room Size:\tMedium";
        case (Size::large):
            return "Room Size:\tLarge";
    }

    return "Room Size:\tUnknown";
}

// Returns a string of the estimated time to clean the room in minutes
std::string Room::time_to_string() {
    std::string est_time = "Estimated Time to Clean: " + std::to_string(this->estimated_time_) + " minutes";
    return est_time;
}

// Returns a string of the room name, status, size, and time
std::string Room::to_string() {
    std::string data = "Room Name:\t" + room_name_ + "\n" + status_to_string() + "\n" + size_to_string() + "\n" + time_to_string();
    return data;
}

// Given a status, sets the status of the room to the given status
void Room::set_status(Status status){
    this->room_status_ = status;
}

// Returns an integer of the estimated time to clean the room
int Room::get_time_to_clean(){
    return this->estimated_time_;
}

// Given an integer time, sets the estimated time to clean the room to the given time. 
void Room::set_time_to_clean(int time){
    this->estimated_time_ = time;
}