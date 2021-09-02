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
    // Create a default tile
    Tile defaultTile = Tile();
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

/**
 * Applies a height value to each Tile
 * 
 */
void Map::generateHeightMap()
{
    FastNoiseLite noise;
    noise.SetFrequency(0.05);
    srand(time(NULL));
    int seed = rand() % 1000 + 1;
    noise.SetSeed(seed);

    FastNoiseLite noise2;
    noise2.SetFrequency(0.05);
    srand(time(NULL));
    int seed2 = rand() % 1000 + 1;
    noise2.SetSeed(seed);
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float n = noise.GetNoise((float)h, (float)w);
            float n2 = noise2.GetNoise((float)h, (float)w) / 50;
            tileMap.at(h).at(w).setElevation(n + n2);
        }
    }
}

/**
 * Generates Tile temperature based on X, Y, and elevation
 * 
 */
void Map::generateTemperatureMap()
{
    FastNoiseLite noise;
    noise.SetFrequency(0.04);
    srand(time(NULL));
    int seed = rand() % 1000 + 1;
    noise.SetSeed(seed);

    int equator = height / 2;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float elevation = tileMap.at(h).at(w).getElevation();
            float n = noise.GetNoise((float)w, (float)h, elevation);
            float temp = elevation + (n / 50);

            tileMap.at(h).at(w).setTemperature(temp);
        }
    }
}