#pragma once

#include "Stack.hpp"
#include "Cell.hpp"
#include "Map.hpp"

class Tracker{
public:
    Tracker();
    void findPath(Map& map);
    void move();
private:
    Stack <Cell*> history;
    Cell* p_current;
};
