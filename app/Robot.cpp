#include "Robot.hpp"
#include <iostream>
#include <string>
using namespace std;

Robot::Robot() {
    setRoom("");
    setTimer(0);
}

Robot::Robot(string room, int time) {
    setRoom(room);
    setTimer(time);
}

void setRoom(string room) {
    this->room = room;
}

string getRoom() const {
    return room;
}

string getType() const {
    return type;
}

string getStatus() const {
    return status;
}

void setStatus(string status) {
    this->status = status;
}

void setTimer(int value) {
    this->timer = value;
}

int getTimer() const {
    return timer;
}

void setLocation(string location) {
    this->location = location;
}

string getLocation() const {
    return location;
}


void cleanRoom() const {
    this->location = room;
    // count down timer?
    // 
}

// basically reset
void goHome() const {
    this->location = "home";
    this->timer = 0;
    this->room = "";
}