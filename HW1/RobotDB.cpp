#include "RobotDB.h"
#include <vector>
#include <string>
#define R_HIGHT 7
#define R_WIDTH 7
#define FULL_TANK 5

std::vector<std::string>::const_iterator iter_find;
std::vector<std::string>::const_iterator iter_exist;

    //placing a robot function, puts values to the correct vectors if the coordinates the
    //user enetered are inside the map.
    //printing a successful placement of a robot
/*
 * places a robot in x, y coordinates, puts the values in the correct vector.
 * @param name: name of the robot
 * @param x: x cooridnate
 * @param y: y coordinate
 * @param robots: vector of robots name
 * @param location_x: vector of x cooridnates of robots
 * @param location_y: vector of y cooridnates of robots
 * @param robotRank: vector of robot ranks
 * @param tankCounter: vector of tank capacities of robots
 */
void Place(std::string name, int x, int y, vector<string>& robots, vector<int>& location_x, vector<int>& location_y,
           vector<int>& robotRank, vector<int>& tankCounter)
{
    if (inMapLimit(x, y))
    {
        if (isRobotExist(name, robots))
        {
            int index = findRobot(name, robots);
            location_x[index] = x;
            location_y[index] = y;
        }
        else /* if (!isRobotExist(name, robots)) */
        {
            robots.push_back(name);
            location_x.push_back(x);
            location_y.push_back(y);
            robotRank.push_back(0);
            tankCounter.push_back(0);
        }
        PrintRobotPlace(name, x, y);
    }
}
    //deleting a robot function, deletes all values related to the name of the robot
    //in all related vectors.
/*
 * @param name: name of a robot
 * @param robots: vector of robot names
 * @param location_x: vector of x coordinates
 * @param location_y: vector of y coordinates
 * @param robotRank: vector of robot ranks
 * @param tankCounter: vector of counters for tank capacity
 */
void Delete(std::string name, vector<string>& robots, vector<int>& location_x, vector<int>& location_y,
            vector<int>& robotRank, vector<int>& tankCounter)
{
    int index = findRobot(name, robots);

    robots.erase(robots.begin() + index);
    location_x.erase(location_x.begin() + index);
    location_y.erase(location_y.begin() + index);
    robotRank.erase(robotRank.begin() + index);
    tankCounter.erase(tankCounter.begin() + index);
}
    //moving a robots location, gets a direction from the user and changes the coordinates
    //of the robot to the correct location by changing his coordinates in the x and y
    //coordinate vectors.
    //also printing a successful moving message.
    //
    //if robot is outside of bound after movement, doesnt print a successful message
    //if robot is out of bounds while in a movemulti function,
    //put the robot at (-1, -1)
/*
 * @param name: name of a robot
 * @param robots: vector of robot names
 * @param direction: a direction recieved from the user
 * @param location_x: vector of x coordinates
 * @param location_y: vector of y coordinates
 */
void Move(std::string name, vector<string>& robots, std::string direction,
		vector<int>& location_x,
          vector<int>& location_y)
{
    int index = findRobot(name, robots);

    if (inMapLimit(location_x[index], location_y[index]))
    {
        if (direction == "U" && index >= 0)
        {
            location_x[index]--;
        }
        if (direction == "D" && index >= 0)
        {
            location_x[index]++;
        }
        if (direction == "L" && index >= 0)
        {
            location_y[index]--;
        }
        if (direction == "R" && index >= 0)
        {
            location_y[index]++;
        }
        if (direction == "UR" && index >= 0)
        {
            location_x[index]--;
            location_y[index]++;
        }
        if (direction == "UL" && index >= 0)
        {
            location_x[index]--;
            location_y[index]++;
        }
        if (direction == "DR" && index >= 0)
        {
            location_x[index]++;
            location_y[index]++;
        }
        if (direction == "DL" && index >= 0)
        {
            location_x[index]++;
            location_y[index]--;
        }
        if (!inMapLimit(location_x[index], location_y[index]))
        {
            location_x[index] = -1;
            location_y[index] = -1;
            PrintRobotPlace(robots[index], location_x[index], location_y[index]);
        }
        else
            PrintRobotPlace(robots[index], location_x[index], location_y[index]);
    }
}
/*
 * finds the name of the robot in the robots name vector
 * counts the place of the robot in the vector
 * this index will help us locate the information related to this specific robot
 * in other vectors. all information about a specific robot is stored in different
 * vectors but with the same index.
 * @param name: name of the robot
 * @param robots: vector of robot names
 */
int findRobot(std::string name, vector<string>& robots)
{
    int index = 0;
    iter_find = robots.begin();
    while (iter_find != robots.end())
    {
        if (*iter_find == name)
        {
            return index;
        }
        index++;
        iter_find++;
    }
    return -1;
}
/*
 * checks if the capacity of the dirt tank is full (5).
 * @param name: name of the robot
 * @param robots: vector of robot names
 * @param tankCounter: vector of tank counters for the robots.
 */
bool isTankFull(std::string name, vector<string>& robots, vector<int>& tankCounter)
{
    int index = findRobot(name, robots);
    if (tankCounter[index] == FULL_TANK)
    {
        return true;
    }
    else return false;
}
/*
 * checks if a robot with this name already exists.
 * @param name: name of the robot
 * @param robots: vector of robot names
*/
bool isRobotExist(std::string name, vector<string>& robots)
{
    iter_exist = robots.begin();
    while (iter_exist != robots.end())
    {
        if (*iter_exist == name)
        {
            return true;
        }
        iter_exist++;
    }
    return false;
}

