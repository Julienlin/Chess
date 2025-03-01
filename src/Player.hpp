#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Board.hpp"
class Board;

#include "Arbitre.hpp"
class Arbitre;

class Player
{
protected:
    byte color;
    byte pieces[32];
    byte pieces_nb;
public:
    Player(Board* b, byte c);
    ~Player(){};
    virtual move play(Board* b, Arbitre* a){return 0;};
};


class Human : public Player
{
private:

public:
    Human(Board*b, byte c) : Player(b, c){};
    move play(Board * b, Arbitre * a) override;
};

class AlphaBeta : public Player
{
private:
    byte depth = 6;
    char pieces_sqv[6][64] =  {{0,  0,  0,  0,  0,  0,  0,  0,
                                50, 50, 50, 50, 50, 50, 50, 50,
                                10, 10, 20, 30, 30, 20, 10, 10,
                                5,  5, 10, 25, 25, 10,  5,  5,
                                0,  0,  0, 20, 20,  0,  0,  0,
                                5, -5,-10,  0,  0,-10, -5,  5,
                                5, 10, 10,-20,-20, 10, 10,  5,
                                0,  0,  0,  0,  0,  0,  0,  0},
                               {0,  0,  0,  0,  0,  0,  0,  0,
                                5, 10, 10, 10, 10, 10, 10,  5,
                                -5,  0,  0,  0,  0,  0,  0, -5,
                                -5,  0,  0,  0,  0,  0,  0, -5,
                                -5,  0,  0,  0,  0,  0,  0, -5,
                                -5,  0,  0,  0,  0,  0,  0, -5,
                                -5,  0,  0,  0,  0,  0,  0, -5,
                                0,  0,  0,  5,  5,  0,  0,  0},
                               {-50,-40,-30,-30,-30,-30,-40,-50,
                                -40,-20,  0,  0,  0,  0,-20,-40,
                                -30,  0, 10, 15, 15, 10,  0,-30,
                                -30,  5, 15, 20, 20, 15,  5,-30,
                                -30,  0, 15, 20, 20, 15,  0,-30,
                                -30,  5, 10, 15, 15, 10,  5,-30,
                                -40,-20,  0,  5,  5,  0,-20,-40,
                                -50,-40,-30,-30,-30,-30,-40,-50},
                               {-20,-10,-10,-10,-10,-10,-10,-20,
                                -10,  0,  0,  0,  0,  0,  0,-10,
                                -10,  0,  5, 10, 10,  5,  0,-10,
                                -10,  5,  5, 10, 10,  5,  5,-10,
                                -10,  0, 10, 10, 10, 10,  0,-10,
                                -10, 10, 10, 10, 10, 10, 10,-10,
                                -10,  5,  0,  0,  0,  0,  5,-10,
                                -20,-10,-10,-10,-10,-10,-10,-20},
                               {-20,-10,-10, -5, -5,-10,-10,-20,
                                -10,  0,  0,  0,  0,  0,  0,-10,
                                -10,  0,  5,  5,  5,  5,  0,-10,
                                -5,  0,  5,  5,  5,  5,  0, -5,
                                0,  0,  5,  5,  5,  5,  0, -5,
                                -10,  5,  5,  5,  5,  5,  0,-10,
                                -10,  0,  5,  0,  0,  0,  0,-10,
                                -20,-10,-10, -5, -5,-10,-10,-20},
                               {-30,-40,-40,-50,-50,-40,-40,-30,
                                -30,-40,-40,-50,-50,-40,-40,-30,
                                -30,-40,-40,-50,-50,-40,-40,-30,
                                -30,-40,-40,-50,-50,-40,-40,-30,
                                -20,-30,-30,-40,-40,-30,-30,-20,
                                -10,-20,-20,-20,-20,-20,-20,-10,
                                20, 20,  0,  0,  0,  0, 20, 20,
                                20, 30, 10,  0,  0, 10, 30, 20}};
    uint64_t calculated[8];
public:
    AlphaBeta(Board*b, byte c) : Player(b, c){};
    move play(Board * b, Arbitre * a) override;
    int digDown(Board* b, Arbitre* a, int depth, int alpha, int beta);
    int evaluateBoard(Board* b);
};


#endif
