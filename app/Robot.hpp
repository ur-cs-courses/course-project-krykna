#ifndef ROBOT_HPP
#define ROBOT_HPP
#include <string>
using namespace std;

class Robot {
    public:
        // Constructors
        Robot();
        Robot(string room, int time);

        // Room
        void setRoom(string room);
        string getRoom() const;

        // Task
        string getType() const;

        // Status
        string getStatus() const;
        void setStatus(string status);

        // Timer
        void setTimer(int value);
        int getTimer() const;
        
        // Location
        void setLocation(string location);
        string getLocation() const;

        // Robot activities
        void cleanRoom() const;
        void goHome() const;

    private:
        string room;
        string status;
        string type;
        string location;
        int timer;
};

#endif