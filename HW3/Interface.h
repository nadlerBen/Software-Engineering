#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>

#include "Map.hpp"
#include "RobotDB.hpp"

/**
 * Interface class role is to interface between the user, the map and robotDB module.
 * Receive inputs from user and according to the command, calls the suitable functions from the suitable module
 */
class Interface
{
private:
    RobotDB* pRobots;
    
    const Interface& operator=(const Interface& Robs_control); //Assignment operator
    Interface(const Interface& Robs_control); //Copy constructor

public:
    //Constructors
    Interface(RobotDB* pNew_Robots): pRobots(pNew_Robots){}
    
    //Destructor
    ~Interface(){}
    
    /**
     * function that gets input from the user and calls the suitable function accordingly
     * @param map object representing the map
     */
    void StartControl(Map* map);
};

#endif
