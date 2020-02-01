#include "QuickRobot.hpp"

#define OUT_OF_BOUNDS -1

QuickRobot:: ~QuickRobot(){}
/* the virtual function is called on a specific quick robot and gets the desired direction
 * then moves this direction to the Coordinate class function changeCoordinates
 * for further changes. the function checks if the robot hit a wall and if the robot
 * is outside of map limits.
 * if the robot moved out of map limits it goes to -1,-1.
 * @param: direction - the desired direction the robot needs to move to.
 * @param: map - the map with all the info about walls and paths.
 */
void QuickRobot::moveRobot(Map* map, std::string direction){
    
    bool hitWall = false;
    int locX = this->coordinate.get_x(), locY = coordinate.get_y();
    while(map->inMapLimit(coordinate.get_x(), coordinate.get_y()) && !hitWall){
        if(!this->coordinate.changeCoordinates(direction, map)){
            locX = coordinate.get_x();
            locY = coordinate.get_y();
        } else {
            coordinate.set_x(locX);
            coordinate.set_y(locY);
            this->print();
            hitWall = true;
        }
    }
    if(!map->inMapLimit(coordinate.get_x(), coordinate.get_y())){
        this->replaceCoordinates(OUT_OF_BOUNDS, OUT_OF_BOUNDS);
        this->shutDownConnection();
        this->print();
    }
}
