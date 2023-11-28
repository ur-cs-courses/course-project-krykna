#include "../include/libRobot/Robot.hpp"
using namespace std;
#include <stdexcept>

// Default constructor
Robot::Robot() {
    // Initialize member variables with default values
    this->id_ = "ERROR: NON EXISTENT BOT";  // Default ID
    this->status_ = Robot_Status::Busy; 
    this->size_ = Robot_Size::Medium;
    this->type_ = Type::Vac;
    this->room_id_= ""; 
}


Robot::Robot(string ID, string status_, string size_, string type_, string room_id_) {
    this->id_ = ID;
    this->room_id_ = room_id_;
    if (status_ == "Free") {
        this->status_ = Robot_Status::Free;
    } else if (status_ == "Busy") {
        this->status_ = Robot_Status::Busy;
    }

    if (type_ == "Mop" || type_ == "mop") {
        this->type_ = Type::Mop;
    } else if (type_ == "Vac" || type_ == "Vaccuum" || type_ == "vaccuum") {
        this->type_ = Type::Vac;
    } else if (type_== "Scrub" || type_ == "scrub") {
        this->type_ = Type::Scrub;
    } else {
        throw std::invalid_argument("Invalid argument: Received an invalid type");
    }
    // } else if (type_ != "Mop" && type_ != "mop" && type_ != "Vac" && type_ != "Vaccuum" && 
    //         type_ != "vaccuum" && type_ != "Scrub" && type_ != "scrub") {
    //             throw std::invalid_argument("Invalid argument: Received an invalid type");
    // }
    
    if (size_ == "Small" || size_ == "small") {
        this->size_ = Robot_Size::Small;
    } else if (size_ == "Medium" || size_== "medium") {
        this->size_ = Robot_Size::Medium;
    } else if (size_== "Large" || size_== "large") {
        this->size_ = Robot_Size::Large;
    } else {
        throw std::invalid_argument("Invalid argument: Received an invalid size");
    }
    // } else if (size_ != "Small" && size_ != "small" && size_ != "Medium" && size_ != "medium" && 
    //         size_ != "Large" && size_ != "large") {
    //             throw std::invalid_argument("Invalid argument: Received an invalid size");
    // }
}

// Copy constructor
Robot::Robot(const Robot& other) {
    this->id_ = other.id_;
    this->status_ = other.status_;
    this->size_ = other.size_;
    this->type_ = other.type_;
    this->room_id_ = other.room_id_;
}

Robot::~Robot() {}

void Robot::set_room(string givenRoom) {
    this->room_id_ = givenRoom;
    this->status_ = Robot_Status::Busy;
}

string Robot::get_room() const {
    return this->room_id_;
}

string Robot::to_string_size() {
    switch (this->size_) {
        case (Robot_Size::Small):
            return "Size:\tSmall";
        case (Robot_Size::Medium):
            return "Size:\tMedium";
        case (Robot_Size::Large):
            return "Size:\tLarge";
    }

    return "Size:\tUnknown";
}

string Robot::to_string_type() {
    switch (this->type_) {
        case (Type::Mop):
            return "Type:\tMop";
        case (Type::Vac):
            return "Type:\tVaccuum";
        case (Type::Scrub):
            return "Type:\tScrub";
    }

    return "Type:\tUnknown";
}

string Robot::to_string_status() {
    switch (this->status_) {
        case (Robot_Status::Free):
            return "Status:\tFree";
        case (Robot_Status::Busy):
            return "Status:\tBusy";
    }

    return "Status:\tUnknown";
}

void Robot::set_status(string status_) {
    if (status_ == "Free") {
        this->status_ = Robot_Status::Free;
    } else if (status_ == "Busy") {
        this->status_ = Robot_Status::Busy;
    } else {
        this->status_ = Robot_Status::Free;
    }
}

// basically reset
void Robot::go_home() {
    this->room_id_ = "NA";
    this->status_ = Robot_Status::Free;
}

string Robot::to_string() {
    std::string data = "ID:\t" + id_ + "\n" + to_string_status() + "\n" + "Room:\t" + this->room_id_+ "\n" + to_string_size() + "\n" + to_string_type();
    return data;
}

Robot_Size Robot::get_size() {
    return this->size_;
}

bool Robot::operator<(const Robot& other) const {
        return std::stoi(id_) < std::stoi(other.id_);
 }