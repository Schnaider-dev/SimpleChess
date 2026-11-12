#include "./c++_headers/King.h"

// Checks whether the king can move one square to an empty adjacent square.
bool King::IsValidMove(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    bool horizontal_move = row_diff == 0 && col_diff == 1;
    bool vertical_move = col_diff == 0 && row_diff == 1;
    bool diagonal_move = row_diff == 1 && row_diff == col_diff;

    return (horizontal_move || vertical_move || diagonal_move) && CanLandOn(piece);
}

// Checks whether the king can capture an opposing piece on an adjacent square.
bool King::IsValidCapture(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    bool horizontal_move = row_diff == 0 && col_diff == 1;
    bool vertical_move = col_diff == 0 && row_diff == 1;
    bool diagonal_move = row_diff == 1 && row_diff == col_diff;

    return (horizontal_move || vertical_move || diagonal_move) && CanCaptureOn(piece);
}

// Captures an opposing piece if the target is a legal adjacent square.
bool King::Capture(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidCapture(m_target, piece)) {
        return false;
    }

    position = m_target;
    return true;
}

// Moves the king to an empty adjacent square if the move is legal.
bool King::MoveTo(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidMove(m_target, piece)) {
        return false;
    }

    position = m_target;
    return true;
}

// Returns the board character used to display this king's color.
char King::Symbol() {
    return m_white ? 'K' : 'k';
}