#include "../include/libroom/room.hpp"

Room::Room() {
    this->room_name_ = "TBD";
    this->room_status_ = Room_Status::emp;
    this->room_size_ = Room_Size::emp2;
    this->estimated_time_ = 0;
}

Room::Room(std::string name, std::string status, std::string size, std::string time)
    : room_name_(name)
{
    std::string stat_conv = to_lower(status);
    std::string size_conv = to_lower(size);
    convert_to_status(stat_conv);
    convert_to_size(size_conv);

    this->estimated_time_ = std::stoi(time);

}

Room::Room(const Room &other)
    : room_name_(other.room_name_),
      room_status_(other.room_status_),
      room_size_(other.room_size_),
      estimated_time_(other.estimated_time_)
{}

Room::~Room() {}

void Room::convert_to_status(std::string& status_string_) {
    if (status_string_ == "dirty") {
        this->room_status_ = Room_Status::dirty;
    } else if (status_string_ == "in-progress" || status_string_ == "in progress" || status_string_ == "ip") {
        this->room_status_ = Room_Status::in_progress;
    } else if (status_string_ == "clean") {
        this->room_status_ = Room_Status::clean;
    } else {
        throw std::invalid_argument("Invalid argument: Received an invalid status");
    }
}

void Room::convert_to_size(std::string& size_string_) {
    if (size_string_ == "small" || size_string_ == "s") {
        this->room_size_ = Room_Size::small;
    } else if (size_string_ == "medium" || size_string_ == "med" || size_string_ == "m") {
        this->room_size_ = Room_Size::medium;
    } else if (size_string_ == "large" || size_string_ == "lg" || size_string_ == "l") {
        this->room_size_ = Room_Size::large;
    } else {
        throw std::invalid_argument("Invalid argument: Received an invalid size");
    }
}

std::string Room::to_lower(std::string& string_to_convert) {
    std::string lowercase;
    for (char c : string_to_convert) {
        lowercase.push_back(std::tolower(c));
    }
    return lowercase;
}

std::string Room::to_string_status() {
    switch (this->room_status_) {
        case (Room_Status::dirty):
            return "Room Status:\tDirty";
        case (Room_Status::in_progress):
            return "Room Status:\tIn-progress";
        case (Room_Status::clean):
            return "Room Status:\tClean";
    }

    return "Room Status:\tUnknown";
}

std::string Room::to_string_size() {
    switch (this->room_size_) {
        case (Room_Size::small):
            return "Room Size:\tSmall";
        case (Room_Size::medium):
            return "Room Size:\tMedium";
        case (Room_Size::large):
            return "Room Size:\tLarge";
    }

    return "Room Size:\tUnknown";
}

std::string Room::to_string_time() {
    std::string est_time = "Estimated Time to Clean: " + std::to_string(this->estimated_time_) + " minutes";
    return est_time;
}

std::string Room::to_string() {
    std::string data = "Room Name:\t" + this->room_name_ + "\n" + to_string_status() + "\n" + to_string_size() + "\n" + to_string_time();
    return data;
}