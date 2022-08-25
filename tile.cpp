#include "tile.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>

//executables of the class functions defined in tile.hpp

//constructor
tile::tile(){
    pos[0] = 5;
    int rotation = 0;
    //chooses a random type of tile, then according to that type forms the initial pos[] array
    srand(time(NULL));
    this->type = rand() %7;
    switch(this->type){
        case 0:
            pos[1] = pos[0]-2;
            pos[2] = pos[0]-1;
            pos[3] = pos[0]+1;
            break;
        case 1:
            pos[1] = pos[0]-1;
            pos[2] = pos[0]+9;
            pos[3] = pos[0]+10;
            break;
        case 2:
            pos[1] = pos[0]-1;
            pos[2] = pos[0]+1;
            pos[3] = pos[0]+11;
            break;
        case 3:
            pos[1] = pos[0]-1;
            pos[2] = pos[0]+1;
            pos[3] = pos[0]+9;
            break;
        case 4:
            pos[1] = pos[0]+1;
            pos[2] = pos[0]+9;
            pos[3] = pos[0]+10;
            break;
        case 5:
            pos[1] = pos[0]-1;
            pos[2] = pos[0]+1;
            pos[3] = pos[0]+10;
            break;
        case 6:
            pos[1] = pos[0]-1;
            pos[2] = pos[0]+10;
            pos[3] = pos[0]+11;
            break;
    }
}

//destructor
tile::~tile(){}

//calculates new position of all pieces of the tile when turning 90* with the piecePos[0] tile as turning point
void tile::rotate(bool board[200]){
    this->rotation++;
    this->rotation %= 4;
    int xOffset, yOffset;
    if (this->type != 1){
        for (int i = 1; i < 4; i++){
            xOffset = pos[i]%10 -pos[0]%10;
            yOffset = (pos[i]-pos[0]-xOffset)/10;
            int newPos = xOffset*10 - yOffset + pos[0];
            if(pos[0]%10 - yOffset < 0 || pos[0]%10 - yOffset > 9 || newPos > 199 || newPos < 0 || board[newPos]){
                //std::cout<<"can't rotate";
                return;
            }
        }
        for (int i = 1; i < 4; i++){
            xOffset = pos[i]%10 -pos[0]%10;
            yOffset = (pos[i]-pos[0]-xOffset)/10;
            pos[i] = xOffset*10 - yOffset + pos[0];
            //std::cout<<std::endl<<xOffset<<" "<<yOffset;
        }
    }
}

//move tile one space to the left
void tile::moveLeft(bool board[200]){
    for( int i = 0; i < 4; i++){
        if(pos[i]%10-1<0||board[pos[i]-1]){
            //std::cout<<"can't move left";
            return;
        }
    }
    for (int i = 0; i < 4; i++){
        pos[i] = pos[i] -1;
    }
}

//move tile one space to the right
void tile::moveRight(bool board[200]){
    for( int i = 0; i < 4; i++){
        if(pos[i]%10+1>9||board[pos[i]+1]){
            //std::cout<<"can't move right";
            return;
        }
    }
    for (int i = 0; i < 4; i++){
        pos[i] += 1;
    }
}

//move tile one space down
void tile::moveDown(){
    for (int i = 0; i < 4; i++){
        pos[i] += 10;
    }
}

//collisionCheck on previous tiles and the bottom of the board
bool tile::collisionCheck(bool board[200]){
    for(int i = 0; i < 4; i++){
        if(board[pos[i]+10]||pos[i]+10>=200){
            return true;
        }
    }
    return false;
}