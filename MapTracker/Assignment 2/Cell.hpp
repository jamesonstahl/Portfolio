#pragma once

class Cell{
public:
    Cell();
    void setN(Cell* north);
    void setE(Cell* east);
    void setW(Cell* west);
    void setS(Cell* south);
    Cell* getNorth();
    Cell* getSouth();
    Cell* getEast();
    Cell* getWest();
    int getx();
    int gety();
    void setx(int xcord);
    void sety(int ycord);
    char getType();
    void setType(char terrain);
    void setTraverse(bool tf);
    bool getTraverse();
    void setDead(bool tf);
    bool getDead();
private:
    int x;
    int y;
    bool traversed;
    bool deadPath;
    char type;
    Cell* p_north;
    Cell* p_east;
    Cell* p_west;
    Cell* p_south;
};
