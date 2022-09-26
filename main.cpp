#include "tile.hpp"
#include "tetris.hpp"
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <time.h>

//main file that is executed

int main()
{
    std::cout<<"\n\npress  something and then ENTER to start game\n\n";
    int choice;
    std::cin>>choice;

    //setup
    clearBoard();
    int pressedKey = 0, lastPressedKey = 0;    //keycheck variables
    int level = 0, score = 0, remLines = 0, tetrisCounter = 0, lastRemLines = 0, lastTetrisCounter = 0;     //level & score variables
    int highscore = readHighscore();
    int bagIndex = 0, tileBag[7] = {7, 7, 7, 7, 7, 7, 7};   //tileBag system variables

    while (true){
        
        //the main operating body of the bag system for the tiles. 
        //This way in every seven tiles, every type is included once, although the order of appearance is random
        if (bagIndex > 6){
            for (int i = 0; i < 7; i++){
                tileBag[i] = 7;
            }
            bagIndex = 0;
        }
        srand(time(NULL));
        int type = rand() % 7;
        while (std::count(std::begin(tileBag), std::end(tileBag), type) > 0){
            type = rand() % 7;
        }
        tileBag[bagIndex] = type;
        bagIndex++;

        tile actTile(type);

        //GAME OVER check
        if(board[actTile.pos[0]]||board[actTile.pos[1]]||board[actTile.pos[2]]||board[actTile.pos[3]]){
            std::cout<<"\n\nGAME OVER\n\n";
            break;
        }
        //timer for tile ticking
        timer tileTickTimer;
        tileTickTimer.start();
        int prevTime = 0;
        timer colTimer;
        printBoard(actTile.pos, level, score, remLines, highscore);

        while(colTimer.split() < 0.5){

            //keychecks 
            pressedKey = keychecks();
            if(pressedKey != lastPressedKey){
                switch (pressedKey)
                {
                case 1:
                    if (actTile.rotate(board)){
                        colTimer.stop();
                        printBoard(actTile.pos, level, score, remLines, highscore);
                    }
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
                    if(!actTile.collisionCheck(board)){
                        actTile.moveDown();
                        printBoard(actTile.pos, level, score, remLines, highscore);
                        //std::cout<<"4"<<std::flush;
                    }
                    break;
                default:
                    break;
                }
                lastPressedKey = pressedKey;
            }

            //tickTile
            int time = int(tileTickTimer.split()*10);
            if(time % int(pow(double(0.8-(level-1)*0.007), double(level-1))*10) == 0 && time != prevTime && !actTile.collisionCheck(board)){
                actTile.moveDown();
                printBoard(actTile.pos, level, score, remLines, highscore);
                prevTime = time;
            }

            //collision Timer conditionals for movement and rotation time buffers
            if(actTile.collisionCheck(board)&&!colTimer.active){
                colTimer.start();
            }
            if(!actTile.collisionCheck(board)){
                colTimer.stop();
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
        }
        
    }
    //highscore update
    if(score > highscore){
            setHighscore(score);
        }
}