#include "./c++_headers/Queen.h"

bool Queen::IsValidMove(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    bool horizontal_move = row_diff == 0 && col_diff > 0;
    bool vertical_move = col_diff == 0 && row_diff > 0;
    bool diagonal_move = row_diff > 0 && row_diff == col_diff;

    return (horizontal_move || vertical_move || diagonal_move) && CanLandOn(piece);
}

bool Queen::IsValidTake(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    bool horizontal_move = row_diff == 0 && col_diff > 0;
    bool vertical_move = col_diff == 0 && row_diff > 0;
    bool diagonal_move = row_diff > 0 && row_diff == col_diff;

    return (horizontal_move || vertical_move || diagonal_move) && CanTakeOn(piece);
}

bool Queen::Take(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidTake(m_target, piece)) {
        return false;
    }

    position = m_target;
    return true;
}

bool Queen::MoveTo(std::string target, const Piece *piece) {
    Position m_target(target);
    if (!IsValidMove(m_target, piece)) {
        return false;
    }
    piece =nullptr;
    position = m_target;
    return true;
}

char Queen::Symbol() {
    return m_white ? 'Q' : 'q';
}