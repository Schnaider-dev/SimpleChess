#include "./c++_headers/Piece.h"

// Creates a piece and records whether it belongs to the white player.
Piece::Piece(bool white) : m_white(white) {};

//Add const after the function’s parentheses to show that it doesn’t modify the piece:
// Returns true when the target square is empty and can be landed on.
bool Piece::CanLandOn(const Piece *targetPiece) const {
    return targetPiece == nullptr;
};

// Returns true when the target square contains an opposing piece.
bool Piece::CanCaptureOn(const Piece *targetPiece) const {
    return targetPiece != nullptr && targetPiece->m_white != m_white;
}