#ifndef StrongRobot_hpp
#define StrongRobot_hpp

#include <stdio.h>
#include <string.h>
#include "Robot.h"
#include "RobotDB.hpp"
#include "Coordinate.h"

class StrongRobot:public Robot{
private:
    int wallBreakCounter;
    robot_type type;
public:
    StrongRobot(const Coordinate& new_coordinate, const string& new_name):
    Robot(new_coordinate, new_name), wallBreakCounter(0), type(STRONG){}
    virtual ~StrongRobot();
    virtual void print()
    {
        printType(std::string("STRONG"));
    };
    /* function moves a strong robot */
    virtual void moveRobot(Map* map, std::string direction);
    /* function returns the robots type. */
    virtual const robot_type getType(){
        return type;
    }
};
#endif
