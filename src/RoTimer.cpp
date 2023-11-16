#include "../include/manage/Management.hpp"
#include "../include/libroom/room.hpp"
#include "../include/libRobot/Robot.hpp"

#include <map>
#include <memory>
#include <thread>
#include <chrono>
#include <vector>
#include <string>


class RoTimer {
private:
    std::map<Robot, Room> assignment_map;

public:
    RoTimer(){
        assignment_map.clear();
    }

    // RoTimer(std::vector<Robot> robot_list, std::vector<Room> room_list){
    //     int assigned_room;
    //     for (int i = 0; i < robot_list.size(); i++){
    //         assigned_room = robot_list[i].get_room();

    //     }
    // }

    void assign_room_to_robot(Robot robot, Room room) {
        assignment_map[robot] = room;
        int time = 0;
        
        if (robot.get_size() == Large){
            time = room.get_time_to_clean();
        } else if (robot.get_size() == Medium){
            time = room.get_time_to_clean() * 2;
        } else {
            time = room.get_time_to_clean() * 3;
        }
        
        // Set robot status to Busy and room status to being cleaned
        room.set_status(in_progress);
        robot.set_status("Busy");
        
        // Start the cleaning process in a separate thread
        std::thread([this, robot, room]() {
            std::this_thread::sleep_for(std::chrono::seconds(10)); // Simulate cleaning time
            // ^^^ Needs to change mathematically but this is temporary mock
        }).detach(); // Detach the thread since we don't need to join it

        room.set_status(clean);
        robot.set_status("Free");

        // remove the robot-room pair from the map
        assignment_map.erase(robot);
    }
    
};
