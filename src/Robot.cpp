#include "../include/libRobot/Robot.hpp"
#include <iostream>
#include <string>
using namespace std;

Robot::Robot(string ID, string status, string size, string type) {
    this->id = ID;
    if (status == "Free") {
        this->status = Robot_Status::Free;
    } else if (status == "Busy") {
        this->status = Robot_Status::Busy;
    }

    if (type == "Mop") {
        this->type = Type::Mop;
    } else if (type == "Vac") {
        this->type = Type::Vac;
    } else if (type== "Scrub") {
        this->type = Type::Scrub;
    }

    if (size == "Small") {
        this->size = Robot_Size::Small;
    } else if (size == "Medium") {
        this->size = Robot_Size::Medium;
    } else if (size== "Large") {
        this->size = Robot_Size::Large;
    }
}

Robot::~Robot() {}

void Robot::set_room(string givenRoom) {
    this->room = givenRoom;
    this->status = Robot_Status::Busy;
}

string Robot::get_room() const {
    return this->room;
}

string Robot::to_string_size() const {
    switch (this->size) {
        case (Robot_Size::Small):
            return "Small";
        case (Robot_Size::Medium):
            return "Medium";
        case (Robot_Size::Large):
            return "Large";
    }
}

string Robot::to_string_status() const {
    switch (this->type) {
        case (Type::Mop):
            return "Mop";
        case (Type::Vac):
            return "Vac";
        case (Type::Scrub):
            return "Scrub";
    }
}

string Robot::to_string_status() const {
    switch (this->status) {
        case (Robot_Status::Free):
            return "Free";
        case (Robot_Status::Busy):
            return "Busy";
    }
}

void Robot::set_status(string status) {
    if (status == "Free") {
        this->status = Robot_Status::Free;
    } else if (status == "Busy") {
        this->status = Robot_Status::Busy;
    }
}

// basically reset
void Robot::go_home() {
    this->room = "";
    this->status = Robot_Status::Free;
}

string Robot::to_string() {
    std::string data = "Robot:\t" + this->id + "\n" + to_string_status() + "\n" + to_string_size() + "\n" + to_string_type();
    return data;
}
