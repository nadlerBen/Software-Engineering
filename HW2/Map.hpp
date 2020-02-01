#ifndef Map_hpp
#define Map_hpp

#include <iostream>
#include <string>
#include <stdio.h>
#define DEFAULT_SIZE 7
class Map
{
private:
    typedef int size_type;
    typedef int** grid_type;
    grid_type ppGrid;
    size_type size_h;
    size_type size_w;
public:
    //Constructor
    Map();
    
    //Destructor
    ~Map(){}
    
    /* function checks if a robot is in maps limits. */
	bool inMapLimit(const int x, const int y);
    /* function changes the requested location into a wall if possible. */
    void AddWall(const int x, const int y);
    /* function chancged the requested location into a path. */
    void AddPath(const int x, const int y);
    /* function checks if requested location is a wall. */
    bool isWall(const int x, const int y);
    /* function resizes the map to fit coordinates requested by the user when adding
     path or wall. */
    void updateMap(const int& x, const int& y, int PathOrWall);
    /* function checks if a location is dirty. */
    bool isLocationDirty(const int x, const int y);
    /* function cleans the requested location. */
    void cleanMap(const int x, const int y);
    /* function adds dirt at requested location if possible. */
    void addDirt(const int x, const int y);
    /* function destroys a wall and puts a 0 instead. */
    void destroyWall(const int x, const int y);
};

#endif
