#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include "RobotDB.h"
#include "Printer.h"
#include "Interface.h"

using namespace std;

/** Add a dirt to the map, meaning place 1 at x,y location
 * @param x: x coordinate
 * @param y: y coordinate
 */
void addDirt(const int x, const int y);

/**
 * Check if x,y coordinates is valid. valid - if the coordinates in the map is in the map limits.
 * @param x: x coordinate
 * @param y: y coordinate
 * @return: True if the if coordinates are valid, false otherwise.
 */
bool inMapLimit (int x, int y);

/** Cleans a coordinate in the map, meaning place 0 at x,y location
 * @param name: the robot's name
 * @param robotName: vector of all of the robots names
 * @param location_x: vector of all of the x coordinates
 * @param location_y: vector of all of the y coordinates
 * @param robotRank: vector of all of the robots ranks
 * @param tankCounter: vector of all all the robots tanks
 */
void Clean(string name, vector<string>& robotName,
		vector<int>& location_x, vector<int>& location_y,
 vector<int>& robotRank, vector<int>& tankCounter);

/* checks if the coordinate is dirty
* @param x: x coordinate
* @param y: y coordinate
* @return: true if the coordinate is dirty, else- false
*/
bool isLocationDirty(int x, int y);

/* checks if there is already a robot in the requested position
* @param x: x location
* @param y: y location
* @param location_x: vector of all of the x coordinates
* @param location_y: vector of all of the y coordinates
* @return: true if there is already a robot, else-false
*/
bool isLocationOccupied(const int x, const int y,
                        vector<int>& location_x, vector<int>& location_y);

#endif
