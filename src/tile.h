#ifndef TILE_H
#define TILE_H

class Tile
{
private:
    char tileRep;
    int tileColor;
    int temp;

public:
    // Constructor.
    Tile(int startingTemp);
    // Set the tile value we should use.
    void setRepresentation(char val);
    // Obtain the value of the given tile.
    char getRepresentation();
    // Set the temperature value of this tile
    void setTemperature(int temperature);
    // Get the temperature value of this tile
    int getTemperature();
    // Print the tile to screen
    void print();
};

#endif