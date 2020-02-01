#include "RobotDB.hpp"

#include <iostream>
#include <string>

#define OUT_OF_BOUNDS -1
#define FULL_BIN 5
#define NOT_FOUND -2
#define NO_LIMIT -1

RobotDB::RobotDB(Map* map): map(map){} //default constructor
RobotDB::~RobotDB(){}
/* function that places a robot in the map with the desired coordinates the user inserted.
 * if the robot exists, only updates his coordinates. else, creates a new robot.
 * @param robotName - a string of the robot name.
 * @param x - the desired x coordinate the robot should be placed.
 * @param y - the desired y coordinate the robot should be placed.
 * @param type - a type of robot.
 */
void RobotDB:: place(std::string robotName, const int x, const int y, const robot_type type){
    int limitedRobotLimit = NO_LIMIT;
    Coordinate* new_coordinate = new Coordinate (x, y);
    if(map->inMapLimit(x, y) && !(map->isWall(x, y))){ //changed- added !map->isWall, check if it works
        if (isRobotExist(robotName)){
            int index = findRobot(robotName);
            if(type == robots[index]->getType()){
                if (type == LIMITED){
                    cin >> limitedRobotLimit;
                    deleteRobot(robots[index]->getName());
                    Robot* new_robot = new QuickLimitedRobot(*new_coordinate, robotName, limitedRobotLimit);
                    robots.push_back(new_robot);
                }
                robots[index]->replaceCoordinates(x, y);
                robots[index]->retrieveConnection();
                robots[index]->print();
            }
        } else if(type == REGULAR){
            Robot* new_robot = new Robot(*new_coordinate, robotName);
            robots.push_back(new_robot);
            new_robot->print();
        } else if(type == STRONG){
            Robot* new_robot = new StrongRobot(*new_coordinate, robotName);
            robots.push_back(new_robot);
            new_robot->print();
        } else if(type == QUICK){
            Robot* new_robot = new QuickRobot(*new_coordinate, robotName);
            robots.push_back(new_robot);
            new_robot->print();
        } else if(type == LIMITED){
            cin >> limitedRobotLimit;
            Robot* new_robot = new QuickLimitedRobot(*new_coordinate, robotName, limitedRobotLimit);
            robots.push_back(new_robot);
            new_robot->print();
        }
        delete new_coordinate;
    }
}

/* function that finds the robot inside the vector, function gets a string of
 * the robots name and then searches for this name in the vector with the help
 * of a function that gets the private member of robot: name.
 * returns an index which indicates the robots place in the vector, else returns
 * NOT_FOUND which is a value defined as -2.
 * @param name - a string containing the robots name.
 */
int RobotDB:: findRobot(const std::string robotName){
    int index = 0;
    RobotVec_it iter_find;
    iter_find = robots.begin();
    while (iter_find != robots.end()){
        if ((*iter_find)->getName() == robotName){
            return index;
        }
        index++;
        iter_find++;
    }
    return NOT_FOUND;
}
/* a function that sends a robot to his respective move function,
 * the function gets the name of the robot and the
 * @param name - a string of the robots name.
 * @param direction - the desired direction the user wants the robot to move to.
 */
void RobotDB:: move(std::string robotName, std::string direction){
    int index = findRobot(robotName);
    if(isRobotExist(robotName)){
        robots[index]->moveRobot(map, direction);
    }
}

/* a function that deletes an existing robot, first checking if a robot with this
 * name exists, if it does exist the function deletes his memory allocation and
 * also deletes him from the robots vector.
 * @param name - a string of a robots name.
 */
void RobotDB:: deleteRobot(std::string robotName){
    if(isRobotExist(robotName)){
        int index = findRobot(robotName);
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
bool RobotDB:: isRobotExist(const std::string robotName)
{
    return (findRobot(robotName) != NOT_FOUND) ? true : false;
}

