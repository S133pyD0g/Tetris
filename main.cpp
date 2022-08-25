#include "tile.hpp"
#include "tetris.hpp"
#include <chrono>

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
    int time;
    int prevTime = 0;

    while (true){

        tile actTile;
        //GAME OVER check
        if(board[actTile.pos[0]]||board[actTile.pos[1]]||board[actTile.pos[2]]||board[actTile.pos[3]]){
            std::cout<<"\n\nGAME OVER\n\n";
            break;
        }
        auto start = std::chrono::high_resolution_clock::now();
        printBoard(actTile.pos);

        while(!actTile.collisionCheck(board))
        {
            //keychecks
            press = keychecks();
            if(pressed != press){
                switch (press)
                {
                case 1:
                    actTile.rotate(board);
                    printBoard(actTile.pos);
                    //std::cout<<"1"<<std::flush;
                    break;
                case 2:
                    actTile.moveLeft(board);
                    printBoard(actTile.pos);
                    //std::cout<<"2"<<std::flush;
                    break;
                case 3:
                    actTile.moveRight(board);
                    printBoard(actTile.pos);
                    //std::cout<<"3"<<std::flush;
                    break;
                case 4:
                    actTile.moveDown();
                    printBoard(actTile.pos);
                    //std::cout<<"4"<<std::flush;
                    break;
                default:
                    break;
                }
                pressed = press;
            }

            //tickTile
            auto finish = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = finish - start;
            time = int(elapsed.count()*10);
            if(time % 10 == 0 && time != prevTime){
                actTile.moveDown();
                printBoard(actTile.pos);
            }
            prevTime = time;
        }
        //writes finished tile to board
        for(int i=0; i<4; i++){
            board[actTile.pos[i]] = true;
        }
        updateBoard();
    }
}