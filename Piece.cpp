#include "./c++_headers/Piece.h"

Piece::Piece(bool white) : m_white(white) {};

//Add const after the function’s parentheses to show that it doesn’t modify the piece:
bool Piece::CanLandOn(const Piece *targetPiece) const {
    return targetPiece == nullptr;
};

bool Piece::CanTakeOn(const Piece *targetPiece) const {
    return targetPiece != nullptr && targetPiece->m_white != m_white;
}