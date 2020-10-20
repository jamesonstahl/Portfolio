#include "Tracker.hpp"

Tracker::Tracker(){
  
}

//Takes in the map and calls the move function to iterate through the map until the end is found
void Tracker::findPath(Map& map){
    p_current = map.getStart();
    while(p_current -> getType() != 'E'){
        move();
    }
}

//Tracker starts at starting cell and systematically selects a direction
//and attempts to move to the cell in that direction
void Tracker::move(){
    //Attempts to move north
    if(p_current -> getNorth() != NULL && (p_current -> getNorth() -> getType() == 'F' || p_current -> getNorth() -> getType() == 'E') && p_current -> getNorth() -> getTraverse() == false){
        history.push(p_current);
        p_current = p_current -> getNorth();
        p_current -> setTraverse(true);
        cout << "Going North X: " << p_current -> getx() << " Y: " << p_current -> gety() << " Type: " << p_current -> getType() << endl;
    }
    //Attempts to move east
    else if(p_current -> getEast() != NULL && (p_current -> getEast() -> getType() == 'F' || p_current -> getEast() -> getType() == 'E') && p_current -> getEast() -> getTraverse() == false){
        history.push(p_current);
        p_current = p_current -> getEast();
        p_current -> setTraverse(true);
        cout << "Going East X: " << p_current -> getx() << " Y: " << p_current -> gety() << " Type: " << p_current -> getType() << endl;
    }
    //Attempts to move south
    else if(p_current -> getSouth() != NULL && (p_current -> getSouth() -> getType() == 'F' || p_current -> getSouth() -> getType() == 'E') && p_current -> getSouth() -> getTraverse() == false){
        history.push(p_current);
        p_current = p_current -> getSouth();
        p_current -> setTraverse(true);
        cout << "Going South X: " << p_current -> getx() << " Y: " << p_current -> gety() << " Type: " << p_current -> getType() << endl;
    }
    //Attempts to move east
    else if(p_current -> getWest() != NULL && (p_current -> getWest() -> getType() == 'F' || p_current -> getWest() -> getType() == 'E') && p_current -> getWest() -> getTraverse() == false){
        history.push(p_current);
        p_current = p_current -> getWest();
        p_current -> setTraverse(true);
        cout << "Going West X: " << p_current -> getx() << " Y: " << p_current -> gety() << " Type: " << p_current -> getType() << endl;
    }
    //The tracker reaches a point where it can not proceed any longer
    //It will backtrack to the previous cell
    else{
        cout << "Backtracking from X: " << p_current -> getx() << " Y: " << p_current -> gety() << " Type: " << p_current -> getType() << " to: X: " << history.top() -> getx() << " Y: " << history.top() -> gety() << " Type: " << history.top() -> getType() << endl;
        p_current -> setDead(true);
        p_current = history.top();
        history.pop();
        move();
    }
}
