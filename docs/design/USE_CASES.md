# Primary - Fleet Management Use Case

### Contributions:
* **Liz**
    - use_case.puml and .png
    - .md: Actors/Entities, Use Cases, Relationships
* **Waleed** 
    - .md: description, customer goal, customer actions 
* **Wonyoung**
    - reviewed and merged all pull requests 
* **Kate**
    - brainstorming


#
![Diagram Description](../images/use_case.png)
The customers will be able to manage their fleet of robots through a command line interface application. This UML diagram visualizes the interactions between a manager (`Customer`), rooms, and various types of cleaning robots.


The **customer** will be able to:

* Check the status of the room
* Check the status of individual robots
    - Checks if robot's battery life and whether or not the specific robot is in need of maintenance
* Order the vacuum robot to vacuum selected room in building
* Order the mopping robot to mop selected room in building
* Order the scrubber robot to scrub selected room in building
* Facilitate the maintenance/charging station of the robots


## Actors/Entities:

1. **Customer (Manager)**: The primary user who interacts with the fleet management tool to get statuses, manage maintenance, and assign tasks.
   
2. **Room**: Represents a physical room.
   
3. **Mop Bot**: A robot designed for mopping.
   
4. **Vacuum Bot**: A robot designed for vacuuming.
   
5. **Scrub Bot**: A robot designed for scrubbing.

## Use Cases:

1. **Check Robot Status**: Allows the customer to check the status of any robot:
    - **Ready**: The robot is available for tasks.
    - **Offline**: The robot is not operational.
    - **Busy**: The robot is currently working on a task, and the time until it's free is displayed.

2. **Check Room Status**: Allows the customer to check the cleanliness status of a room:
    - **Clean**: The room is already cleaned.
    - **In-Progress**: Cleaning is currently taking place in the room.
    - **Dirty**: The room is yet to be cleaned.

3. **Manage Robot Maintenance**: Enables the customer to send any robot to maintenance/charging station.

4. **Order Mopping**: The customer can assign mopping tasks to the Mop Bot.

5. **Order Vacuuming**: The customer can assign vacuuming tasks to the Vacuum Bot.

6. **Order Scrubbing (UC6)**: The customer can assign scrubbing tasks to the Scrub Bot.

## Relationships:

- Robot status interacts with customer and every robot type.
- Room cleanliness status interacts with rooms and customer.
- Maintenance management interacts with customer and each robot type.
- Mopping, vacuuming, and scrubbing use cases interact with customer, room, and their respective robots.

