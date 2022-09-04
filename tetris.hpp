#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <chrono>

//all functions concerning the player board, keychecks and the highscore

bool board[200];

//sets all board spaces to false/empty
void clearBoard(){
    for(int i = 0; i < sizeof(board); i++){
        board[i] = 0;
    }
}

//prints the playing board to the terminal
void printBoard(int pos[4], int level, int score, int remLines, int highscore){
    for (int i = 0; i < 4; i++){
        board[pos[i]] = true;
    }
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\nLevel: "<<level<<"\nScore: "<<score<<"\nRemoved Lines: "<<remLines <<"\n\nHighscore: "<<highscore<<"\n\n######################\n#"<<std::flush;
    for(int i = 0; i < sizeof(board); i++){
        if (i % 10 == 0 && i != 0){
            std::cout<<"#\n#"<<std::flush;
        }
        if (board[i]){
            std::cout<<"██"<<std::flush;
        }else{
            std::cout<<"  "<<std::flush;
        }
    }
    std::cout<<"#\n######################"<<std::flush;
    for (int i = 0; i < 4; i++){
        board[pos[i]] = false;
    }
}

//removes full lines and moves all of the above down, returns the number of removed lines
int updateBoard(){
    int linesRemoved = 0;
    for(int i=0; i<20; i++){
        int counter = 0;
        for(int j=0; j<10; j++){
            if(board[i*10+j])
            counter ++;
        }
        if(counter == 10){
            //std::cout<<"line"<<i<<"to be removed"<<std::flush;
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

int readHighscore(){
    std::string sHighscore;
    std::ifstream file;
    file.open("highscore.txt");
    if(!file.is_open()){
        std::cout<<"file not found"<<std::endl;
        return 0;
    }
    getline(file,sHighscore);
    file.close();
    return std::stoi(sHighscore);
    
}

void setHighscore(const int highscore){
    std::ofstream file;
    file.open("highscore.txt");
    if(!file.is_open()){
        std::cout<<"file not found"<<std::endl;
        return;
    }
    file<<highscore<<std::flush;
    file.close();
}

class timer
{
    public:
        std::chrono::time_point<std::chrono::high_resolution_clock> startPoint;
        bool active;

        timer(){active = false;}
        ~timer(){}
        void start(){
            startPoint = std::chrono::high_resolution_clock::now();
            active = true;
        }
        double split(){
            if(active){
                std::chrono::duration<double> split = std::chrono::high_resolution_clock::now() - startPoint;
                return split.count();
            }
            return 0;
        }
        void stop(){
            active = false;
        }
};