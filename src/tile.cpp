#include "tile.h"
#include <iostream>

/**
 * Construct a new Tile:: Tile object
 * 
 */
Tile::Tile()
{
    // Default temperature, elevation and humidity is 0.5
    setTemperature(0.99);
    setHumditity(0.5);
    setElevation(0.5); // Sea level (?)
}

/**
 * Set the char representation of this tile.
 * 
 * @param val 
 */
void Tile::setRepresentation(string val)
{
    tileRep = val;
}

/**
 * Obtain the tile representation (char).
 * 
 * @return char The character that represents this tile
 */
string Tile::getRepresentation()
{
    return tileRep;
}

/**
 * Get the temperature of the tile.
 * 
 * @return int 
 */
float Tile::getTemperature()
{
    return temp;
}

/**
 * Set the humidity of the tile.
 * 
 * @param humidity 
 */
void Tile::setHumditity(float humidity)
{
    humid = humidity;
}

/**
 * Get the humidity of the tile.
 * 
 * @return float 
 */
float Tile::getHumditity()
{
    return humid;
}

/**
 * Set the elevation (height) of the tile.
 * 
 * @param elevation 
 */
void Tile::setElevation(float elevation)
{
    elev = elevation;
    deriveGeologyClass();
}

/**
 * Returns the elevation of the tile.
 * 
 * @return float 
 */
float Tile::getElevation()
{
    return elev;
}

/**
 * Derives the current geological classification.
 * Sets the char representation
 * 
 */
void Tile::deriveGeologyClass()
{
    if (elev < 0.2)
    {
        geoClass = GEO_OCEAN;
        setRepresentation(OCEAN_REPRESENTATION);
    }
    if (elev >= 0.2 && elev < 0.3)
    {
        geoClass = GEO_RIVER;
        setRepresentation(RIVER_REPRESENTATION);
    }
    if (elev >= 0.3 && elev < 0.6)
    {
        geoClass = GEO_PLAINS;
        setRepresentation(PLAINS_REPRESENTATION);
    }
    if (elev >= 0.6 && elev < 0.8)
    {
        geoClass = GEO_HILLS;
        setRepresentation(HILLS_REPRESENTATION);
    }
    if (elev >= 0.8 && elev < 0.95)
    {
        geoClass = GEO_MOUNTAINS;
        setRepresentation(MOUNTAINS_REPRESENTATION);
    }
    if (elev >= 0.95)
    {
        geoClass = GEO_EVEREST;
        setRepresentation(EVEREST_REPRESENTATION);
    }
}

/**
 * Returns int code of tiles geology, see GEOLOGY to decode
 * 
 * @return int 
 */
int Tile::getGeologyClass()
{
    return geoClass;
}

/**
 * Classifies the tile into temperature class by its temp.
 * Also assigns the tile a color.
 * RUN deriveGeologyClass() FIRST
 * 
 */
void Tile::setTemperature(float temperature)
{
    temp = temperature;
    if (temp <= 0.08)
    {
        tempClass = TEMP_DEATH_VALLEY;
        setColor(DEATH_VALLEY_COLOR);
    }
    if (temp > 0.08 && temp <= 0.2)
    {
        tempClass = TEMP_DESSERT;
        setColor(DESSERT_COLOR);
    }
    if (temp > 0.2 && temp <= 0.7)
    {
        tempClass = TEMP_GRASSY;
        setColor(GRASSY_COLOR);
    }
    if (temp > 0.7 && temp <= 0.85)
    {
        tempClass = TEMP_SNOW;
        setColor(SNOW_COLOR);
    }
    if (temp > 0.85 && temp <= 0.95)
    {
        tempClass = TEMP_DEEP_SNOW;
        setColor(DEEP_SNOW_COLOR);
    }
    if (temp > 0.95)
    {
        tempClass = TEMP_ICE;
        setColor(ICE_COLOR);
    }
}

/**
 * Sets the color of the tile, given a linux color value
 * 
 * @param colorValue 
 */
void Tile::setColor(string colorValue)
{
    tileColor = colorValue;
}

/**
 * Get the temperature class.
 * 
 * @return int 
 */
int Tile::getTemperatureClass()
{
    return tempClass;
}

/**
 * Print the tile char representation to screen
 * 
 */
void Tile::print()
{
    cout << tileColor;
    cout << getRepresentation();
    cout << "\033[0";
}