#include "tile.hpp"
#include <stdlib.h>
#include <iostream>

//executables of the class functions defined in tile.hpp

tile::tile(){
    pos = 15;
    piecePos[0] = pos;
    int rotation = 0;
    //chooses a random type of tile, then according to that type forms the initial piecePos[] array
    this->type = rand() %7;
    switch(this->type){
        case 0:
            piecePos[1] = pos-2;
            piecePos[2] = pos-1;
            piecePos[3] = pos+1;
            break;
        case 1:
            piecePos[1] = pos-1;
            piecePos[2] = pos+9;
            piecePos[3] = pos+10;
            break;
        case 2:
            piecePos[1] = pos-1;
            piecePos[2] = pos+1;
            piecePos[3] = pos+11;
            break;
        case 3:
            piecePos[1] = pos-1;
            piecePos[2] = pos+1;
            piecePos[3] = pos+9;
            break;
        case 4:
            piecePos[1] = pos+1;
            piecePos[2] = pos+9;
            piecePos[3] = pos+10;
            break;
        case 5:
            piecePos[1] = pos-1;
            piecePos[2] = pos+1;
            piecePos[3] = pos+10;
            break;
        case 6:
            piecePos[1] = pos-1;
            piecePos[2] = pos+10;
            piecePos[3] = pos+11;
            break;
    }
}

tile::~tile(){}

//calculates new position of all pieces of the tile when turning 90* with the this->pos tile as turning point
void tile::rotate(){
    this->rotation++;
    this->rotation %= 4;
    if (this->type != 1){
        int xOffset, yOffset;
        for (int i = 1; i < 4; i++){
            xOffset = (piecePos[i]-piecePos[0])%10;
            yOffset = (piecePos[i]-piecePos[0]-xOffset)/10;
            piecePos[i] = xOffset*10 - yOffset + piecePos[0];
            //std::cout<<std::endl<<xOffset<<" "<<yOffset;
        }
    }
}

//functions to move tile 1 space down, left and right
void tile::moveLeft(){
    for (int i = 0; i < 4; i++){
        piecePos[i] = piecePos[i] -1;
    }
}
void tile::moveRight(){
    for (int i = 0; i < 4; i++){
        piecePos[i] += 1;
    }
}
void tile::moveDown(){
    for (int i = 0; i < 4; i++){
        piecePos[i] += 10;
    }
}