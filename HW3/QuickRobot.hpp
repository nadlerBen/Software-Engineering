#ifndef QuickRobot_hpp
#define QuickRobot_hpp

#include <stdio.h>
#include <string.h>
#include "Robot.h"
#include "RobotDB.hpp"
#include "Coordinate.h"

class QuickRobot:public Robot{
private:
    robot_type type;
    
public:
    QuickRobot(const Coordinate& new_coordinate, const std::string& new_name):
    Robot(new_coordinate, new_name), type(QUICK){}
    virtual ~QuickRobot();
     /* function moves a quick robot */
    virtual void moveRobot(Map* map, std::string direction);
    virtual void print()
    {
        printType(std::string("QUICK"));
    };
    /* function returns the robots type. */
    virtual const robot_type getType(){
        return type;
    }
};

#endif
