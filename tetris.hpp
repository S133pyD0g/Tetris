#include <iostream>

//all functions concerning the player board

bool board[200];

void clearBoard(){
    for(int i = 0; i < sizeof(board); i++){
        board[i] = 0;
    }
}
void printBoard(int piecesPos[4]){
    for (int i = 0; i < 4; i++){
        board[piecesPos[i]] = true;
    }
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int i = 0; i < sizeof(board); i++){
        if (i % 10 == 0){
            std::cout<<"\n";
        }
        std::cout<<board[i];
    }
    for (int i = 0; i < 4; i++){
        board[piecesPos[i]] = false;
    }
}