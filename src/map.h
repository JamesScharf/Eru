#ifndef MAP_H
#define MAP_H

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <math.h>
#include "tile.h"
#include "FastNoiseLite.h"
using namespace std;

class Map
{
private:
    vector<vector<Tile>> tileMap;
    int height = 0;
    int width = 0;

public:
    // Constructor. Sets up tileMap size.
    Map(int xSize, int ySize);
    // Set the tilemap at location x,y with tile of type Tile
    void setTile(int x, int y, Tile value);
    // Obtain the tile object here
    Tile getTileAt(int x, int y);
    // Generate the height map
    void generateHeightMap();
    // Creates temperatures for a tile based on X, Y, Z
    void generateTemperatureMap();
    //Gets the X size of the map
    int getWidth();
    // Gets the Y size of the map
    int getHeight();
    // Print the map as-is for viewing purposes
    void print();
};

#endif