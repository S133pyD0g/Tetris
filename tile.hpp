#pragma once

//tile class definition

class tile
{
    public:
        int rotation;   //current rotation of tile
        int type;       //type of current tile
        int pos[4];     //positions of the four single tile parts on the board

        tile();
        ~tile();
        void rotate(bool board[200]);
        void moveDown();
        void moveLeft(bool board[200]);
        void moveRight(bool board[200]);
        bool collisionCheck(bool board[200]);
};