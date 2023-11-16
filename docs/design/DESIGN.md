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

**`IMPORTANT FORMAT NOTE`**:  Any attribute or method names that are **BOLD** signify that they have not been implemented yet in the class. Any attribute or method names that are in `HIGHLIGHT` means that it has been implemented in the class.

Attributes

* **room_clean: set:** A set containing the rooms that are clean.
* **rooms_dirty: set:** A set containing the rooms that are dirty.
* **bots_ready: set:** A set containing the robots that are ready for cleaning.
* **bots_out: set**: A set containing the robots that are currently out cleaning or out of commission.

* `room_list_: set`: A Set (vector) with room class objects.
* `robot_list_: set`: A Set (vector) with robot class objects.
* `csv_path_room_: String`: A String storing the path to a csv file comprised of a detailed building's room list.
* `csv_path_robot_: String`: A String storing the path to a csv file comprised of a detailed inventory of the robots within a manager's fleet.

Methods

* `initialize_robot_list_from_csv_file(): void`: A helper function for reading the csv file for the robots within a manager's fleet.
* `initialize_room_list_from_csv_file(): void`: A helper function for reading the csv file for the rooms within a building.
* **assign_bots(): void**: Assigns robots to rooms for cleaning.
* **update_rooms(): void**: Updates the status of rooms (clean/dirty).
* **update_bots(): void**: Updates the status of robots (clean/dirty).
* **availability_string(): string**: Returns a string representing the availability of robots (available/not).
* **room_status_string(): string**: Returns a string representing the status of rooms (clean/dirty).
* **bot_data_string()**: string: Returns a string representing the status of robots (size, type).
* `add_new_bot(): void`: Adds a new robot to the system.
* `add_new_room(): void`: Adds a new room to the system.
* `to_string_room_list(): String`: Returns the data of the rooms in the room_list_.
* `to_string_robot_list(): String`: Returns the data of the robots in the robot_list_.

Relationships

* The Management class has a 1 to 0...n  aggregation relationship with the Rooms class.
* The Management class has a 1 to 0...n composition relationship with the Robots class.
* The Management class implements the CommandLine interface.

## Robot Class Diagram Overview

![Diagram Description](images/robot_class_diagram.png)

This document describes the class diagram for a system of robots that involves receiving input commands and cleaning rooms. The system focuses on the attributes of the Robot class and mentions its relationships with other classes and interfaces (Management, Rooms).

## Classes
### Robot

**`IMPORTANT FORMAT NOTE`**:  Any attribute or method names that are **BOLD** signify that they have not been implemented yet in the class. Any attribute or method names that are in `HIGHLIGHT` means that it has been implemented in the class.

Attributes

* `robot_name: String`: A String storing the name/ID of the robot.
* `robot_status: Robot_Status`: An enum variable storing the status of the robot --> (`Free`, `Busy`).
* `robot_size: Robot_Size`: An enum variable storing the size of the robot --> (`Small`, `Medium`, `Large`).
* `robot_type: Robot_Type`: An enum variable storing the type of the robot --> (`Mop`, `Vac`, `Scrub`).
* `assigned_room: String`: A String storing the room a robot is assigned to clean --> (*default "" when robot status is Free*).

Methods

* **get_robot_size(): Robot_Size**: Returns the enum value of Robot_Size of a robot object.
* `set_assigned_room(): void`: Stores the name of the room that a robot is assigned to clean.
* `get_assigned_room(): String`: Returns the room name the robot is assigned to clean (returns "" if not currently assigned).
* `set_robot_status(): String`: Sets robot status to either "Free" or "Busy"; determined by if they are currently assigned to clean or not.
* `go_home(): void`: Acts a reset for the robot; sets the robot status to "Free" and the name of the room assigned to "".
* `to_string_type(): String`: A helper function to convert the robot_type (enum) to a string; used by to_string().
* `to_string_status(): String`: A helper function to convert the robot_status (enum) to a string; used by to_string().
* `to_string_size(): String`: A helper function to convert the robot_size (enum) to a string; used by to_string().
* `to_string(): String`: Returns the data of a Robot object in a nicely structured format.

Relationships

* The Robot class has a 1 to 1 aggregation relationship with the Rooms class.
* The Robot class has a 1-to-1 composition with enum class Robot_Status.
* The Robot class has a 1-to-1 composition with enum class Robot_Size.
* The Robot class has a 1-to-1 composition with enum class Robot_Type.

## Room Class Diagram Overview

![Diagram Description](images/room_class_diagram.png)

This document describes the class diagram for a system of rooms that involves receiving input commands and cleaning rooms. The system focuses on the attributes of the Room class and mentions its relationships with other classes and interfaces (Management, Robots, and enum classes Status and Size).

## Classes
### Room

**`IMPORTANT FORMAT NOTE`**:  Any attribute or method names that are **BOLD** signify that they have not been implemented yet in the class. Any attribute or method names that are in `HIGHLIGHT` means that it has been implemented in the class.

Attributes

* `room_name: String`: A String storing the room name.
* `estimated_clean_time: int`: An int variable storing the estimated time to clean the room.
* `room_status: Status`: An enum variable storing the cleanliness status of the room --> (`Dirty`, `In-progress`, `Clean`).
* `room_size: Size`: An enum variable storing the size of the room --> (`Small`, `Medium`, `Large`).

Methods

* **get_estimated_clean_time(): int**: Returns the integer value of the estimated time to clean; used to calculate the timer for an assigned robot to clean.
* **update_room_status(): void**: Updates the room status; used when a robot is assigned to a room (i.e. room_status changes to `In-progress`) and cleaning is finished (i.e. room_status changes to `Clean`).
* `status_to_string(): String`: A helper function to convert the room_status (enum) to a string; used by to_string().
* `size_to_string(): String`: A helper function to convert the room_size (enum) to a string; used by to_string().
* `time_to_string(): String`: A helper function to convert the estimated_clean_time (int) to a string; used by to_string().
* `to_string(): String`: Returns the data of a Room object in a nicely structured format.

Relationships

* The Room class has a 1-to-1 composition with enum class Status.
* The Room class has a 1-to-1 composition with enum class Size.

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
