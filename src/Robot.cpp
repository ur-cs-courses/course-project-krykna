#include "../include/libRobot/Robot.hpp"
#include <iostream>
#include <string>
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
            return "Size: Small";
        case (Robot_Size::Medium):
            return "Size: Medium";
        case (Robot_Size::Large):
            return "Size: Large";
    }
}

string Robot::to_string_type() {
    switch (this->type_) {
        case (Type::Mop):
            return "Type: Mop";
        case (Type::Vac):
            return "Type: Vaccuum";
        case (Type::Scrub):
            return "Type: Scrub";
    }
}

string Robot::to_string_status() {
    switch (this->status_) {
        case (Robot_Status::Free):
            return "Status: Free";
        case (Robot_Status::Busy):
            return "Status: Busy";
    }
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
    std::string data = "Robot:\t" + id_ + "\n" + to_string_status() + "\n" + to_string_size() + "\n" + to_string_type();
    return data;
}

Robot_Size Robot::get_size() {
    return this->size_;
}

bool Robot::operator<(const Robot& other) const {
        return std::stoi(id_) < std::stoi(other.id_);
 }