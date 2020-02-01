#include <stdio.h>
#include <iostream>
#include <string>
#include "Robot.h"

using namespace std;
/* initiallization of Robot constructor. */
Robot::Robot(const Coordinate& new_coordinate, const std::string& new_name, int new_bin,
      connection_e connection): coordinate(new_coordinate), name(new_name), dust_bin(new_bin),
con(connection) {} //default constructor for robot

/* function that connects RobotDB with Coordinate classes.
 * function is called on a specific robot and gets the desired direction
 * then moves this direction to the Coordinate class function changeCoordinates
 * for further changes.
 * @param: direction - the desired direction the robot needs to move to.
 * @param: map - the map with all the info about walls and paths.
 * @param: useMoveBuild - boolian type which tells us if the user called regular move
 * function or move-build function.
 */
bool Robot:: moveCoordinate(std::string& direction, Map* map, bool useMoveBuild)
{
    if(coordinate.changeCoordinates(direction, map, useMoveBuild)){
        return true;
    }
    return false;
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
/* function gets the private member x from the coordinate class. */
const int Robot:: getX_coordinate()
{
    int new_x;
    new_x =  coordinate.get_x();
    return new_x;
}
/* function gets the private member y from the coordinate class. */
const int Robot:: getY_coordinate()
{
    int new_y;
    new_y =  coordinate.get_y();
    return new_y;
}
/* function increments the dust bin by one. */
void Robot:: growDustBin()
{
    dust_bin++;
}
/* function clears the dust bin completely. */
void Robot:: clearDustBin()
{
    dust_bin = 0;
}
