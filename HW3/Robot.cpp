#include <stdio.h>
#include <iostream>
#include <string>
#include "Robot.h"

#define OUT_OF_BOUNDS -1

using namespace std;
Robot:: ~Robot(){}
/* the virtual function is called on a specific regular robot and gets the desired direction
 * then moves this direction to the Coordinate class function changeCoordinates
 * for further changes. the function checks if the robot hit a wall and if the robot
 * is outside of map limits.
 * @param: direction - the desired direction the robot needs to move to.
 * @param: map - the map with all the info about walls and paths.
 */
void Robot::moveRobot(Map* map, std::string direction){
    int locX = coordinate.get_x();
    int locY = coordinate.get_y();
    if (!this->coordinate.changeCoordinates(direction, map)){
        if(map->inMapLimit(this->coordinate.get_x(), this->coordinate.get_y())){
                this->print();
        }
    } else{
        coordinate.set_x(locX);
        coordinate.set_y(locY);
        this->print();
    }
    if(!map->inMapLimit(this->coordinate.get_x(), this->coordinate.get_y())){
        this->replaceCoordinates(OUT_OF_BOUNDS, OUT_OF_BOUNDS);
        this->shutDownConnection();
        this->print();
    }
}
/* function that connectes RobotDB with Coordinate classes.
 * function is called on a specific robot and gets the desired x,y new coordinate
 * then moves those x,y to the Coordinate class function replaceExistingCoordinate.
 * @param x - new x coordinate the existing robot needs to move to.
 * @param y - new y coordinate the existing robot needs to move to.
 */
void Robot:: replaceCoordinates(const int& x, const int& y)
{
    coordinate.replaceExisitingCoordinates(x, y);
}
