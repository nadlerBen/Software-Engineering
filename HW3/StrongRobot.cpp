#include "StrongRobot.hpp"
#include <string.h>
#define OUT_OF_BOUNDS -1
/* default destructor */
StrongRobot::~StrongRobot(){}
/* a virtual function that moves a strong robot. for every step the robot takes
 * the function checks if its in map limits, then moves the robot.
 * if the robot hit a wall it destroys it and increments the wall break counter
 * by 1. if the robot broke one wall it stops moving.
 * if the robot moved out of map limits it goes to -1,-1.
 * @param: direction - the desired direction the robot needs to move to.
 * @param: map - the map with all the info about walls and paths.
 */
void StrongRobot::moveRobot(Map* map, std::string direction){
    wallBreakCounter = 0;
    while(map->inMapLimit(this->coordinate.get_x(), this->coordinate.get_y()) && !wallBreakCounter){
        if(this->coordinate.changeCoordinates(direction, map)){
            map->destroyWall(this->coordinate.get_x(), this->coordinate.get_y());
            wallBreakCounter++;
            this->print();
        }
    }
    if(!map->inMapLimit(this->coordinate.get_x(), this->coordinate.get_y())){
        this->replaceCoordinates(OUT_OF_BOUNDS, OUT_OF_BOUNDS);
        this->shutDownConnection();
        this->print();
    }
    wallBreakCounter--;
}
