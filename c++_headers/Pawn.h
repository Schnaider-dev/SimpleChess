#pragma once

#include "Piece.h"
#include "Position.h"
#include <string>

//code that has a Pawn can use its public Piece members, and a Pawn can be used where a Piece is expected.

class Pawn : public Piece {
    public:
        using Piece::Piece;
        bool first_move = true;
        bool IsValidCapture(Position target, const Piece* piece) override;
        bool IsValidMove(Position target, const Piece* piece) override;
        bool Capture(std::string target, const Piece* piece) override;
        bool MoveTo(std::string target, const Piece* piece) override;
        char Symbol() override;
};