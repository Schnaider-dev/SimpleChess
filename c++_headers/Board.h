#pragma once

#include "Piece.h"
#include "Player.h"
#include <vector>
#include <string>

using Grid = std::vector<std::vector<Piece*>>;

class Board {
    private:
        std::vector<Piece *> board_pieces;
        static constexpr int SIZE = 8;
        Grid board = Grid(SIZE, std::vector<Piece*>(SIZE, nullptr));

    public:
        Board(std::vector<Player*> players);
        void DisplayBoard(std::vector<std::vector<Piece*>>* captured_pieces);
        Piece* At(std::string position);
        void RemovePiece(Piece* piece);
        void UpdatedBoard();
};
