#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "c++_headers/Board.h"
#include "c++_headers/Position.h"

std::string AddMargin(std::string &text);

// Builds the board from the starting pieces belonging to both players.
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

// Rebuilds the board grid using the pieces' current positions.
void Board::UpdatedBoard() {
    board = Grid(SIZE, std::vector<Piece*>(SIZE, nullptr));
    for (Piece* piece : board_pieces) {
        int row = piece->position.get_row();
        int col = piece->position.get_col();
        board[row][col] = piece;
    }
}

// Prints the board and the pieces captured by each player.
void Board::DisplayBoard(std::vector<std::vector<Piece*>>* captured_pieces) {
   
    std::vector<string> players = {"Black", "White"};
    int i = 0;
    
    std::ostringstream out;
    out << "\033[2J\033[H";
    //"\033[K" before each "\n" erases leftover characters on that line.
    out << "    " << "a b c d e f g h \n";
    out << "    " << std::string(16, '-') << "\n";

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

    std::cout << out.str() << std::flush; // one single write
}

// Returns the piece at the requested chess square, or nullptr if it is empty.
Piece* Board::At(std::string position) {
    Position new_pos(position);
    Piece *piece = board[new_pos.get_row()][new_pos.get_col()];
    return piece;
}

// Removes a captured piece from the board grid and the board's piece list.
void Board::RemovePiece(Piece* piece) {
    if (piece == nullptr) {
        return;
    }

    int row = piece->position.get_row();
    int col = piece->position.get_col();
    board[row][col] = nullptr;
    /*
        The std::remove function is a template algorithm that removes all occurrences of a specified value from a range defined by two iterators, _First and _Last, in a vector of pointers to Piece objects. It shifts the remaining elements to the front of the range and returns an iterator to the new logical end of the vector, effectively resizing it without actually changing its capacity.  
    */
    board_pieces.erase(
        std::remove(board_pieces.begin(), board_pieces.end(), piece),
        board_pieces.end()
    );
}

// Adds left-side spacing to the rendered board text.
