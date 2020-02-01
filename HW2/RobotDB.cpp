#include "RobotDB.hpp"
#include <iostream>
#include <string>
#define OUT_OF_BOUNDS -1
#define FULL_BIN 5
#define NOT_FOUND -2

RobotDB::RobotDB(Map* map): map(map){} //default constructor

/* function that places a robot in the map with the desired coordinates the user inserted.
 * if the robot exists, only updates his coordinates. else, creates a new robot.
 * @param robotName - a string of the robot name.
 * @param x - the desired x coordinate the robot should be placed.
 * @param y - the desired y coordinate the robot should be placed.
 */
void RobotDB:: Place(std::string robotName, const int x, const int y)
{
    if(map->inMapLimit(x, y) && !(map->isWall(x, y))){
        if (isRobotExist(robotName)){
            int index = findRobot(robotName);
            robots[index]->replaceCoordinates(x, y);
            robots[index]->retrieveConnection();
            robots[index]->printLoc();
        }
        else{
            Coordinate* new_coordinate = new Coordinate (x, y);
            Robot* new_robot = new Robot (*new_coordinate, robotName, 0, COMMUNICABLE);
            robots.push_back(new_robot);
            delete new_coordinate;
            new_robot->printLoc();
        }
    }
}

/* function that finds the robot inside the vector, function gets a string of
 * the robots name and then searches for this name in the vector with the help
 * of a function that gets the private member of robot: name.
 * returns an index which indicates the robots place in the vector, else returns
 * NOT_FOUND which is a value defined as -2.
 * @param name - a string containing the robots name.
 */
int RobotDB:: findRobot(const std::string name)
{
    int index = 0;
    RobotVec_it iter_find;
    iter_find = robots.begin();
    while (iter_find != robots.end()){
        if ((*iter_find)->getName() == name){
            return index;
        }
        index++;
        iter_find++;
    }
    return NOT_FOUND;
}

/* a function that moves a robot, the function gets the name of the robot and the
 * desired direction to move into, then finds the specific robot by his name.
 * to prevent from move-multi to move a robot in an undefined location we first check
 * the robots current location. if robot is inside the map limits we call functions
 * that move the robot to the desired location, if movement maintained the robot
 * in map limits we print a successful movement.
 * else, if the robot is out of the limits we set him to -1,-1, shut down his connenction
 * and print that he is in -1,-1.
 * @param name - a string of the robots name.
 * @param direction - the desired direction the user wants the robot to move to.
 * @param usingMoveBuild - a boolian variable that determines if we use the moveBuild
 * function or not.
 */
void RobotDB:: Move(std::string name, std::string direction, bool usingMoveBuild) //changed- added usingMoveBuild
{
    bool useMoveBuild = usingMoveBuild; //changed useMoveBuild gets usingMoveBuild instead of false
    int index = findRobot(name);
    if(isRobotExist(name)){
        
        int robotX = robots[index]->getX_coordinate();
        int robotY = robots[index]->getY_coordinate();
        if (map->inMapLimit(robotX, robotY)){
            if(robots[index]->moveCoordinate(direction, map, useMoveBuild)){
                robots[index]->printLoc();
            }
        }
        robotX = robots[index]->getX_coordinate();
        robotY = robots[index]->getY_coordinate();
        if(!map->inMapLimit(robotX, robotY)){
            robots[index]->replaceCoordinates(OUT_OF_BOUNDS, OUT_OF_BOUNDS);
            robots[index]->shutDownConnection();
            robots[index]->printLoc();
        }
    }
}
/* a function that cleans a location the robot is in. first we check if the robot is
 * in the map limits. if it is, we first check if the robots dust bin is full to prevent
 * him from further cleaning if his dust bin his full. if its full, the robot is moved
 * to 0,0 and his dust bin is cleared entirely.
 * else, if the dust bin is not full we check if the robots location is dirty,
 * if its dirty the robot cleans it, his dust bin grows by one and we print a successful
 * cleaning message.
 * @param name - a string of the robots name.
 */
