#include "./c++_headers/Queen.h"

// Checks whether the queen can move horizontally, vertically, or diagonally to an empty square.
bool Queen::IsValidMove(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    bool horizontal_move = row_diff == 0 && col_diff > 0;
    bool vertical_move = col_diff == 0 && row_diff > 0;
    bool diagonal_move = row_diff > 0 && row_diff == col_diff;

    return (horizontal_move || vertical_move || diagonal_move) && CanLandOn(piece);
}

// Checks whether the queen can capture an opposing piece along a rank, file, or diagonal.
bool Queen::IsValidCapture(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    bool horizontal_move = row_diff == 0 && col_diff > 0;
    bool vertical_move = col_diff == 0 && row_diff > 0;
    bool diagonal_move = row_diff > 0 && row_diff == col_diff;

    return (horizontal_move || vertical_move || diagonal_move) && CanCaptureOn(piece);
}

// Captures an opposing piece on the target square if the capture is valid.
bool Queen::Capture(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidCapture(m_target, piece)) {
        return false;
    }

    position = m_target;
    return true;
}

// Moves the queen to the target square if the move is valid.
bool Queen::MoveTo(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidMove(m_target, piece)) {
        return false;
    }
    piece =nullptr;
    position = m_target;
    return true;
}

// Returns the board character used to display this queen's color.
char Queen::Symbol() {
    return m_white ? 'Q' : 'q';
}