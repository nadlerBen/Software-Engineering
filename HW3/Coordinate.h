#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <string>
#include "Map.hpp"

//The coordinate class role is to hold the X&Y coordinates for a certain robot.
class Coordinate
{
private:
    int x;
    int y;
    
public:
    //Constructors
    Coordinate(int new_x, int new_y): x(new_x), y(new_y) { } //Default constructor
    Coordinate(const Coordinate& new_coordinate): x(new_coordinate.x), y(new_coordinate.y) { } // Copy constructor

    //Destructor
    ~Coordinate(){}
    
    //Member functions
    inline void print()
    {  
           std::cout << " at: " << x << "," << y << std::endl;  
    };
    /* function retrieves x coordinate of a robot, which is a private member of
     Coordinate class. */
    inline const int get_x()
    {
        return x;
    }
    /* function retrieves y coordinate of a robot, which is a private member of
     Coordinate class. */
    inline const int get_y()
    {
        return y;
    }
    /* function sets a new value to the x coordinate member. */
    void set_x(int locX){
        x = locX;
    }
    /* function sets a new value to the y coordinate member. */
    void set_y(int locY){
        y = locY;
    }
    /* function gets a direction, checks if new location for the robot is not a wall
     or destroys the wall depends on the function that called it. */
    bool changeCoordinates(std::string& direction, Map* map);
    /* function changes the coordinates for robots that already exist. */
    void replaceExisitingCoordinates(const int& new_x, const int& new_y);
};

#endif 
