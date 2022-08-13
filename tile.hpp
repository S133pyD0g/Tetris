//tile class definition

class tile
{
    public:
        int rotation;
        int type;
        int piecePos[4];

        tile();
        ~tile();
        void rotate();
        void moveDown();
        void moveLeft();
        void moveRight();
};