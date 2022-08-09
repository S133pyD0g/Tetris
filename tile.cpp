//executables of the class functions defined in tile.hpp

#include <stdlib.h>
#include "tile.hpp"
#include "tetris.hpp"

tile::tile(){
    int pos = 0;
    int rotation = 0;
    //chooses a random type of tile, then according to that type forms the initial cage
    this->type = rand() %7;
    switch(this->type){
        case 0: break;
        case 1: break;
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

void tile::rotate(){
    this->rotation++;
    this->rotation %= 4;
    switch(this->type){
        case 0: 
            break;
        case 1: 
            break;
        default:
            //WONT WORK IF OTHER TILES FROM PREVIOUS PARTS ALREADY ARE IN 3x3 CAGE AREA -> rotation_possible_check !!!
            cage[0] = board[this->pos+9],cage[1] = board[this->pos-1],cage[2] = board[this->pos-11],
            cage[3] = board[this->pos+10],cage[4] = board[this->pos],cage[5] = board[this->pos-10],
            cage[6] = board[this->pos+11],cage[7] = board[this->pos+1],cage[8] = board[this->pos-9];
            board[this->pos-11] = cage[0];board[this->pos-10] = cage[1];board[this->pos-9] = cage[2];
            board[this->pos-1] = cage[3];board[this->pos+1] = cage[5];
            board[this->pos+9] = cage[6];board[this->pos+10] = cage[7];board[this->pos+11] = cage[8];
            //for (int i = 0; i <9;i++){std::cout <<std::endl<< cage[i];}
    }
}