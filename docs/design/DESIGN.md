# Design Document for Robot Fleet Management Software
## Introduction
In our design document, we will be going over how we plan on developing our robot fleet management system.

_* Our actual design implementation isn't fully completed yet. We are still in the beginning phases of our Scrum development process._

## Project Overview

**Our software will help building managers, the customers, manage their fleet of cleaning robots in their building.**



Potential Design Ideas:

* Retrieval System of Robot Information from Backend Database
* Developers will potentially implement a bug detection system to ensure software has no external issues

# Class Diagram Documentation

## Management Class Diagram Overview

![Diagram Description](images/management_class_diagram.png)

This document describes the class diagram for a simple management system that involves room cleaning by robots. The system focuses on the attributes of the main class, Management, and mentions its relationships with other classes and interfaces (CommandLine, Robots, Rooms). 

## Classes
### Management

Attributes

* `room_list_`: *set* - A map containing the rooms added to the system
* `robot_list_`: *set* - A map containing the robots added to the system
* `assignment_map`: *set* - A map containing the assignment of robots to rooms
* `csv_path_room_`: *string* - A string representing the path to the csv file containing the rooms of a building
* `csv_path_robot_`: *string* - A string representing the path to the csv file containing the set of rooms a manager has in their fleet

Methods

* `initialize_room_list_from_csv_file(string)`: *void* - Reads csv file for rooms to be added to the system.
* `initialize_robot_list_from_csv_file(string)`: *void* - Reads csv file for robots to be added to the system
* `add_new_bot(string)`: *void* - Adds a new robot to the system based on passed strings [requires 5 string parameters].
* `add_new_room(string)`: *void* - Adds a new room to the system based on passed string [requires 4 string parameters].
* `maintenance(string)`: *void* - Takes a user-chosen  robot offline for repairs
* `cleaning(Robot, Room, int)`: *void* - Simulates a robot cleaning a room for a calculated amount of time, including possibility of breaking or running out of battery.
* `cleaning_assignment(string)`: *void* - Assigns a user-chosen robot to a user-chosen room for cleaning
* `charge(string)`: *void* - Takes a user-chosen robot offline for charging
* `to_string_room_list()`: *string* - Returns the overall room details of room_list_
* `to_string_robot_list()`: *string* - Returns the overall robot details of robot_list_
* `get_bot(string)`: *Robot* - Returns the corresponding Robot of the string id passed
* `get_room(string)`: *Room* - Returns the corresponding Room of the string id passed


Relationships

* The Management class has a 1 to 0...n  aggregation relationship with the Rooms class.
* The Management class has a 1 to 0...n aggregation relationship with the Robots class.
* The Management class implements the CommandLine interface.

## Robot Class Diagram Overview

![Diagram Description](images/robot_class_diagram.png)

This document describes the class diagram for a system of robots that involves receiving input commands and cleaning rooms. The system focuses on the attributes of the Robot class and mentions its relationships with other classes and interfaces (Management, Rooms).

## Classes
### Robot

Attributes

* `id_`: *string* - A string representing the id of a robot
* `room_id_`: *string* - A string representing the room a robot is assigned to clean.
* `size_`: *enum* - An enum representing the size of a robot
* `status_`: *enum* - An enum representing the current status of a robot, including: **Free, Busy, Offline, Broken, Dead**.
* `type_`: *enum* - An enum representing the type of a robot is either: **mop, scrub, vaccuum**.
* `battery_`: *int* - An integer representing the current battery of a robot.

Methods

* `go_home()`: *void* - Resets the status and room assignment
* `kill_battery()`: *void* - Decrements the current battery power of a robot based on its type. Larger robots last longer than others.
* `charge_battery()`: *void* - Restores the battery to full power
* `set_status(string)`: *void* - Updates the status of a robot based on string input given
* `set_size(string)`: *void* - Sets the size of a robot based on string input given
* `set_type(string)`: *void* - Sets the type of a robot based on string input given 
* `set_room(string)`: *void* - Updates the room assignment of a robot either when manager assigns or when a robot is finished
* `get_id()`: *string* - Returns the id of the robot
* `get_room()`: *string* - Returns the current room assignment
* `get_size()`: *enum* - Returns an enum of the robot size
* `get_status()`: *enum* - Returns an enum of the current status
* `get_battery()`: *int* - Returns an int representing the current battery "percentage" of a robot
* `to_string_status()`: *string* - Returns a string representing the robot status. Used only as a helper function for the `to_string()` function.
* `to_string_size()`: *string* - Returns a string representing the robot size. Used only as a helper function for the `to_string()` function.
* `to_string_type()`: *string* - Returns a string representing the robot type. Used only as a helper function for the `to_string()` function.
* `to_string()`: *string* - Returns a string containing the details of a robot object instance.

Relationships

* The Robot class has a 1-to-1 composition with enum class Size. 
* The Robot class has a 1-to-1 composition with enum class Status.
* The Robot class has a 1-to-1 composition with enum class Type.

## Room Class Diagram Overview

