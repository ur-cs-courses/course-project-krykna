#include "../include/libRobot/Robot.hpp"
#include <iostream>
#include <string>
using namespace std;

// Keep track of Timer 
// Multiples of different factor depending on size
// Get Timer from Management 
    // Math in Robot
    // Large = Standard
    // Medium  = Standard * 2
    // Small = Standard * 3
// Make new branch off of Integration Test and copy and paste the 3 files changed

Robot::Robot(int ID, string status, string size, string type) {
    this->id = ID;
    if (status == "Free") {
        this->status = Status::Free;
    } else if (status == "Busy") {
        this->status = Status::Busy;
    }

    if (type == "Mop") {
        this->type = Type::Mop;
    } else if (type == "Vac") {
        this->type = Type::Vac;
    } else if (type== "Scrub") {
        this->type = Type::Scrub;
    }

    if (size == "Small") {
        this->size = Size::Small;
    } else if (size == "Medium") {
        this->size = Size::Medium;
    } else if (size== "Large") {
        this->size = Size::Large;
    }
}

Robot::~Robot() {}

void Robot::setRoom(string givenRoom) {
    this->room = givenRoom;
    this->status = Status::Busy;
}

string Robot::getRoom() const {
    return this->room;
}

string Robot::sizeToString() const {
    switch (this->size) {
        case (Size::Small):
            return "Small";
        case (Size::Medium):
            return "Medium";
        case (Size::Large):
            return "Large";
    }
}

string Robot::typeToString() const {
    switch (this->type) {
        case (Type::Mop):
            return "Mop";
        case (Type::Vac):
            return "Vac";
        case (Type::Scrub):
            return "Scrub";
    }
}

string Robot::statusToString() const {
    switch (this->status) {
        case (Status::Free):
            return "Free";
        case (Status::Busy):
            return "Busy";
    }
}

void Robot::setStatus(string status) {
    if (status == "Free") {
        this->status = Status::Free;
    } else if (status == "Busy") {
        this->status = Status::Busy;
    }
}

// basically reset
void Robot::goHome() {
    this->room = "";
    this->status = Status::Free;
}