#include <stdio.h>
#include "Coordinate.h"
#include <iostream>
#include <string>

/*
 * function gets a direction and moves the robot to the correct location requested
 * by the user. if the new location is a wall function returns true.
 * else, if the robot didn't hit a wall return false.
 * @param: direction - the desired direction the robot needs to move to.
 * @param: map - the map with all the info about walls and paths.
 */
bool Coordinate:: changeCoordinates(std::string& direction, Map* map){
    if (direction == "U"){
        --x;
        if(map->inMapLimit(x, y) && map->isWall(x, y)){
            return true;
        }
    }
    if (direction == "D"){
        ++x;
        if(map->inMapLimit(x, y) && map->isWall(x, y)){
            return true;
        }
    }
    if (direction == "L"){
        --y;
        if(map->inMapLimit(x, y) && map->isWall(x, y)){
            return true;
        }
    }
    if (direction == "R"){
        ++y;
        if(map->inMapLimit(x, y) && map->isWall(x, y)){
            return true;
        }
    }
    if (direction == "UR"){
        --x;
        ++y;
        if(map->inMapLimit(x, y) && map->isWall(x, y)){
            return true;
        }
    }
    if (direction == "UL"){
        --x;
        --y;
        if(map->inMapLimit(x, y) && map->isWall(x, y)){
            return true;
        }
    }
    if (direction == "DR"){
        ++x;
        ++y;
        if(map->inMapLimit(x, y) && map->isWall(x, y)){
            return true;
        }
    }
    if (direction == "DL"){
        ++x;
        --y;
        if(map->inMapLimit(x, y) && map->isWall(x, y)){
            return true;
        }
    }
    return false;
}
/* function gets new coordinates to replace with the old ones for an existing robot.
 * @param new_x - the new x coordinate that the existing robot is going to move to.
 * @param new_y - the new y coordinate that the existing robot is going to move to.
 */
void Coordinate:: replaceExisitingCoordinates(const int& new_x, const int& new_y){
    x = new_x;
    y = new_y;
}

