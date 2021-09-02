// main.cpp
#include <iostream>
#include "tile.h"
#include "map.h"

int main()
{
    Map m = Map(100, 100);
    m.print();
    cout << "\nApplying noise now...\n\n\n\n\n"
         << endl;
    m.generateHeightMap();
    m.generateTemperatureMap();
    m.print();
    return 0;
}