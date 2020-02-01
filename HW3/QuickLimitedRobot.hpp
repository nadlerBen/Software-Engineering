#ifndef QuickLimitedRobot_hpp
#define QuickLimitedRobot_hpp

#include <stdio.h>
#include <string.h>
#include "Robot.h"
#include "RobotDB.hpp"
#include "Coordinate.h"

class QuickLimitedRobot:public Robot{
private:
    int limit;
    robot_type type;
public:
    QuickLimitedRobot(const Coordinate& new_coordinate, const std::string& new_name, int limit):
    Robot(new_coordinate, new_name), limit(limit), type(LIMITED){}
    
    virtual ~ QuickLimitedRobot();
    virtual void print()
    {
        printType(std::string("LIMITED"));
    };
    /* function moves a quick limited robot */
    virtual void moveRobot(Map* map, std::string direction);
    /* function returns the robots type. */
    virtual const robot_type getType(){
        return type;
    }
};
#endif
