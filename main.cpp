#include "tile.hpp"
#include "tetris.hpp"
#include <chrono>
#include <math.h>

//main file that is executed

int main()
{
    std::cout<<"\n\npress  something and then ENTER to start game\n\n";
    int choice;
    std::cin>>choice;

    //setup
    clearBoard();
    int press = 0;
    int pressed = 0;
    int level = 0, score = 0, remLines = 0, tetrisCounter = 0, lastScore = 0,lastRemLines = 0, lastTetrisCounter = 0;
    int highscore = readHighscore();

    while (true){

        tile actTile;
        //GAME OVER check
        if(board[actTile.pos[0]]||board[actTile.pos[1]]||board[actTile.pos[2]]||board[actTile.pos[3]]){
            std::cout<<"\n\nGAME OVER\n\n";
            break;
        }
        timer tileTickTimer;
        tileTickTimer.start();
        int prevTime = 0;
        printBoard(actTile.pos, level, score, remLines, highscore);

        while(!actTile.collisionCheck(board)){

            //keychecks 
            press = keychecks();
            if(pressed != press){
                switch (press)
                {
                case 1:
                    actTile.rotate(board);
                    printBoard(actTile.pos, level, score, remLines, highscore);
                    //std::cout<<"1"<<std::flush;
                    break;
                case 2:
                    actTile.moveLeft(board);
                    printBoard(actTile.pos, level, score, remLines, highscore);
                    //std::cout<<"2"<<std::flush;
                    break;
                case 3:
                    actTile.moveRight(board);
                    printBoard(actTile.pos, level, score, remLines, highscore);
                    //std::cout<<"3"<<std::flush;
                    break;
                case 4:
                    actTile.moveDown();
                    printBoard(actTile.pos, level, score, remLines, highscore);
                    //std::cout<<"4"<<std::flush;
                    break;
                default:
                    break;
                }
                pressed = press;
            }

            //tickTile
            int time = int(tileTickTimer.split()*10);
            if(time % int(pow(double(0.8-(level-1)*0.007), double(level-1))*10) == 0 && time != prevTime){
                actTile.moveDown();
                printBoard(actTile.pos, level, score, remLines, highscore);
                prevTime = time;
            }
        }
        //writes finished tile to board
        for(int i=0; i<4; i++){
            board[actTile.pos[i]] = true;
        }
        //updates board, removed lines and level
        int x =  updateBoard();
        switch (x)
        {
            case 1:
                score += 40*(level+1);
                break;
            case 2:
                score += 100*(level+1);
                break;
            case 3:
                score += 300*(level+1);
                break;
            case 4:
                score += 1200*(level+1);
                tetrisCounter ++;
                break;
            default:
                break;
        }
        remLines += x;
        if((remLines-lastRemLines) >= 12 || tetrisCounter-lastTetrisCounter == 2){
            level++;
            lastTetrisCounter = tetrisCounter;
            lastRemLines = remLines;
            lastScore = score;
        }
        
    }
    if(score > highscore){
            setHighscore(score);
        }
}