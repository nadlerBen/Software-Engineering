#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Interface.h"


using namespace std;
/* function gets commands from the user and sends them to the correct functions.
 * @param map - holds all the information about walls and paths.
 */
void Interface:: StartControl(Map* map)
{
    std::string direction, command, robotName;
    int locX, locY;
    while (cin >> command){
        if (command == "PlaceRegularRobot"){
            cin >> robotName;
            cin >> locX;
            cin >> locY;
            pRobots->place(robotName, locX, locY, REGULAR);
        }
        if (command == "PlaceQuickRobot"){
            cin >> robotName;
            cin >> locX;
            cin >> locY;
            pRobots->place(robotName, locX, locY, QUICK);
        }
        if (command == "PlaceQuickLimitedRobot"){
            cin >> robotName;
            cin >> locX;
            cin >> locY;
            pRobots->place(robotName, locX, locY, LIMITED);
        }
        if (command == "PlaceStrongRobot"){
            cin >> robotName;
            cin >> locX;
            cin >> locY;
            pRobots->place(robotName, locX, locY, STRONG);
        }
        if (command == "Move"){
            cin >> robotName;
            cin >> direction;
            pRobots->move(robotName, direction);
        }
        if (command == "Delete"){
            cin >> robotName;
            pRobots->deleteRobot(robotName);
        }
        if (command == "AddWall"){
            cin >> locX;
            cin >> locY;
                if(locX >= 0 && locY >= 0){
                    map->AddWall(locX, locY);
                }
        }
        if (command == "AddPath"){
            cin >> locX;
            cin >> locY;
            if(locX >= 0 && locY >= 0){
                map->AddPath(locX, locY);
            }
        }
        if (command == "MoveMulti"){
            cin >> robotName;
            cin >> direction;
            while (direction != "end"){
                pRobots->move(robotName, direction);
                cin >> direction;
            }
        }
    }
    
}
