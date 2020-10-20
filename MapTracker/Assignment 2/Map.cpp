#include "Map.hpp"
#include <iostream>
#include <fstream>
#include <string>

//Reads in the map shape from the inputed file and constructs a linked list by connecting the cells
 Map::Map(string pathToMapFile){
     ifstream mapFile;
     char line;
     mapFile.open(pathToMapFile);
     //Reads in map file to find the number of cells and compute the dimension
     if(mapFile.is_open()){
         while(mapFile >> line){
             //mapFile >> line;
             numCells++;
         }
         mapFile.close();
         dimension  = sqrt(numCells);
     }
     else{
         cout << "Unable to open file" << endl;
         exit(0);
     }
     //Creates a dynamic array of cells
     p_allCells = new Cell*[numCells];
     for(int i = 0; i < numCells; i++){
         p_allCells[i] = new Cell;
    }
     //Reads in file again and assigns the cell type
     mapFile.open(pathToMapFile);
     if(mapFile.is_open()){
         for(int i = 0; i < numCells; i++){
             mapFile >> line;
             p_allCells[i] -> setType(line);
         }
         mapFile.close();
         //Assigns x and y values to each cell
         int x = 0;
         for(int i = 0; i < dimension; i++){
             for(int j = 0; j < dimension; j++){
                 if(i == 0 && j == 0){
                    p_topLeft = p_allCells[x];
                 }
                 p_allCells[x] -> setx(j);
                 p_allCells[x] -> sety(i);
                 x++;
             }
         }
     }
     else{
         cout << "Unable to open file" << endl;
         exit(0);
     }
     //Links each cell to the cell to the east
     for(int i = 0; i < numCells; i++){
         if(p_allCells[i] -> getx() < (dimension - 1)){
             p_allCells[i]->setE(p_allCells[i + 1]);
         }
         else{
             p_allCells[i]->setE(NULL);
         }
         if(p_allCells[i]->getType() == 'S'){
             startCell = p_allCells[i];
             startCell -> setTraverse(true);
         }
     }
     //Links each cell to the cell to the north
     for(int i = 0; i < numCells; i++){
         if(p_allCells[i] -> gety() > 0){
             p_allCells[i]->setN(p_allCells[i - dimension]);
         }
         else{
             p_allCells[i]->setN(NULL);
         }
         if(p_allCells[i]->getType() == 'S'){
             startCell = p_allCells[i];
             startCell -> setTraverse(true);
         }
     }
     //Links each cell to the cell to the west
     for(int i = 0; i < numCells; i++){
         if(p_allCells[i] -> getx() > 0){
             p_allCells[i]->setW(p_allCells[i - 1]);
         }
         else{
             p_allCells[i]->setW(NULL);
         }
         if(p_allCells[i]->getType() == 'S'){
             startCell = p_allCells[i];
             startCell -> setTraverse(true);
         }
     }
     //Links each cell to the cell to the south
     for(int i = 0; i < numCells; i++){
         if(p_allCells[i] -> gety() < (dimension - 1)){
             p_allCells[i]->setS(p_allCells[i + dimension]);
         }
         else{
             p_allCells[i]->setS(NULL);
         }
         if(p_allCells[i]->getType() == 'S'){
             startCell = p_allCells[i];
             startCell -> setTraverse(true);
         }
     }
 }

//Destructor class deletes all cells and deletes the dynamic array to prevent a memory leak
Map::~Map(){
    for(int i = numCells - 1; i > 0; i--){
        numCells--;
        delete p_allCells[i];
        p_allCells[i] = NULL;
    }
    delete [] p_allCells;
    p_allCells = NULL;
}

//Prints each cell to create the map
void Map::printCells(){
    Cell* p_row = p_topLeft;
    while(p_row != 0){
        Cell* p_col = p_row;
        while(p_col != 0){
            cout << p_col -> getType() << " ";
            p_col = p_col -> getEast();
        }
        p_row = p_row -> getSouth();
        cout << endl;
    }
    cout << endl;
}

//Prints the route from start to finish
void Map::printRoute(){
    Cell* p_row = p_topLeft;
    while(p_row != 0){
        Cell* p_col = p_row;
        while(p_col != 0){
            if((p_col -> getDead() == true) || (p_col -> getType() == 'B') || (p_col -> getTraverse() == false)){
                cout << "X ";
            }
            else{
                cout << "O ";
            }
            
            p_col = p_col -> getEast();
        }
        p_row = p_row -> getSouth();
        cout << endl;
    }
    cout << endl;
}

//Returns the start cell
Cell* Map::getStart(){
    return startCell;
}

