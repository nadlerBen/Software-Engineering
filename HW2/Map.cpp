#include "Map.hpp"
#include <iostream>
#include <string>
#define DEFAULT_SIZE 7
#define CLEAN_PATH 0
#define WALL 1
#define DIRTY 2

/* initiallization of map constructor. */
Map::Map(): size_h(DEFAULT_SIZE), size_w(DEFAULT_SIZE)
{
    int grid[DEFAULT_SIZE][DEFAULT_SIZE] =
    {
        { 0 , 1 , 1 , 1 , 1 , 1 , 1},
        { 1 , 2 , 2 , 0 , 1 , 0 , 1},
        { 0 , 0 , 1 , 1 , 1 , 2 , 1},
        { 1 , 0 , 0 , 0 , 0 , 0 , 1},
        { 1 , 1 , 1 , 2 , 1 , 0 , 1},
        { 1 , 0 , 0 , 0 , 0 , 2 , 1},
        { 1 , 0 , 1 , 1 , 1 , 1 , 1}
    };
    ppGrid = new int*  [DEFAULT_SIZE];
    for (int i = 0; i < DEFAULT_SIZE; i++){
        ppGrid[i] = new int [DEFAULT_SIZE];
        for (int j = 0; j < DEFAULT_SIZE; j++){
            ppGrid[i][j] = grid[i][j];
        }
    }
}
/* adds a wall in a desired location, function will be called only if a robot
 * is not in this location.
 * @param x - desired x coordinate to put a wall in.
 * @param y - desired y coordinate to put a wall in.
 */
void Map:: AddWall (const int x, const int y)
{
    if (inMapLimit(x, y)){
        ppGrid[x][y] = 1;
    }
    else{
        updateMap(x, y, WALL);
    }
}
/* adds a path in a desired location, function will be called only if a robot
 * is not in this location. function doesnt add a path if location is dirty
 * because dirty location is already a path.
 * @param x - desired x coordinate to put a wall in.
 * @param y - desired y coordinate to put a wall in.
 */
void Map:: AddPath(const int x, const int y)
{
    if (inMapLimit(x, y)){
        if(!isLocationDirty(x, y) && isWall(x, y)){
            ppGrid[x][y] = 0;
        }
    }
    else{
        updateMap(x, y, CLEAN_PATH);
    }
}
    //*checks if the given robot is within our map limits
    //variables- const int x- x coordinate
    //           const int y- y coordinate
    //return- returns true if the robot is in the map limits, else return false. */
bool Map:: inMapLimit(const int x, const int y)
{
    if (x >= 0 && x<size_h && y >= 0 && y<size_w)
        return true;
    else
        return false;
}
/* function checks if desired location is a wall, returns true if it is. false if its not.
 * @param x - desired x coordinate to check a wall in.
 * @param y - desired y coordinate to check a wall in.
 */
bool Map:: isWall(const int x, const int y)
{
    if (ppGrid[x][y] == 1){
        return true;
    }
    return false;
}
/* function checks if desired location is dirty, returns true if it is. false if its not.
 * @param x - desired x coordinate to check if dirty.
 * @param y - desired y coordinate to check if dirty.
 */
bool Map:: isLocationDirty(const int x, const int y)
{
    if (ppGrid[x][y] == 2){
        return true;
    }
    return false;
}
/* function cleans the desired location. function is called only if x,y in map limits.
 * @param x - desired x coordinate to clean.
 * @param y - desired y coordinate to clean.
 */
void Map:: cleanMap(const int x, const int y)
{
    ppGrid[x][y] = 0;
}
/* adds dirt in a desired location, function will be called only if a robot
 * is not in this location. only if x,y is in map limits.
 * @param x - desired x coordinate to put dirt in.
 * @param y - desired y coordinate to put dirt in.
 */
void Map:: addDirt(const int x, const int y)
{
    if (inMapLimit(x, y) && !isWall(x, y)){
        ppGrid[x][y] = 2;
    }
}
/* function destroys a wall in a desired location, first checks if the x,y
 * that were requested are in the map and if theres a wall there. if there is
 * it destroys the wall.
 * @param x - desired x coordinate to destroy wall in.
 * @param y - desired y coordinate to destroy wall in.
 */
void Map:: destroyWall(const int x, const int y)
{
    if(inMapLimit(x, y) && isWall(x, y)){
        ppGrid[x][y] = 0;
    }
}
/* function is called if the user requests to add a path or a wall in
 * a location further than the map can reach.
 * the function saves the old map size and then resizes it to fit the coordinates
 * the user inserted. after allocating a new array the function adds walls in all
 * locations and a wall or a path in the desired location the user inserted.
 * then the function gets the old map info and places them in their old location
 * with the help of the temp variables we made.
 * at the end the function copies the new map to ppGrid and deletes the memory of the 
 * new one. now ppGrid has the new map.
 * @param x - the desired x coordinate to put a path or wall in.
 * @param y - the desired y coordinate to put a path or wall in.
 * @param PathOrWall - gets 0 or 1 from the addPath or addWall function so we can
 * know what the user wanted to place in the desired location.
 */
void Map:: updateMap(const int& x, const int& y, int PathOrWall)
{
    size_type temp_h = size_h;
    size_type temp_w = size_w;
    
    if(x >= size_h && y < size_w){
        size_h = x + 1;
    }
    else if(x < size_h && y >= size_w){
        size_w = y + 1;
    }
    else if(x >= size_h && y >= size_w){
        size_h = x + 1;
        size_w = y + 1;
    }
    
    grid_type new_map = new int * [size_h];
    for(int i = 0; i < size_h; i++){
        new_map[i] = new int [size_w];
    }
    for(int i = 0; i < size_h; i++){
        for(int j = 0; j < size_w; j++){
            if(i == x && j == y){
                new_map[i][j] = PathOrWall;
            }
            else new_map[i][j] = WALL;
        }
    }
    for(int i = 0; i < temp_h; i++){
        for(int j = 0; j < temp_w; j++){
            new_map[i][j] = ppGrid[i][j];
        }
    }
        //////// changed- added memory deletion of old map, removed the line "delete [] new_map;"
    for(int i = 0; i < temp_h; i++){
        delete [] ppGrid[i];
    }
    delete [] ppGrid;
        ////////
    ppGrid = new_map;
    /* delete [] new_map; */
}
