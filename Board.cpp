#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "c++_headers/Board.h"
#include "c++_headers/Position.h"

std::string AddMargin(std::string &text);

Board::Board(std::vector<Player*> players) {
    for(Player* player : players) {
        for(Piece* piece : player->pieces) {
                int row = piece->position.get_row();
                int col = piece->position.get_col();
                board[row][col] = piece;
                board_pieces.push_back(piece);
            };
    }
    
}

void Board::UpdatedBoard() {
    board = Grid(SIZE, std::vector<Piece*>(SIZE, nullptr));
    for (Piece* piece : board_pieces) {
        int row = piece->position.get_row();
        int col = piece->position.get_col();
        board[row][col] = piece;
    }
}

void Board::DisplayBoard(std::vector<std::vector<Piece*>>* captured_pieces) {
   
    std::vector<string> players = {"Black", "White"};
    int i = 0;
    
    std::ostringstream out;
    //"\033[H" at the start moves the cursor to the top-left. The new board is drawn over the old one, so there is no blank frame.
    out << "\033[H"; // cursor to top-left, no clearing

    //"\033[K" before each "\n" erases leftover characters on that line.
    out << "    " << "a b c d e f g h " << "\033[K\n";
    out << "    " << std::string(16, '-') << "\033[K\n";

    for (int row = 0; row < SIZE; row++) {
        out << 8 - row << " ";
        out << " | ";

        for (int col = 0; col < SIZE; col++) {
            Piece *piece = board[row][col];
            if (piece != nullptr) {
                out << piece->Symbol() << " ";
            }
            else {
                out << "." << " ";
            }
        }

        out << "| " << 8 - row << " " << "\033[K\n";
    }

    out << "    " << std::string(16, '_') << "\033[K\n";
    out << "    " << "a b c d e f g h " << "\033[K\n\n";

    for (const std::vector<Piece*> player : *captured_pieces) {
        out << players[i] << ": ";
        for (Piece* piece : player) {
            if (piece != nullptr) {
                out << piece->Symbol() << " ";
            }
            else {
                out << '.';
            }
        }
        i++;
        out <<"\033[K\n";
    }

    //"\033[J" at the end erases anything below the board, such as the old prompt or an old error message.
    out << "\033[J"; // erase everything below the board

    std::cout << AddMargin(out.str()) << std::flush; // one single write
}

Piece* Board::At(std::string position) {
    Position new_pos(position);
    Piece *piece = board[new_pos.get_row()][new_pos.get_col()];
    return piece;
}

void Board::RemovePiece(Piece* piece) {
    if (piece == nullptr) {
        return;
    }

    int row = piece->position.get_row();
    int col = piece->position.get_col();
    board[row][col] = nullptr;
    board_pieces.erase(
        std::remove(board_pieces.begin(), board_pieces.end(), piece),
        board_pieces.end()
    );
}

std::string AddMargin(std::string& text) {
    std::ostringstream out;

    out << "\n" << std::string(10, ' ') << "\n";
    out << std::string(50, ' ') << text;
    return out.str();
}