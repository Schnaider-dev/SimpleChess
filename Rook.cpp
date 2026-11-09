#include "./c++_headers/Rook.h"
#include <string>


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

bool Rook::IsValidTake(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    bool horizontal_move = row_diff == 0 && col_diff > 0;
    bool vertical_move = col_diff == 0 && row_diff > 0;

    return (horizontal_move || vertical_move) && CanTakeOn(piece);
}


bool Rook::Take(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidTake(m_target, piece)) {
        return false;
    }

    position = m_target;
    return true;
}

bool Rook::MoveTo(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidMove(m_target, piece)) {
        return false;
    }

    position = m_target;
    return true;
}



char Rook::Symbol() {
    return m_white ? 'R' : 'r';
}