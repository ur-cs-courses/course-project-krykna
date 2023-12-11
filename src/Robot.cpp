#include "../include/libRobot/Robot.hpp"
#include <stdexcept>

Robot::Robot() {
    this->id_ = "ERROR: NON EXISTENT BOT";
    this->status_ = Robot_Status::Busy; 
    this->size_ = Robot_Size::Medium;
    this->type_ = Type::Vac;
    this->room_id_= ""; 
}

Robot::Robot(std::string ID, std::string status_, std::string size_, std::string type_, std::string room_id_) {
    this->id_ = ID;
    this->room_id_ = room_id_;
    set_status(status_);
    set_type(type_);
    set_size(size_);
}

Robot::Robot(const Robot& other) {
    this->id_ = other.id_;
    this->status_ = other.status_;
    this->size_ = other.size_;
    this->type_ = other.type_;
    this->room_id_ = other.room_id_;
}

Robot::~Robot() {}


void Robot::set_size(std::string& bot_size_) {
    if (bot_size_ == "Small" || bot_size_ == "small") {
        this->size_ = Robot_Size::Small;
    } else if (bot_size_ == "Medium" || bot_size_== "medium") {
        this->size_ = Robot_Size::Medium;
    } else if (bot_size_== "Large" || bot_size_== "large") {
        this->size_ = Robot_Size::Large;
    } else {
        throw std::invalid_argument("Invalid argument: Received an invalid size");
    }
}

void Robot::set_type(std::string& bot_type_) {
    if (bot_type_ == "Mop" || bot_type_ == "mop") {
        this->type_ = Type::Mop;
    } else if (bot_type_ == "Vac" || bot_type_ == "Vaccuum" || bot_type_ == "vaccuum") {
        this->type_ = Type::Vac;
    } else if (bot_type_== "Scrub" || bot_type_ == "scrub") {
        this->type_ = Type::Scrub;
    } else {
        throw std::invalid_argument("Invalid argument: Received an invalid type");
    }
}

void Robot::set_room(std::string givenRoom) {
    this->room_id_ = givenRoom;
    this->status_ = Robot_Status::Busy;
}

void Robot::set_status(std::string status_) {
    if (status_ == "Free") {
        this->status_ = Robot_Status::Free;
    } else if (status_ == "Busy") {
        this->status_ = Robot_Status::Busy;
    } else if (status_ == "Broken") {
        this->status_ = Robot_Status::Broken;
    } else if (status_ == "Offline") {
        this->status_ = Robot_Status::Offline;
    }
    else {
        throw std::invalid_argument("Invalid argument: Received an invalid status");
    }
}

// basically reset
void Robot::go_home() {
    this->room_id_ = "NA";
    this->status_ = Robot_Status::Free;
}

std::string Robot::to_string_size() {
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

std::string Robot::to_string_type() {
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

std::string Robot::to_string_status() {
    switch (this->status_) {
        case (Robot_Status::Free):
            return "Status:\tFree";
        case (Robot_Status::Busy):
            return "Status:\tBusy";
        case (Robot_Status::Broken):
            return "Status:\tBroken";
        case (Robot_Status::Offline):
            return "Status:\tOffline";
    }

    return "Status:\tUnknown";
}

std::string Robot::to_string() {
    std::string data = "ID:\t" + id_ + "\n" + to_string_status() + "\n" + "Room:\t" + this->room_id_ + "\n" + to_string_size() + "\n" + to_string_type();
    return data;
}

bool Robot::operator<(const Robot& other) const {
        return std::stoi(id_) < std::stoi(other.id_);
 }