![Diagram Description](images/room_class_diagram.png)

This document describes the class diagram for a system of rooms that involves maintaining the cleanliness. The system focuses on the attributes of the Room class and mentions its relationships with other classes and interfaces (Management, Robots, and enum classes Status and Size).

## Classes
### Room

Attributes

* `room_name_`: *string* - A string representing the name/id of a room
* `room_status_`: *enum* - An enum representing the status of a room as either: **Dirty, In-progress, Clean**
* `room_size_`: *enum* - An enum representing the size of a room
* `estimated_time_`: *int* - An int representing the approximate time to clean a room

Methods

* `convert_to_status(string)`: *void* - Converts string input to an enum representing the appropriate room status. Used only during room instance creation.
* `convert_to_size(string)`: *void* - Converts string input to an enum representing the appropriate room size. Used only during room instance creation.
* `to_lower(string)`: *void* - Converts passed string input to lowercase to cover most variations of strings. Used only during room instance creation.
* `set_status(enum)`: *void* - Updates the status of a room.
* `get_status()`: *enum* - Returns an enum indicating the current state of the room (dirty, in-progress, clean).
* `set_time_to_clean(int)`: *void* - Updates the time to clean the room according to the current cleaning progress made.
* `get_time_to_clean()`: *int* - Returns an int representing the current time duration it may take for the room to be cleaned.
* `get_id()`: *string* - Returns a string representing the room identifier/name.
* `to_string_status()`: *string* - Returns a string representing the room status. Used only as a helper function for the `to_string()` function.
* `to_string_size()`: *string* - Returns a string representing the room size. Used only as a helper function for the `to_string()` function.
* `to_string_time()`: *string* - Returns a string representing the approximate time to clean a room. Used only as a helper function for the `to_string()` function.
* `to_string()`: *string* - Returns a string containing the details of a room object instance.

Relationships

* The Room class has a 1-to-1 composition with enum class Status
* The Room class has a 1-to-1 composition with enum class Size

# Sequence Diagram Documentation

## Overview

This documentation explains a sequence diagram that outlines the interactions between four components involved in a robot cleaning a room from start to finish:

1. `CommandLine (CLI)`: The command line interface for users.
2. `Management (M)`: The management system that handles room and robot statuses.
3. `Robots (Bot)`: Represents the robots available for cleaning.
4. `Rooms (R)`: Represents the rooms available for cleaning.

## Cleaning Sequence Diagram
![Diagram Description](images/cleaning_sequence_diagram.png)

## Components

#### Assign Bot for Cleaning

1. CLI sends a message to `Management` to assign a bot to clean a room.
   - `Management` assigns  `Bot` to a room.
   - `Bot`
     -  updates its status to `BUSY`.
     -  starts the cleaning process.
   - `Room`
     - starts a timer for cleaning.
   
##### Optional Flow: Robot Breaks

- `opt Robot breaks`: An optional block where the robot can break.
  - `Room`
    - pauses the timer.
    -  notifies `Bot` that bot is broken.
  - `Bot`
    - notifies `Management`.
  - `Management`
    - checks for available bots.
    - `alt if another bot is available`:
      - Assigns another bot to the room.
      - `Bot`
        - New bot starts cleaning.
      - `Room`
        -  Room resumes timer.

    - `else if no other bot is available`:
      -  Notifies CLI that cleaning assignment was unsuccessful.

- `Room`
    - cleaning timer ends.
    - updates its status to `CLEAN`.
    - notifies `Management` that the room is clean.
- `Bot`
    - updates its status to `FREE`.
    - notifies `Management` that it's now free.
- `Management` Notifies `CLI` that the cleaning was successful.



## Requesting Room and Bot Status Sequence Diagram
![Diagram Description](images/requesting_status_sequence_diagram.png)

- `CommandLine requests room or bot status from management`
- `Management` 
     -  converts status data to string format.
     -   sends back the status of the room/bot as a string to `CLI`.



## Adding New Rooms and Bots Sequence Diagram
![Diagram Description](images/adding_sequence_diagram.png)

- `CommandLine requests add new bot/room from management`
- `Management` 
    -  initialize new bot/room object
    -   add  bot/room to free set

# Activity Diagram Documentation

## Overview

This documentation explains an activity diagram that outlines the overall activity of the program between the user, robot, and the rooms. The activity diagram captures the very big picture on a simple level without the exact details. 

1. The User is online in the software.
2. The user checks the system whether there are any robots available.
    - If Robot IS available, Assign robot the given task
    - If Robot is NOT available, wait and end.
3. Tasked robot goes to clean the assigned room.
    - If room IS clean, end.
    - Else check.. 
        - Room is not clean
            - In case room is not clean, robot continues to clean room.
        - Robot fail
            - In case robot fails, robot returns home and user is prompted.
4. If User wants to utilize other functions:
    - If user wants to add or check:
        - If add:
            - Add Robot
            - Add Room
        - If check:
            - Check Robot Status
            - Check Room Status

![Diagram Description](images/activity_diagram.png)