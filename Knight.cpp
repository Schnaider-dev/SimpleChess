#include "./c++_headers/Knight.h"
#include <string>

bool Knight::IsValidMove(Position target, const Piece* piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    return (row_diff == 2 && col_diff == 1 && CanLandOn(piece)) || (row_diff == 1 && col_diff == 2 && CanLandOn(piece));
};

bool Knight::IsValidTake(Position target, const Piece* piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    return (row_diff == 2 && col_diff == 1 && CanTakeOn(piece)) || (row_diff == 1 && col_diff == 2 && CanTakeOn(piece));
};

bool Knight::MoveTo(std::string target, const Piece* piece) {
    Position m_target(target);
    if (IsValidMove(m_target, piece)){
        position = target;
        return true;
    }
    return false;
}

bool Knight::Take(std::string target, const Piece* piece) {
    Position m_target(target);
    if (IsValidTake(m_target, piece)) {
        position = m_target;
        return true;
    }
    return false;
}

char Knight::Symbol() {
    return m_white ? 'N' : 'n';
}