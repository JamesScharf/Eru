#include "map.h"
#include "tile.h"
#include <iostream>
using namespace std;

/**
 * Build a blank canvas of blank Tile objects.
 * @brief Construct a new Map:: Map object
 * 
 * @param xSize The width of the map canvas
 * @param ySize The height of the map canvas
 */
Map::Map(int xSize, int ySize)
{
    height = ySize;
    width = xSize;
    Tile defaultTile = Tile(0);
    for (int x = 0; x < xSize; x++)
    {
        // Build the row up first
        vector<Tile> row(xSize, defaultTile);
        tileMap.push_back(row);
    }
}

/**
 * Sets the tilemap at x,y to value.
 * 
 * @param x 
 * @param y 
 * @param value 
 */
void Map::setTile(int x, int y, Tile value)
{
    tileMap[x][y] = value;
}

/**
 * Get the tile at location x,y
 * 
 * @param x 
 * @param y 
 * @return Tile 
 */
Tile Map::getTileAt(int x, int y)
{
    return tileMap[x][y];
}

int Map::getWidth()
{
    return width;
}

int Map::getHeight()
{
    return height;
}

/**
 * Print the map for viewing purposes.
 * 
 */
void Map::print()
{
    for (vector<Tile> row : tileMap)
    {
        for (Tile t : row)
        {
            t.print();
        }
        cout << "\n";
    }
}