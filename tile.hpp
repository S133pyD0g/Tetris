//tile class definition

#pragma once
#include <iostream>

class tile
{
    public:
    int pos ;
    int rotation;
    int type;
    bool cage[9];

    tile();
    ~tile();
    void rotate();

};