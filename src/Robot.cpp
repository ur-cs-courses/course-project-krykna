//#include "../include/libRobot/Robot.hpp"
#include "libRobot/Robot.hpp"
using namespace std;
#include <stdexcept>

Robot::Robot(string ID, string status_, string size_, string type_) {
    // check for incorrect arguments

    this->id_ = ID;
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

Robot::~Robot() {}

void Robot::set_room(string givenRoom) {
    this->room_ = givenRoom;
    this->status_ = Robot_Status::Busy;
}

string Robot::get_room() const {
    return this->room_;
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
    }
}

// basically reset
void Robot::go_home() {
    this->room_ = "";
    this->status_ = Robot_Status::Free;
}

string Robot::to_string() {
    std::string data = "Robot ID:\t" + id_ + "\n" + to_string_status() + "\n" + to_string_size() + "\n" + to_string_type();
    return data;
}
