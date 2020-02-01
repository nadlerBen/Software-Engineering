#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Prints robot new location
 * @param robotName: robot's name
 * @param locX: x coordinate
 * @param locY: y coordinate
 */
inline void PrintRobotPlace(const string& robotName, int locX, int locY )
{
    cout << "Robot: " << robotName << " at: " << locX << "," << locY << endl;
}

/*
 * Prints cleaning
 * @param robotName: robot's name
 * @param locX: x coordinate
 * @param locY: y coordinate
 */
inline void PrintClean(const string& robotName, int locX, int locY )
{
    cout << "Robot: " << robotName << " clean: " << locX << "," << locY << endl;
}

/*
 * Prints cleaning
 */
inline void PrintTable(vector<string> robots, vector<int> ranks, vector<int> tankCounter )
{
	cout << "==========\nRank Table:" << endl;;
	for (vector<string>::size_type i = 0; i != robots.size (); i++)
		cout << "Robot: " << robots[i] << ", rank: " << ranks[i] << ", dirt-tank: " << tankCounter[i] << std::endl;
}
#endif
