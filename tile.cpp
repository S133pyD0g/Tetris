#include "tile.hpp"
#include <stdlib.h>

//executables of the class functions defined in tile.hpp

tile::tile(){
    int pos = 0;
    int rotation = 0;
    //chooses a random type of tile, then according to that type forms the initial piecePos[] array
    this->type = rand() %7;
    switch(this->type){
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
    }
}

tile::~tile(){}

//calculates new position of all pieces of the tile when turning 90* with the this->pos tile as turning point
void tile::rotate(){
    this->rotation++;
    this->rotation %= 4;
    int xOffset, yOffset;
    for (int i = 1; i < 4; i++){
        xOffset = (piecePos[i]-this->pos)%10;
        yOffset = (piecePos[i]-this->pos+xOffset)/10;
        piecePos[i] = xOffset*10 - yOffset + this->pos;
        //std::cout<<xOffset<<" "<<yOffset<<std::endl;
    }
    
}