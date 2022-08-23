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
        void rotate();
        void moveDown();
        void moveLeft();
        void moveRight();
        bool collisionCheck(bool board[200]);
};