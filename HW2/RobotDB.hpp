#ifndef RobotDB_hpp
#define RobotDB_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Map.hpp"
#include "Robot.h"
#include "Coordinate.h"

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
    ~RobotDB(){}
    //Assignment operator
    const RobotDB& operator=(const RobotDB& Robs_DB);
    
    /* function places a robot in a requested location. */
    void Place(std::string robotName, const int x, const int y);
    /* function deletes a robot. */
    void DeleteRobot(std::string name);
    /* function cleans at the location the robot is in. */
    void Clean(std::string name);
    /* function finds the location of a robot inside the robots vector. */
    int findRobot(const std::string name);
    /* function moves a robot to a requested location if possible. */
    void Move(std::string name, std::string direction, bool usingMoveBuild); //changed- added usingMoveBuild
    /* function checks if a robot with this name already exists. */
    bool isRobotExist(const std::string name);
    /* function checks if a location is already occupied by a robot. */
    bool isLocationOccuppied(const int x, const int y);
    /* function moves a robot to a location with a wall and destroys the wall. */
    void moveBuild(std::string name, std::string direction, bool usingMoveBuild); //changed- added usingMoveBuild
};
#endif
