#ifndef TILE_H
#define TILE_H

#include <string>
using namespace std;

// Let's define some colors
#define DEFAULT_COLOR "\033[0m"
#define GREEN "\033[;32m"
#define BOLD_GREEN "\033[1;32m"
#define RED "\033[;31m"
#define BOLD_RED "\033[1;31m"
#define YELLOW "\033[;33m"
#define BOLD_YELLOW "\033[1;33m"
#define BLUE "\033[;34m"
#define BOLD_BLUE "\033[1;34m"
#define MAGENTA "\033[;35m"
#define BOLD_MAGENTA "\033[1;35m"
#define CYAN "\033[;36m"
#define BOLD_CYAN "\033[1;36m"
#define WHITE "\033[;37m"
#define BOLD_WHITE "\033[1;37m"

// Let's define some characters for the tiles
#define DEFAULT_REPRESENTATION "X"
#define OCEAN_REPRESENTATION "O"
#define RIVER_REPRESENTATION "|"
#define PLAINS_REPRESENTATION "ж"
#define HILLS_REPRESENTATION "^"
#define MOUNTAINS_REPRESENTATION "Ʌ"
#define EVEREST_REPRESENTATION "A"

// Strings for temperature classification; corresponds to enum below
// this block
#define WATER_COLOR BLUE
#define DEATH_VALLEY_COLOR RED
#define DESSERT_COLOR YELLOW
#define GRASSY_COLOR GREEN
#define SNOW_COLOR WHITE
#define DEEP_SNOW_COLOR BOLD_WHITE
#define ICE_COLOR CYAN

// Temperature classes
enum TEMPERATURE_CLASSES
{
    TEMP_WATER = 0,
    TEMP_DEATH_VALLEY = 1,
    TEMP_DESSERT = 2,
    TEMP_GRASSY = 3,
    TEMP_SNOW = 4,
    TEMP_DEEP_SNOW = 5,
    TEMP_ICE = 6
};

// Geological biomes; determines the geological classifier
enum GEOLOGY_CLASSES
{
    GEO_OCEAN = 0,
    GEO_RIVER = 0,
    GEO_PLAINS = 2,
    GEO_HILLS = 3,
    GEO_MOUNTAINS = 4,
    GEO_EVEREST = 5
};

class Tile
{
private:
    string tileRep;
    string tileColor;
    float temp;
    float humid;
    float elev;    // Elevation
    int geoClass;  // Geology classification
    int tempClass; // Temperature classification

    // Given the elevation, derive the geological classification based on tile height; set appropriate char representation
    void deriveGeologyClass();
    // Set the tile value we should use.
    void setRepresentation(string val);
    // Set the tile character color
    void setColor(string colorValue);

public:
    // Constructor.
    Tile();

    // Obtain the value of the given tile.
    string getRepresentation();
    // Set the temperature value of this tile, color it, classify it.
    void setTemperature(float temperature);
    // Get the temperature value of this tile
    float getTemperature();
    // Set the humidity value of the tile
    void setHumditity(float humidity);
    // Get the humidity value of the tile
    float getHumditity();
    // Set the elevation value of the tile
    void setElevation(float elevation);
    // Get the elevation value of the tile
    float getElevation();
    // Print the tile to screen
    void print();
    // Returns the geological classification (see enum GEOLOGY_CLASSES)
    int getGeologyClass();
    // Returns the temperature classification (see enum TEMPERATURE_CLASSES)
    int getTemperatureClass();
};

#endif