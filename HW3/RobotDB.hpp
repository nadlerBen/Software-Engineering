#ifndef RobotDB_hpp
#define RobotDB_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Map.hpp"
#include "Robot.h"
#include "Coordinate.h"
#include "StrongRobot.hpp"
#include "QuickRobot.hpp"
#include "QuickLimitedRobot.hpp"

class RobotDB
{
private:
    typedef std::vector<Robot*> RobotVec;
    typedef std::vector<Robot*>::iterator RobotVec_it;
    typedef std::vector<Robot*>::const_iterator RobotVec_cit;
    RobotVec robots;
    Map* map;
    
public:
        //Constructor
    RobotDB(Map* new_map);
        //Destructor
    ~RobotDB();
        //Assignment operator
    const RobotDB& operator=(const RobotDB& Robs_DB);
    
    /* function places a robot in a requested location. */
    void place(std::string robotName, const int x, const int y, const robot_type type);
    /* function deletes a robot. */
    void deleteRobot(std::string name);
    /* function finds the location of a robot inside the robots vector. */
    int findRobot(const std::string name);
    /* function moves a robot to a requested location if possible. */
    void move(std::string name, std::string direction);
    /* function checks if a robot with this name already exists. */
    bool isRobotExist(const std::string name);
};
#endif

