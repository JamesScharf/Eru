#ifndef MAP_H
#define MAP_H

#include <vector>
#include "tile.h"

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
    // Generate the map
    void generateMap();
    //Gets the X size of the map
    int getWidth();
    // Gets the Y size of the map
    int getHeight();
    // Print the map as-is for viewing purposes
    void print();
};

#endif