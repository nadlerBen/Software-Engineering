#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "Coordinate.h"
#include "Map.hpp"

using namespace std;

typedef enum { COMMUNICABLE = 0, NON_COMMUNICABLE = 1} connection_e;
typedef enum { REGULAR =0,
    QUICK = 1, LIMITED =2, STRONG =3,
} robot_type;
/**
 * Robot class role is to hold all the data and operations (function) of a single robot.
 */
class Robot
{
protected:
    Coordinate coordinate;
    const string name;
    connection_e con;
    robot_type type;
    
public:
        //constructor
    Robot(const Coordinate& new_coordinate, const string& new_name): coordinate(new_coordinate),
    name(new_name), con(COMMUNICABLE), type(REGULAR){}
    
        //destructor
    virtual ~Robot();
    // #################### Class methods ####################
    /* the function moves a regular robot. */
    virtual void moveRobot(Map* map, std::string direction);
    virtual void print()
    {
		printType(std::string("REGULAR"));
    };
    virtual const robot_type getType(){
        return type;
    }
    /* function gets the private member name of the robot and sends it to functions.
     as const. */
    inline const string& getName()
    {
        return name;
    }
    /* function sets the robot to communicale status. */
    void retrieveConnection()
    {
        con = COMMUNICABLE;
    }
    /* function sets the robot to non-communicable status. */
    void shutDownConnection()
    {
        con = NON_COMMUNICABLE;
    }
    /* function connects between RobotDB class to Coordinate class to replace
     coordinates for existing robot. */
    void replaceCoordinates(const int& x, const int& y);
protected:

    virtual void printType(const std::string & type_name)
    {
        std::cout << "Robot: " << this->name << " Type: " << type_name;
		coordinate.print();
    };
    

};

#endif
