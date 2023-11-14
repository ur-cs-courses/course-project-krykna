//#include "../include/libRobot/Robot.hpp"
#include "libRobot/Robot.hpp"
using namespace std;

Robot::Robot(string ID, string status_, string size_, string type_) {
    this->id_ = ID;
    if (status_ == "Free") {
        this->status_ = Robot_Status::Free;
    } else if (status_ == "Busy") {
        this->status_ = Robot_Status::Busy;
    }

    if (type_ == "Mop") {
        this->type_ = Type::Mop;
    } else if (type_ == "Vac") {
        this->type_ = Type::Vac;
    } else if (type_== "Scrub") {
        this->type_ = Type::Scrub;
    }

    if (size_ == "Small") {
        this->size_ = Robot_Size::Small;
    } else if (size_ == "Medium") {
        this->size_ = Robot_Size::Medium;
    } else if (size_== "Large") {
        this->size_ = Robot_Size::Large;
    }
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

    return "Size:\tNA";
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

    return "Type:\tNA";
}

string Robot::to_string_status() {
    switch (this->status_) {
        case (Robot_Status::Free):
            return "Status:\tFree";
        case (Robot_Status::Busy):
            return "Status:\tBusy";
    }

    return "Status:\tNA";
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
