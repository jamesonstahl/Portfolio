#include "Cell.hpp"

Cell::Cell(){
    traversed = false;
    deadPath = false;
}

//Sets the north pointer to the passed in cell
void Cell::setN(Cell* north){
    this -> p_north = north;
}

//Sets the east pointer to the passed in cell
void Cell::setE(Cell* east){
    this -> p_east = east;
}

//Sets the west pointer to the passed in cell
void Cell::setW(Cell* west){
    this -> p_west = west;
}

//Sets the south pointer to the passed in cell
void Cell::setS(Cell* south){
    this -> p_south = south;
}

//Returns the cell pointed to by the north pointer
Cell* Cell::getNorth(){
    return this -> p_north;
}

//Returns the cell pointed to by the south pointer
Cell* Cell::getSouth(){
    return this -> p_south;
}

//Returns the cell pointed to by the east pointer
Cell* Cell::getEast(){
    return this -> p_east;
}

//Returns the cell pointed to by the west pointer
Cell* Cell::getWest(){
    return this -> p_west;
}

//Returns the x coordinate
int Cell::getx(){
    return this -> x;
}

//Returns the y coordinate
int Cell::gety(){
    return this -> y;
}

//Assigns the x coordinate to the passed in value
void Cell::setx(int xcord){
    this -> x = xcord;
}

//Assigns the y coordinate to the passed in value
void Cell::sety(int ycord){
    this -> y = ycord;
}

//Returns the type of desired cell
char Cell::getType(){
    return this -> type;
}

//Assigns the type to the desired cell
void Cell::setType(char terrain){
    this -> type = terrain;
}

//Sets traversed to the passed in bool
void Cell::setTraverse(bool tf){
    this -> traversed = tf;
}

//Returns the bool traversed
bool Cell::getTraverse(){
    return this -> traversed;
}

//Assigns the bool to dead path
void Cell::setDead(bool tf){
    this -> deadPath = tf;
}

//Returns the bool dead path
bool Cell::getDead(){
    return this -> deadPath;
}
