#include <string>
#include <cstdlib>
#include "./c++_headers/Bishop.h"

bool Bishop::IsValidMove(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    return row_diff > 0 && row_diff == col_diff && CanLandOn(piece);
}

bool Bishop::IsValidTake(Position target, const Piece *piece) {
    const Position &current = position;
    int row_diff = std::abs(current.get_row() - target.get_row());
    int col_diff = std::abs(current.get_col() - target.get_col());

    return row_diff > 0 && row_diff == col_diff && CanTakeOn(piece);
}

bool Bishop::MoveTo(std::string target, const Piece *piece) {
    Position m_target(target);

    if(!IsValidMove(m_target, piece))
        return false;

    position = m_target;
    return true;
}

bool Bishop::Take(std::string target, const Piece *piece) {
    Position m_target(target);
    if(!IsValidTake(m_target, piece)){
        return false;
    }

    position = m_target;
    return true;
}

char Bishop::Symbol() {
    return m_white ? 'B' : 'b';
}