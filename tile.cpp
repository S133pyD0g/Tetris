#include "tile.hpp"
#include <stdlib.h>
#include <iostream>

//executables of the class functions defined in tile.hpp

tile::tile(){
    piecePos[0] = 5;
    int rotation = 0;
    //chooses a random type of tile, then according to that type forms the initial piecePos[] array
    this->type = rand() %7;
    switch(this->type){
        case 0:
            piecePos[1] = piecePos[0]-2;
            piecePos[2] = piecePos[0]-1;
            piecePos[3] = piecePos[0]+1;
            break;
        case 1:
            piecePos[1] = piecePos[0]-1;
            piecePos[2] = piecePos[0]+9;
            piecePos[3] = piecePos[0]+10;
            break;
        case 2:
            piecePos[1] = piecePos[0]-1;
            piecePos[2] = piecePos[0]+1;
            piecePos[3] = piecePos[0]+11;
            break;
        case 3:
            piecePos[1] = piecePos[0]-1;
            piecePos[2] = piecePos[0]+1;
            piecePos[3] = piecePos[0]+9;
            break;
        case 4:
            piecePos[1] = piecePos[0]+1;
            piecePos[2] = piecePos[0]+9;
            piecePos[3] = piecePos[0]+10;
            break;
        case 5:
            piecePos[1] = piecePos[0]-1;
            piecePos[2] = piecePos[0]+1;
            piecePos[3] = piecePos[0]+10;
            break;
        case 6:
            piecePos[1] = piecePos[0]-1;
            piecePos[2] = piecePos[0]+10;
            piecePos[3] = piecePos[0]+11;
            break;
    }
}

tile::~tile(){}

//calculates new position of all pieces of the tile when turning 90* with the piecePos[0] tile as turning point
void tile::rotate(){
    this->rotation++;
    this->rotation %= 4;
    int xOffset, yOffset;
    if (this->type != 1){
    for (int i = 1; i < 4; i++){
        xOffset = piecePos[i]%10 -piecePos[0]%10;
        yOffset = (piecePos[i]-piecePos[0]-xOffset)/10;
        int newPos = xOffset*10 - yOffset + piecePos[0];
        if(piecePos[0]%10 - yOffset < 0 || piecePos[0]%10 - yOffset > 9 || newPos > 199 || newPos < 0){
            std::cout<<"can't rotate";
            return;
        }
    }
    for (int i = 1; i < 4; i++){
        xOffset = piecePos[i]%10 -piecePos[0]%10;
        yOffset = (piecePos[i]-piecePos[0]-xOffset)/10;
        piecePos[i] = xOffset*10 - yOffset + piecePos[0];
        //std::cout<<std::endl<<xOffset<<" "<<yOffset;
    }
    }
}

//functions to move tile 1 space down, left and right
void tile::moveLeft(){
    for( int i = 0; i < 4; i++){
        if(piecePos[i]%10-1<0){
            std::cout<<"can't move left";
            return;
        }
    }
    for (int i = 0; i < 4; i++){
        piecePos[i] = piecePos[i] -1;
    }
}
void tile::moveRight(){
    for( int i = 0; i < 4; i++){
        if(piecePos[i]%10+1>9){
            std::cout<<"can't move right";
            return;
        }
    }
    for (int i = 0; i < 4; i++){
        piecePos[i] += 1;
    }
}
void tile::moveDown(){
    for( int i = 0; i < 4; i++){
        if(piecePos[i] + 10 > 199){
            std::cout<<"can't move down";
            return;
        }
    }
    for (int i = 0; i < 4; i++){
        piecePos[i] += 10;
    }
}