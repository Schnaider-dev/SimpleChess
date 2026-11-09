
#pragma once

#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Piece.h"
#include <vector>

class Player {
    public:
        bool m_white;
        Player(bool white);
        King king;
        Queen queen;
        Bishop b_bishop;
        Bishop w_bishop;
        Knight b_knight;
        Knight w_knight;
        Rook w_rook;
        Rook b_rook;
        std::vector<Pawn> pawns;
        std::vector<Piece *> pieces;
};