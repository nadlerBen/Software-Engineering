#include "QuickLimitedRobot.hpp"

#define OUT_OF_BOUNDS -1
/* default destructor */
QuickLimitedRobot:: ~QuickLimitedRobot(){}

/* a virtual function that moves a quick limited robot. for every step the robot takes
 * the function checks if its in map limits, then moves the robot.
 * the robot keeps moving if it didn't hit a wall, his limit didn't hit 0 and 
 * if he didn't go out of map limits.
 * if the robot moved out of map limits it goes to -1,-1.
 * @param: direction - the desired direction the robot needs to move to.
 * @param: map - the map with all the info about walls and paths.
 */
void QuickLimitedRobot::moveRobot(Map* map, std::string direction){
    
    int locX = this->coordinate.get_x();
    int locY = this->coordinate.get_y();
    int robotLimit = limit;
    int hitWall = false;
    
    while(map->inMapLimit(coordinate.get_x(), coordinate.get_y()) && !hitWall && robotLimit > 0){
        if(!coordinate.changeCoordinates(direction, map)){
            locX = coordinate.get_x();
            locY = coordinate.get_y();
            robotLimit--;
        } else {
            coordinate.set_x(locX);
            coordinate.set_y(locY);
            hitWall = true;
            this->print();
        }
    }
    if(!map->inMapLimit(coordinate.get_x(), coordinate.get_y())){
        this->replaceCoordinates(OUT_OF_BOUNDS, OUT_OF_BOUNDS);
        this->shutDownConnection();
        this->print();
    }
    if(!robotLimit){
        this->print();
    }
}
