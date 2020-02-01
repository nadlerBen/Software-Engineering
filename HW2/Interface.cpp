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
        if (command == "Place"){
            cin >> robotName;
            cin >> locX;
            cin >> locY;
            pRobots->Place(robotName, locX, locY);
        }
        if (command == "Move"){
            cin >> robotName;
            cin >> direction;
            pRobots->Move(robotName, direction, false); //added usingMoveBuild as false
        }
        if (command == "Delete"){
            cin >> robotName;
            pRobots->DeleteRobot(robotName);
        }
        if (command == "AddDirt"){
            cin >> locX;
            cin >> locY;
            if(!pRobots->isLocationOccuppied(locX, locY)){
                map->addDirt(locX, locY);
            }
        }
        if (command == "AddWall"){
            cin >> locX;
            cin >> locY;
            if(!pRobots->isLocationOccuppied(locX, locY)){
                if(locX >= 0 && locY >= 0){
                map->AddWall(locX, locY);
                }
            }
        }
        if (command == "AddPath"){
            cin >> locX;
            cin >> locY;
            if(locX >= 0 && locY >= 0){
            map->AddPath(locX, locY);
            }
        }
        if (command == "Clean"){
            cin >> robotName;
            pRobots->Clean(robotName);
        }
        if (command == "MoveBuild"){
            cin >> robotName;
            cin >> direction;
            pRobots->moveBuild(robotName, direction, true); //added usingMoveBuild as true
        }
        if (command == "MoveMulti"){
            cin >> robotName;
            cin >> direction;
            while (direction != "end"){
                pRobots->Move(robotName, direction, false); //added usingMoveBuild as false
                cin >> direction;
            }
        }
    }
    
}
