#include "./c++_headers/Player.h"

Player::Player(bool white) : m_white(white), king(white), queen(white), b_bishop(white), w_bishop(white), b_knight(white), w_knight(white), b_rook(white), w_rook(white), pawns(8, Pawn(white)){
    
        b_rook.position = white ? Position("a1") : Position("h8");
        w_knight.position = white ? Position("b1") : Position("g8");
        b_bishop.position = white ? Position("c1") : Position("f8");
        queen.position = white ? Position("d1") : Position("e8");
        king.position = white ? Position("e1") : Position("d8");
        w_bishop.position = white ? Position("f1") : Position("c8");
        b_knight.position = white ?  Position("g1") : Position("b8");
        w_rook.position =  white ? Position("h1") : Position("a8");

     for (int col = 0; col < 8; ++col )
        {
            std::string square;
            square += static_cast<char>('a' + col);
            square += white ? '2' : '7';
            pawns[col].position = Position(square);
        };
        pieces = {&king, &queen, &b_bishop, &w_bishop, &b_knight, &w_knight, &w_rook, &b_rook};

        for(Pawn& pawn: pawns) {
            pieces.push_back(&pawn);
        };
};