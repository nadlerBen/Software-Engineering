#include <iostream>
#include "map.h"
#include <string>

#define S_HIGH (7) // define the numbers of rows
#define S_WIDTH (7) // define the numbers of columns

using namespace std;

int gmap [S_HIGH][S_WIDTH] =
{
    { 0 , 1 , 1 , 1 , 1 , 1 , 1},
    { 1 , 0 , 0 , 0 , 1 , 0 , 1},
    { 0 , 0 , 1 , 1 , 1 , 0 , 1},
    { 1 , 0 , 0 , 0 , 0 , 0 , 1},
    { 1 , 1 , 1 , 0 , 1 , 0 , 1},
    { 1 , 0 , 0 , 0 , 0 , 0 , 1},
    { 1 , 0 , 1 , 1 , 1 , 1 , 1}
} ;

/**
 * ###################### Module functions ######################
 */
    //adds dirt to the map
void addDirt(const int x, const int y)
{
    if (inMapLimit(x,y))
        gmap[x][y]=1;
}
    //####################################################################################################
    //checks if the loaction of the robot is inside the map.
    //if it is: checks if the location of the robot is dirty,
    //then cleans the location
    //also adding 1 to the tank capacity and rank and
    //prints a successful cleaning message
    //checks if the tank capacity is full, if it is full: placing the robot at 0,0
    //and removing the tank from the tank making the capacity 0 again.
    //printing a successful movement for the robot.
void Clean(string name, vector<string>& robots, vector<int>& location_x,
		vector<int>& location_y,
           vector<int>& robotRank, vector<int>& tankCounter)
{
    int index = findRobot(name, robots);
    int x = location_x[index], y = location_y[index];
    if (inMapLimit(x, y))
    {
        if (isLocationDirty(x, y))
        {
            gmap[x][y] = 0;
            tankCounter[index]++;
            robotRank[index]++;
            PrintClean(robots[index], x, y);
        }
        else
        {
        	tankCounter[index]++;
        	PrintClean(robots[index], x, y);
        }
        if (isTankFull(name, robots, tankCounter))
        {
            x = 0;
            y = 0;
            tankCounter[index] = 0;
            PrintRobotPlace(robots[index], x, y);
        }
    }
}
    //####################################################################################################
    //checks if the current coordinates are inside the map
bool inMapLimit (const int x, const int y)
{
	if (x>=0 && x<S_HIGH && y>=0 && y<S_WIDTH)
		return true;
	else
		return false;
}
    //checks if the current location of the robot is dirty
bool isLocationDirty(int x, int y)
{
    if (gmap[x][y] == 1)
    {
        return true;
    }
    else return false;
}
    //checks if the location we want to put dirt in is occupied by a robot
bool isLocationOccupied(const int x, const int y,
                        vector<int>& location_x, vector<int>& location_y)
{
    vector<int>::const_iterator iter_x;
    vector<int>::const_iterator iter_y;
    iter_x = location_x.begin();
    iter_y = location_y.begin();

    while (iter_x != location_x.end() && iter_y != location_y.end())
    {
        if (x == *iter_x && y == *iter_y)
        {
            return true;
        }
        iter_x++;
        iter_y++;
    }
    return false;
}

