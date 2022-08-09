//all functions concerning the player board

#include <iostream>
using namespace std;

bool board[200];

void clearBoard(){
    for(int i = 0; i < sizeof(board); i++){
        board[i] = 0;
    }
}
void printBoard(){
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int i = 0; i < sizeof(board); i++){
        if (i % 10 == 0){
            std::cout<<"\n";
        }
        std::cout<<board[i];
    }
}