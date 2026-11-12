#include <string>
#include <cstdlib>
#include "./c++_headers/Bishop.h"

// Checks whether the bishop can move diagonally to an empty square.
bool Bishop::IsValidMove(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    return row_diff > 0 && row_diff == col_diff && CanLandOn(piece);
}

// Checks whether the bishop can capture an opposing piece diagonally.
bool Bishop::IsValidCapture(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    return row_diff > 0 && row_diff == col_diff && CanCaptureOn(piece);
}

// Moves the bishop to the target square if the move is valid.
bool Bishop::MoveTo(std::string target, const Piece *piece) {
    Position m_target(target);

    if(!IsValidMove(m_target, piece))
        return false;

    position = m_target;
    return true;
}

// Captures an opposing piece on the target square if the capture is valid.
bool Bishop::Capture(std::string target, const Piece *piece) {
    Position m_target(target);
    if(!IsValidCapture(m_target, piece)){
        return false;
    }

    position = m_target;
    return true;
}

// Returns the board character used to display this bishop's color.
char Bishop::Symbol() {
    return m_white ? 'B' : 'b';
}