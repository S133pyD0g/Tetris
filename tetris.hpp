#pragma once
#include <iostream>
#include <Windows.h>

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
    std::cout<<"\n\n\n";
    for(int i = 0; i < sizeof(board); i++){
        if (i % 10 == 0){
            std::cout<<std::endl;
        }
        std::cout<<board[i]<<std::flush;
    }
    for (int i = 0; i < 4; i++){
        board[piecesPos[i]] = false;
    }
}
//removes full lines and moves all of the above down
int updateBoard(){
    int linesRemoved = 0;
    for(int i=0; i<20; i++){
        int counter = 0;
        for(int j=0; j<10; j++){
            if(board[i*10+j])
            counter ++;
        }
        if(counter == 10){
            std::cout<<"line"<<i<<"to be removed"<<std::flush;
            for(int j=i*10+9; j>=10; j-=1){
                board[j] = board[j-10];
            }
            for(int j=0; j<10; j++){
                board[j] = false;
            }
            linesRemoved++;
        }
    }
    return linesRemoved;
}

//keychecks for tile functions
int keychecks(){
    if(GetAsyncKeyState(VK_UP)){
        return 1;
    }
    if(GetAsyncKeyState(VK_LEFT)){
        return 2;
    }
    if(GetAsyncKeyState(VK_RIGHT)){
        return 3;
    }
    if(GetAsyncKeyState(VK_DOWN)){
        return 4;
    }
    return 0;
}