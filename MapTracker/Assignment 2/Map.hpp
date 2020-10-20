#pragma once

#include "Cell.hpp"
#include <string>

using namespace std;

class Map{
public:
    Map(string pathToMapFile);
    ~Map();
    void printCells();
    void printRoute();
    Cell* getStart();
private:
    Cell* startCell;
    Cell* p_topLeft;
    int numCells;
    int dimension;
    Cell** p_allCells;
};
