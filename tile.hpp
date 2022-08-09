//tile class definition

class tile
{
    public:
        int pos ;
        int rotation;
        int type;
        int piecePos[4];

        tile();
        ~tile();
        void rotate();

};