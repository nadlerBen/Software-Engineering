#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

#include "Coordinate.h"
#include "Map.hpp"

using namespace std;


/**
 * Robot class role is to hold all the data and operations (function) of a single robot.
 */
typedef enum { COMMUNICABLE = 0, NON_COMMUNICABLE = 1} connection_e;

class Robot
{
private:
    Coordinate coordinate;
    const string name;
    int dust_bin;
    connection_e con;
    
public:
        //constructor
    Robot(const Coordinate& new_coordinate, const std::string& new_name, int new_bin,
          connection_e con);
    
        //destructor
    ~Robot(){}
    
    // #################### Class methods ####################
    
    /**
     * function that prints robot location
     */
    inline void printLoc()
    {
        cout << "Robot: " << this->name;
        coordinate.print();
    }

    /**
     * function that prints cleaning message for a certain robot
     */
    inline void printClean()
    {
        cout << "Robot: " << this->name << " is cleaning";
        coordinate.print();
        cout << "dust bin: " << dust_bin << endl;
    }
    /* function gets the private member name of the robot and sends it to functions.
     as const. */
    inline const string& getName()
    {
        return name;
    }
    /* function gets the private member dust bin of the robot and sends it to functions.
     as const. */
    const int& getBin()
    {
        return dust_bin;
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
    /* function connects between RobotDB class to Coordinate class to change
     coordinates. */
    bool moveCoordinate(std::string& direction, Map* map, bool useMoveBuild);
    /* function connects between RobotDB class to Coordinate class to replace
     coordinates for existing robot. */
    void replaceCoordinates(const int& x, const int& y);
    /* function increments dust bin by one. */
    void growDustBin();
    /* function clears the dust bin completely. */
    void clearDustBin();
    /* function connects between RobotDB to Coordinate classes to retrieve a robots
     X coordinate which is a Coordinate private member. */
    const int getX_coordinate();
    /* function connects between RobotDB to Coordinate classes to retrieve a robots
     Y coordinate which is a Coordinate private member. */
    const int getY_coordinate();
};

#endif
