#include "./c++_headers/Knight.h"
#include <string>

// Checks whether the knight can make an L-shaped move to an empty square.
bool Knight::IsValidMove(Position target, const Piece* piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    return (row_diff == 2 && col_diff == 1 && CanLandOn(piece)) || (row_diff == 1 && col_diff == 2 && CanLandOn(piece));
};

// Checks whether the knight can capture an opposing piece in an L-shape.
bool Knight::IsValidCapture(Position target, const Piece* piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    return (row_diff == 2 && col_diff == 1 && CanCaptureOn(piece)) || (row_diff == 1 && col_diff == 2 && CanCaptureOn(piece));
};

// Moves the knight to the target square if the move is valid.
bool Knight::MoveTo(std::string target, const Piece* piece) {
    Position m_target(target);
    if (IsValidMove(m_target, piece)){
        position = target;
        return true;
    }
    return false;
}

// Captures an opposing piece on the target square if the capture is valid.
bool Knight::Capture(std::string target, const Piece* piece) {
    Position m_target(target);
    if (IsValidCapture(m_target, piece)) {
        position = m_target;
        return true;
    }
    return false;
}

// Returns the board character used to display this knight's color.
char Knight::Symbol() {
    return m_white ? 'N' : 'n';
}