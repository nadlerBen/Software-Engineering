#include <cstdlib>
#include <iostream>
#include <string>

#include "Interface.h"
#include "RobotDB.hpp"
#include "Map.hpp"


int main(int argc, char *argv[])
{
    Map* map = new Map(); 
    RobotDB* pRobots = new RobotDB(map);
    Interface control(pRobots);
    
    control.StartControl(map);
      
    delete pRobots;
    delete map;
    
    return EXIT_SUCCESS;
}
