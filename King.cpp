#include "./c++_headers/King.h"

bool King::IsValidMove(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    bool horizontal_move = row_diff == 0 && col_diff == 1;
    bool vertical_move = col_diff == 0 && row_diff == 1;
    bool diagonal_move = row_diff == 1 && row_diff == col_diff;

    return (horizontal_move || vertical_move || diagonal_move) && CanLandOn(piece);
}

bool King::IsValidTake(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    bool horizontal_move = row_diff == 0 && col_diff == 1;
    bool vertical_move = col_diff == 0 && row_diff == 1;
    bool diagonal_move = row_diff == 1 && row_diff == col_diff;

    return (horizontal_move || vertical_move || diagonal_move) && CanTakeOn(piece);
}

bool King::Take(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidTake(m_target, piece)) {
        return false;
    }

    position = m_target;
    return true;
}

bool King::MoveTo(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidMove(m_target, piece)) {
        return false;
    }

    position = m_target;
    return true;
}

char King::Symbol() {
    return m_white ? 'K' : 'k';
}