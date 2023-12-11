#include "../include/manage/Management.hpp"


Management::Management() {
    this->csv_path_room_ = "";
    this->csv_path_robot_ = "";
    robot_list_.clear();
    room_list_.clear();
    assignment_map.clear();
}

Management::Management(const std::string& csv_path_robot_, const std::string& csv_path_room_){
    this->csv_path_room_ = csv_path_room_;
    this->csv_path_robot_ = csv_path_robot_;
    robot_list_.clear();
    room_list_.clear();
    assignment_map.clear();
    initialize_room_list_from_csv_file(csv_path_room_);
    initialize_robot_list_from_csv_file(csv_path_robot_);
}


// Private methods
void Management::initialize_robot_list_from_csv_file(const std::string& csv_path) {
    std::ifstream csvFile(csv_path);
    
    if (!csvFile.is_open()) {
        std::cerr << "Could not open the file: " << csv_path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(csvFile, line)) {
        std::istringstream iss(line);
        std::string ID;
        std::string size;
        std::string clean_type;
        std::string online_status;
        std::string room_id;
        std::getline(iss, ID, ',');
        std::getline(iss, online_status, ',');
        std::getline(iss, size, ',');
        std::getline(iss, clean_type, ',');
        std::getline(iss, room_id, ',');
        
        add_new_robot(ID, online_status, size, clean_type, room_id);

        // USE: For dumb compilers
        if (room_id == "0" || ((atoi(room_id.c_str()) >= 1) && (room_id.compare("NA") < 0))) {
            cleaning_assignment(ID, room_id);
        }

        // USE: For macBook
        // if (room_id != "NA") {
        //     cleaning_assignment(ID, room_id);
        // }
    }
    
    csvFile.close();
}


void Management::initialize_room_list_from_csv_file(const std::string& csv_path) {
    std::ifstream csvFile(csv_path);
    
    if (!csvFile.is_open()) {
        std::cerr << "Could not open the file: " << csv_path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(csvFile, line)) {
        std::istringstream iss(line);
        std::string name;
        std::string status;
        std::string size;
        std::string time;
        std::getline(iss, name, ',');
        std::getline(iss, status, ',');
        std::getline(iss, size, ',');
        std::getline(iss, time, ',');
        
        add_new_room(name, status, size, time);
    }

    
    csvFile.close();
}


void Management::add_new_robot(std::string& ID, std::string& online_status, std::string& size, std::string& clean_type, std::string& room_id) {
    robot_list_[ID] = Robot(ID, online_status, size, clean_type, room_id);
}

void Management::add_new_room(std::string& ID, std::string& clean_status, std::string& size, std::string& time_till_clean) {
    room_list_[ID] = Room(ID, clean_status, size, time_till_clean);
}

std::string Management::to_string_room_list() {
    std::string output = "********** ROOMS ************ \n \n";
    for (auto& pair : room_list_) {
        output += pair.second.to_string() + "\n" + "\n";
    }
    return output;
}


std::string Management::to_string_robot_list() {
    std::string output = "********** ROBOTS ************ \n \n";
    for (auto& pair : robot_list_) {
        output += pair.second.to_string() + "\n" + "\n";
    }
    return output;
}

void Management::maintenance(std::string bot){
    Robot& robot = robot_list_[bot];
    robot.set_status("Offline");
    std::thread t1([this, &robot]{ 
        std::this_thread::sleep_for(std::chrono::seconds(5));
        robot.set_status("Free");
        });
    t1.detach();
}

void Management::cleaning(Robot& robot, Room& room, int time){
    bool fail;
    for (int i = 0; i < time; i++) {
        std::random_device rd;  // Obtain a random number from hardware
        std::mt19937 gen(rd()); // Seed the generator
        std::uniform_int_distribution<> distr(0, 99); 
        fail = distr(gen) < 10;
        room.set_time_to_clean(i);
        if (fail == true){
            room.set_status(Room_Status::dirty);
            robot.go_home();
            robot.set_status("Broken");
            std::cout << "Robot " + robot.get_id() + " in room " + room.get_id() + " is broken." << std::endl;
            return;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    room.set_status(Room_Status::clean);
    room.set_time_to_clean(0);
    robot.go_home();
}

void Management::cleaning_assignment(std::string bot, std::string rm){
    Robot& robot = robot_list_[bot];
    Room& room = room_list_[rm];
    if (robot.get_status() != Robot_Status::Free && robot.get_room() != room.get_id()){
        throw std::invalid_argument("Invalid assignment: Robot is unavailable");
    }
    if (room.get_status() == Room_Status::clean){
        throw std::invalid_argument("Invalid assignment: Room is already clean");
    }

    assignment_map[robot] = room;
    int time = 0;

    if (robot.get_size() == Large) {
        time = room.get_time_to_clean();
    } else if (robot.get_size() == Medium) {
        time = room.get_time_to_clean() * 2;
    } else {
        time = room.get_time_to_clean() * 3;
    }

    room.set_status(in_progress);
    robot.set_status("Busy");
    robot.set_room(rm);

    std::thread t1([this, &robot, &room, time]{ 
        this->cleaning(robot, room, time); 
        });
    t1.detach();

    assignment_map.erase(robot);
}

//Robot& Management::get_bot(std::string id){ return this->robot_list_[id];}