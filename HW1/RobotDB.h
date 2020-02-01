#ifndef RobotDB_hpp
#define RobotDB_hpp

#include <vector>
#include <string>
#include "Printer.h"
#include "Interface.h"
#include "map.h"

using namespace std;

/*checking if the robot exist and if its position is within the map limits,
if so-updates its new location, othewise- creates a new robot and places it in the map.
accordingly prints a succcessful placement or out of bounds */
void Place(string name, int x, int y, vector<string>& robotName,
		vector<int>& location_x, vector<int>& location_y,
           vector<int>& robotRank, vector<int>& tankCounter);

/*deleteting the robot with all of its related information*/
void Delete(string name, vector<string>& robots, vector<int>& location_x
		, vector<int>& location_y,
            vector<int>& robotRank, vector<int>& tankCounter);

/*moving the robot as requested and printing the new position,
if the robot current position is out of bound-printing out of bound and moving
it to (-1,-1). */
void Move(string name, vector<string>& robots, std::string direction,
		vector<int>& location_x,
          vector<int>& location_y);

/*checking the robot's tank- if it's full-return true,
else return false.*/
bool isTankFull(std::string name, vector<string>& robots, vector<int>& tankCounter);

/*finding the specific robot in the robots vector and returns its index*/
int findRobot(string name, vector<string>& robots);

/*checking if a robot with identical name is already exists-returns true if ther is
one, else returns false*/
bool isRobotExist(std::string name, vector<string>& robots);

#endif
