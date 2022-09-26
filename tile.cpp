#include "tile.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>

//executables of the class functions defined in tile.hpp

//constructor
tile::tile(int type){
    pos[0] = 5;
    int rotation = 0;
    this->type = type;
    //gets a random type for a tile, then according to that type forms the initial pos[] array
    switch(type){
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
bool tile::rotate(bool board[200]){
    this->rotation++;
    this->rotation %= 4;
    if (this->type != 1){
        //collision checks for normal rotation first, if collision is detected it checks for one space to the bottom, left and right
        //and gives a corresponding offset  value on to the rotation execution
        int i;
        bool x;
        int xOffset, yOffset;
        for(i = 0; i < 11; i++){
            //std::cout<<std::endl<<i<<" "<<x<<" "<<pos[0]<<std::endl;
            x = false;
            for(int j = 0; j < 4; j++){
                xOffset = pos[j]%10 -pos[0]%10;
                yOffset = (pos[j]-pos[0]-xOffset)/10;
                int newPos = xOffset*10 - yOffset + pos[0] + i;
                if(pos[0]%10 - yOffset + i%10 < 0 || pos[0]%10 - yOffset + i%10 > 9 || newPos > 199 || newPos < 0 || board[newPos]){
                    x = true;
                }
            }
            if(!x){
                break;
            }
            switch(i){
                case 0: 
                    i = -11;
                    break;
                case-10:
                    i = -2;
                    break;
                case -1:
                    i = 0;
                    break;
                case 1:
                    i = 9;
                    break;
                default:
                    //std::cout << "can't rotate"<<std::endl;
                    break;
            }
        }
        if(x){
            return 0;
        }
        //the actual rotation part
        for (int j = 1; j < 4; j++){
            xOffset = pos[j]%10 -pos[0]%10;
            yOffset = (pos[j]-pos[0]-xOffset)/10;
            pos[j] = xOffset*10 - yOffset + pos[0] + i;
            //std::cout<<std::endl<<xOffset<<" "<<yOffset;
        }
        pos[0] += i;
    }
    return 1;
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
            return 1;
        }
    }
    return 0;
}