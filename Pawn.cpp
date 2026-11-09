#include "./c++_headers/Pawn.h"
#include <string>
#include <cstdlib>

 bool Pawn::IsValidTake(Position target, const Piece* piece) {
     const Position &current = position;
     int direction = m_white ? 1 : -1;

     int row_change = current.get_row() - target.get_row();
     int col_change = target.get_col() - current.get_col();

     return (row_change == direction) && (std::abs(col_change) == 1) && CanTakeOn(piece);
 }


 bool Pawn::IsValidMove(Position target, const Piece* piece) {
     Position &current = position;
     bool valid_row;
     int direction = m_white ? 1 : -1;
     bool valid_col = current.get_col() == target.get_col();


     if (first_move)
     {
        //The direction for first move, for white piece, two row forward, for black piece two row backward.
         int f_direction = m_white ? 2 : -2;

         // When first move is true, the player can move either one or two rows ahead.
         valid_row = (current.get_row() - target.get_row()) == f_direction || (current.get_row() - target.get_row()) == direction ;
     } 
     else {
         valid_row = current.get_row() == target.get_row() + direction;
     }

     // a pawn moving straight forward may only go to an empty square—it can’t capture straight ahead. So for a pawn’s straight move, check: piece == nullptr
     
     return valid_col && valid_row && CanLandOn(piece);
 }

 bool Pawn::MoveTo(std::string target, const Piece* piece) {
    Position m_target(target);

    if(!IsValidMove(m_target, piece)){
        return false;
    }

    this->position = target;
    first_move = false;
    return true;
 }

 bool Pawn::Take(std::string target, const Piece* piece) {
    Position m_target(target);

    // use the Position constructor and assign the result to the inherited position member
    if (IsValidTake(m_target, piece)) {
        this -> position = m_target;
        return true;
    }
    return false;
}


char Pawn::Symbol() {
    return m_white ? 'P' : 'p';
}