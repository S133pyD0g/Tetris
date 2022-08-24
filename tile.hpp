#pragma once
//tile class definition

class tile
{
    public:
        int rotation;
        int type;
        int pos[4];

        tile();
        ~tile();
        void rotate(bool board[200]);
        void moveDown();
        void moveLeft(bool board[200]);
        void moveRight(bool board[200]);
        bool collisionCheck(bool board[200]);
};