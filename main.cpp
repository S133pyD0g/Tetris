#include "tetris.hpp"
#include "tile.hpp"

//main file that is executed

int main(){
    clearBoard();
    tile actTile;

    /*std::cout<<actTile.rotation<<std::endl;
    actTile.changeRotation();
    std::cout<<actTile.rotation<<std::endl;
    printBoard();
    actTile.pos = 95;
    board[95] = true;
    board[94] = true;
    board[96] = true;
    board[84] = true;
    printBoard();
    actTile.rotate();
    printBoard();*/

    actTile.pos = 95;
    actTile.piecePos[0] = actTile.pos;
    actTile.piecePos[1] = 94;
    actTile.piecePos[2] = 96;
    actTile.piecePos[3] = 84;
    printBoard(actTile.piecePos);
    actTile.rotate();
    printBoard(actTile.piecePos);
}