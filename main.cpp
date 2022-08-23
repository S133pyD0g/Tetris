#include "tile.hpp"
#include "tetris.hpp"
//#include <time.h>
//#include <chrono>

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
    board[105] = true;

    while (true)
    {
        tile actTile;
        printBoard(actTile.pos);
        while(!actTile.collisionCheck(board)){

            //keychecks
            press = keychecks();
            if(pressed != press){
                switch (press)
                {
                case 1:
                    actTile.rotate();
                    printBoard(actTile.pos);
                    std::cout<<"1"<<std::flush;
                    break;
                case 2:
                    actTile.moveLeft();
                    printBoard(actTile.pos);
                    std::cout<<"2"<<std::flush;
                    break;
                case 3:
                    actTile.moveRight();
                    printBoard(actTile.pos);
                    std::cout<<"3"<<std::flush;
                    break;
                case 4:
                    actTile.moveDown();
                    printBoard(actTile.pos);
                    std::cout<<"4"<<std::flush;
                    break;
                default:
                    break;
                }
                pressed = press;
            }

            //tickTile
        }
        for(int i=0; i<4; i++){
            board[actTile.pos[i]] = true;
        }
    }
    //printBoard(actTile.pos);
        

    //auto start = std::chrono::high_resolution_clock::now();
    //auto finish = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> elapsed = finish - start;
    //std::cout<<elapsed.count();
    //while(int(elapsed.count() * 10) % 10 != 0){};
}