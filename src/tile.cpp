#include "tile.h"
#include <iostream>
using namespace std;

/**
 * Construct a new Tile:: Tile object
 * 
 * @param startingTemp The initial temperature of a given tile.
 */
Tile::Tile(int startingTemp)
{
    setTemperature(startingTemp);
    setRepresentation('X');
}

/**
 * Set the char representation of this tile.
 * 
 * @param val 
 */
void Tile::setRepresentation(char val)
{
    tileRep = val;
}

/**
 * Obtain the tile representation (char).
 * 
 * @return char The character that represents this tile
 */
char Tile::getRepresentation()
{
    return tileRep;
}

/**
 * Set the temperature of the tile.
 * 
 * @param temperature
 * @return int 
 */
void Tile::setTemperature(int temperature)
{
    temp = temperature;
}

/**
 * Get the temperature of the tile.
 * 
 * @return int 
 */
int Tile::getTemperature()
{
    return temp;
}

/**
 * Print the tile char representation to screen
 * 
 */
void Tile::print()
{
    cout << getRepresentation();
}