#include "./c++_headers/Rook.h"
#include <string>


// Checks whether the rook can move along a rank or file to an empty square.
bool Rook::IsValidMove(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    //The rook can move in one position only, if the row change, the col cannot, the opposite is also true, if the col changes, the row cannot.
    //And they can move from one end to the other, that explain the difference being calculated.

    bool horizontal_move = row_diff == 0 && col_diff > 0;
    bool vertical_move = col_diff == 0 && row_diff > 0;

    return (horizontal_move || vertical_move) && CanLandOn(piece);
}

// Checks whether the rook can capture an opposing piece along a rank or file.
bool Rook::IsValidCapture(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    bool horizontal_move = row_diff == 0 && col_diff > 0;
    bool vertical_move = col_diff == 0 && row_diff > 0;

    return (horizontal_move || vertical_move) && CanCaptureOn(piece);
}


// Captures an opposing piece on the target square if the capture is valid.
bool Rook::Capture(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidCapture(m_target, piece)) {
        return false;
    }

    position = m_target;
    return true;
}

// Moves the rook to the target square if the move is valid.
bool Rook::MoveTo(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidMove(m_target, piece)) {
        return false;
    }

    position = m_target;
    return true;
}



// Returns the board character used to display this rook's color.
char Rook::Symbol() {
    return m_white ? 'R' : 'r';
}