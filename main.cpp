#include "tetris.hpp"
#include "tile.hpp"

//main file that is executed

int main(){
    clearBoard();
    for(int i = 0; i < 100; i++){
        tile actTile;
        printBoard(actTile.piecePos);
        actTile.rotate();
        printBoard(actTile.piecePos);
        actTile.moveLeft();
        printBoard(actTile.piecePos);
        actTile.moveRight();
        printBoard(actTile.piecePos);
        actTile.moveDown();
        printBoard(actTile.piecePos);
        actTile.rotate();
        printBoard(actTile.piecePos);
    }
    
}