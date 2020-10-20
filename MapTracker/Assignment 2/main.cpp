#include <iostream>
#include "Stack.hpp"
#include "Cell.hpp"
#include "Map.hpp"
#include "Tracker.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    //create a map from a file
    Map map("/Users/jameson/Downloads/3x3map.txt");
    
    //create a tracker capable of traversing through a map
    Tracker tracker;

    //send the tracker to find a path through the map
    tracker.findPath(map);
     
    //print the original cells from the file
    map.printCells();
    
    //print an X/O map from the start to the end
    map.printRoute();

    return 0;
}
