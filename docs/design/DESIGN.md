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

* room_clean: set: A set containing the rooms that are clean.
* rooms_dirty: set: A set containing the rooms that are dirty.
* bots_ready: set: A set containing the robots that are ready for cleaning.
* bots_out: set: A set containing the robots that are currently out cleaning or out of commission.

Methods

* assign_bots(): void: Assigns robots to rooms for cleaning.
* update_rooms(): void: Updates the status of rooms (clean/dirty).
* update_bots(): void: Updates the status of robots (clean/dirty).
* availability_string(): string: Returns a string representing the availability of robots (available/not).
* room_status_string(): string: Returns a string representing the status of rooms (clean/dirty).
* bot_data_string(): string: Returns a string representing the status of robots (size, type).
* add_new_bot(): void: Adds a new robot to the system.
* add_new_room(): void: Adds a new room to the system.

Relationships

* The Management class has a 1 to 0...n  composition relationship with the Rooms class.
* The Management class has a 1 to 0...n composition relationship with the Robots class.
* The Management class implements the CommandLine interface.

## Robot Class Diagram Overview

![Diagram Description](images/robot_class_diagram.png)

This document describes the class diagram for a system of robots that involves receiving input commands and cleaning rooms. The system focuses on the attributes of the Robot class and mentions its relationships with other classes and interfaces (Management, Rooms).

## Classes
### Robot

Attributes

* room_assigned: set: A set room assigned for robot to clean.
* task_assigned: set: A set task of either mop, scrub, or vacuum.
* robot_status: set: Status of robot ready or not.
* room_status: set: The status of the room currently assigned.
* timer: set: A set time needed to clean the assigned room.

Methods

* clean_room(): void: Robot set to clean assigned room.
* go_home(): void: Robot sent back home.
* get_robot_status(): Returns an int representing whether robot has failed or not.
* update_robot_status(): Returns an int representing whether robot is ready for new task or not.
* get_room_status(): Returns an int representing how much is left of the assigned room.
* update_room_stats(): Updates whether the current room is cleaned.

Relationships

* The Robot class has a 0...n to 0...n composition relationship with Rooms class.

## Room Class Diagram Overview

![Diagram Description](images/room_class_diagram.png)

This document describes the class diagram for a system of rooms that involves receiving input commands and cleaning rooms. The system focuses on the attributes of the Room class and mentions its relationships with other classes and interfaces (Management, Robots, and enum classes Status and Size).

## Classes
### Room

Attributes

* room_name: string: The name of a room
* status: enum: The status of the room currently assigned.
* size: enum: The size of the room

Methods

* update_room_status(): void: Updates whether the current room is cleaned.
* get_room_status(): Returns an enum representing the current state of the assigned room (dirty, in-progress, clean).
* get_size(): Returns an enum representing the size of a room (small, medium, large).

Relationships

* The Room class has a 1-to-1 composition with enum class Status
* The Room class has a 1-to-1 composition with enum class Size
