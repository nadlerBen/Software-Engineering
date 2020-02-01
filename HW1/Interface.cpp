#include <iostream>
#include <string>
#include <vector>
#include "Interface.h"
#include "RobotDB.h"
#include "map.h"

using namespace std;

    //declaring vectors for name, x and y coordinates, robot rank and tank capacity.
std::vector<std::string> robots;
std::vector<int> location_x;
std::vector<int> location_y;
std::vector<int> robotRank;
std::vector<int> tankCounter;

    //controls the input from the user and sends it to the functions, at the end after
    //the input is done, prints the rank table.
void StartControl()
{
    string commands, robotName, direction;
    int locX, locY;
    cout << "Start entering commands:" << endl;
    while (cin >> commands)
    {
        if (commands == "Place")
        {
            cin >> robotName;
            cin >> locX;
            cin >> locY;
            Place(robotName, locX, locY, robots, location_x, location_y, robotRank,
                  tankCounter);
        }
        if (commands == "Delete")
        {
            cin >> robotName;
            Delete(robotName, robots, location_x, location_y, robotRank,
                   tankCounter);

        }
        if (commands == "Move")
        {
            cin >> robotName;
            cin >> direction;
            Move(robotName, robots, direction, location_x, location_y);
        }
        if (commands == "AddDirt")
        {
            cin >> locX;
            cin >> locY;
            if (!isLocationOccupied(locX, locY, location_x, location_y))
            {
                addDirt(locX, locY);
            }
        }
        if (commands == "Clean")
        {
            cin >> robotName;
            Clean(robotName, robots, location_x, location_y, robotRank, tankCounter);
        }
        if (commands == "MoveMulti")
        {
            cin >> robotName;
            cin >> direction;
            while (direction != "end")
            {
                Move(robotName, robots, direction, location_x, location_y);
                cin >> direction;
            }
        }
    }
    PrintTable(robots, robotRank, tankCounter);
}