void RobotDB:: Clean(std::string name)
{
    int index = findRobot(name);
    if(isRobotExist(name)){
        int robotX = robots[index]->getX_coordinate();
        int robotY = robots[index]->getY_coordinate();
        if (map->inMapLimit(robotX, robotY)){
            if (robots[index]->getBin() == FULL_BIN){
                robots[index]->replaceCoordinates(0, 0);
                robots[index]->clearDustBin();
            }
            else if(map->isLocationDirty(robotX, robotY)){  //changed- from if to else if
                map->cleanMap(robotX, robotY);
                robots[index]->growDustBin();
                robots[index]->printClean();
            }
        }
    }
}

/* a function that deletes an existing robot, first checking if a robot with this
 * name exists, if it does exist the function deletes his memory allocation and
 * also deletes him from the robots vector.
 * @param name - a string of a robots name.
 */
void RobotDB:: DeleteRobot(std::string name)
{
    if(isRobotExist(name)){
        int index = findRobot(name);
        delete robots[index];
        robots.erase(robots.begin() + index);
    }
}

/* function that checks if a robot already exist.
 * function calls findRobot to prevent copying the same code.
 * if findRobot found a robot then we return true, a robot exist.
 * if it returns false then a this robot does not exist.
 * @param name - a string of robots name.
 */
bool RobotDB:: isRobotExist(const std::string name)
{
    return (findRobot(name) != NOT_FOUND) ? true : false;
}
/* a function that checks if there a robot in a desired location.
 * function gets the x,y coordinates of every robots in the vector
 * then checks if its equal to the x,y coordinates recieved by the user.
 * if it found a robot in this location returns true, if a robot is not occupying
 * this location then it returns false.
 * @param x - the x coordinate we want to check if is occupied.
 * @param y - the y coordinate we want to check if is occupied.
 */
bool RobotDB:: isLocationOccuppied(const int x, const int y)
{
    RobotVec_cit iter_coordinate;
    
    for(iter_coordinate = robots.begin(); iter_coordinate != robots.end(); iter_coordinate++){
        int temp_x = (*iter_coordinate)->getX_coordinate();
        int temp_y = (*iter_coordinate)->getY_coordinate();
        
        if (temp_x == x && temp_y == y){
            return true;
        }
    }
    return false;
}
/* a function that moves a robot, the function gets the name of the robot and the
 * desired direction to move into, then finds the specific robot by his name.
 * if robot is inside the map limits we call functions
 * that move the robot to the desired location, if movement maintained the robot
 * in map limits we print a successful movement. if there was a wall in this
 * location we destroy it and move the robot to this location.
 * else, if the robot is out of the limits we set him to -1,-1, shut down his connenction
 * and print that he is in -1,-1.
 * @param name - a string of the robots name.
 * @param direction - the desired direction the user wants the robot to move to.
 * @param usingMoveBuild - a boolian variable that determines if we use the moveBuild
 * function or not.
 */
void RobotDB:: moveBuild(std::string name, std::string direction, bool usingMoveBuild) ////changed- added usingMoveBuild
{
    bool useMoveBuild = usingMoveBuild; //changed- got rid of copied code
    Move(name, direction, useMoveBuild);
    /* int index = findRobot(name);
    bool useMoveBuild = true;
    if(isRobotExist(name)){
        int robotX = robots[index]->getX_coordinate();
        int robotY = robots[index]->getY_coordinate();
        if(map->inMapLimit(robotX, robotY)){
            if(robots[index]->moveCoordinate(direction, map, useMoveBuild))
            {
                robots[index]->printLoc();
            }
        }
        robotX = robots[index]->getX_coordinate();
        robotY = robots[index]->getY_coordinate();
        if(!map->inMapLimit(robotX, robotY))
        {
            robots[index]->replaceCoordinates(OUT_OF_BOUNDS, OUT_OF_BOUNDS);
            robots[index]->shutDownConnection();
            robots[index]->printLoc();
        }
    } */
}
