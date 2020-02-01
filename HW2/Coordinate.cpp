#include <stdio.h>
#include "Coordinate.h"
#include <iostream>
#include <string>

/*
 * function gets a direction and moves the robot to the correct location requested
 * by the user. if the new location is a wall the robot goes back to the previous
 * location. if the user requested move-build function then the robot moves to the wall
 * and destroys it.
 * @param: direction - the desired direction the robot needs to move to.
 * @param: map - the map with all the info about walls and paths.
 * @param: useMoveBuild - boolian type which tells us if the user called regular move
 * function or move-build function.
 */
bool Coordinate:: changeCoordinates(std::string& direction, Map* map, bool useMoveBuild){
    if (direction == "U"){
        int new_x = --x;
        if(map->inMapLimit(new_x, y) && map->isWall(new_x, y)){
            if(useMoveBuild){
                map->destroyWall(new_x, y);
            }
            else x++;
        }
    }
    if (direction == "D"){
        int new_x = ++x;
        if(map->inMapLimit(new_x, y) && map->isWall(new_x, y)){
            if(useMoveBuild){
                map->destroyWall(new_x, y);
            }
            else x--;
        }
    }
    if (direction == "L"){
        int new_y = --y;
        if(map->inMapLimit(x, new_y) && map->isWall(x, new_y)){
            if(useMoveBuild){
                map->destroyWall(x, new_y);
            }
            else y++;
        }
    }
    if (direction == "R"){
        int new_y = ++y;
        if(map->inMapLimit(x, new_y) && map->isWall(x, new_y)){
            if(useMoveBuild){
                map->destroyWall(x, new_y);
            }
            else y--;
        }
    }
    if (direction == "UR"){
        int new_x = --x, new_y = ++y;
        if(map->inMapLimit(new_x, new_y) && map->isWall(new_x, new_y)){
            if(useMoveBuild){
                map->destroyWall(new_x, new_y);
            }
            else{
                x++;
                y--;
            }
        }
    }
    if (direction == "UL"){
        int new_x = --x, new_y = --y;
        if(map->inMapLimit(new_x, new_y) && map->isWall(new_x, new_y)){
            if(useMoveBuild){
                map->destroyWall(new_x, new_y);
            }
            else{
                x++;
                y++;
            }
        }
    }
    if (direction == "DR"){
        int new_x = ++x, new_y = ++y;
        if(map->inMapLimit(new_x, new_y) && map->isWall(new_x, new_y)){
            if(useMoveBuild){
                map->destroyWall(new_x, new_y);
            }
            else{
                x--;
                y--;
            }
        }
    }
    if (direction == "DL"){
        int new_x = ++x, new_y = --y;
        if(map->inMapLimit(new_x, new_y) && map->isWall(new_x, new_y)){
            if(useMoveBuild){
                map->destroyWall(new_x, new_y);
            }
            else{
                x--;
                y++;
            }
        }
    }
    if (map->inMapLimit(x, y)){
        return true;
    }
    return false;
}
/* function gets new coordinates to replace with the old ones for an existing robot.
 * @param new_x - the new x coordinate that the existing robot is going to move to.
 * @param new_y - the new y coordinate that the existing robot is going to move to.
 */
void Coordinate:: replaceExisitingCoordinates(const int& new_x, const int& new_y)
{
    x = new_x;
    y = new_y;
}
