#include "../include/libroom/room.hpp"
#include <iostream>
Room::Room() {
    room_name = "TBD";
    this->room_status = Status::emp;
    this->room_size = Size::emp2;
    this->estimated_time = 0;
}

Room::Room(std::string name, std::string status, std::string size, std::string time)
    : room_name(name)
{

    if (status == "dirty") {
        this->room_status = Status::dirty;
    } else if (status == "in-progress" || status == "IP") {
        this->room_status = Status::in_progress;
    } else if (status == "clean") {
        this->room_status = Status::clean;
    }

    if (size == "small" || size == "s") {
        this->room_size = Size::small;
    } else if (size == "medium" || size == "med" || size == "m") {
        this->room_size = Size::medium;
    } else if (size == "large" || size == "lg" || size == "l") {
        this->room_size = Size::large;
    }

    this->estimated_time = std::stoi(time);

}

Room::Room(const Room &other)
    : room_name(other.room_name),
      room_status(other.room_status),
      room_size(other.room_size),
      estimated_time(other.estimated_time)
{}

Room::~Room() {}

std::string Room::status_to_string() {
    switch (this->room_status) {
        case (Status::dirty):
            return "Room Status:\tDirty";
        case (Status::in_progress):
            return "Room Status:\tIn-progress";
        case (Status::clean):
            return "Room Status:\tClean";
    }

    return "Room Status:\tTBD";
}

std::string Room::size_to_string() {
    switch (this->room_size) {
        case (Size::small):
            return "Room Size:\tSmall";
        case (Size::medium):
            return "Room Size:\tMedium";
        case (Size::large):
            return "Room Size:\tLarge";
    }

    return "Room Size:\tTBD";
}

std::string Room::time_to_string() {
    std::string est_time = "Estimated Time to Clean: " + std::to_string(this->estimated_time) + " minutes";
    return est_time;
}

std::string Room::get_room_data() {
    std::string data = "Room Name:\t" + room_name + "\n" + status_to_string() + "\n" + size_to_string() + "\n" + time_to_string();
    return data;
}