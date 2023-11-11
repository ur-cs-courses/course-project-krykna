#ifndef LIBROBOT_ROBOT_HPP
#define LIBROBOT_ROBOT_HPP
#include <string>
using namespace std;

// TODO
// Timer not needed
// Combine set room into cleanRoom param
enum class Status {Free, Busy};
enum class Size {Small, Medium, Large};
enum class Type {Mop, Vac, Scrub};

class Robot {
    public:
        // Constructors
        //Robot();
        Robot(int ID, string status, string size, string type);

        // Destructor
        ~Robot();

        // Room
        void setRoom(string room);
        string getRoom() const;


        // Status
        void setStatus(string status);
    

        // Robot activities
        void goHome();

        string typeToString() const;
        string statusToString() const;
        string sizeToString() const;
    private:
        string id;
        Size size;
        string room;
        Status status;
        Type type;
};

#endif