#pragma once

#include "Piece.h"
#include <string>

class Rook : public Piece {
    public:
        using Piece::Piece;
        bool IsValidTake(Position target, const Piece* piece) override;
        bool IsValidMove(Position target, const Piece* piece) override;
        bool Take(std::string target, const Piece* piece) override;
        bool MoveTo(std::string target, const Piece* piece) override;
        char Symbol() override;
};