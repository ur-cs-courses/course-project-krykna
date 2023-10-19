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