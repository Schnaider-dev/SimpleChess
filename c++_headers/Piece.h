#pragma once

#include <string>
#include "Position.h"

using string = std::string;

class Piece {

    public:
        // Initialize the member variable m_white with the value passed into the constructor parameter white.
        Piece(bool white);
        const bool m_white;
        Position position;

        //Pure virtual methods
        virtual bool IsValidTake(Position target, const Piece* piece) = 0;
        virtual bool IsValidMove(Position target, const Piece* piece) = 0;
        virtual bool MoveTo(string target, const Piece* piece) = 0;
        virtual bool Take(string target, const Piece* piece) = 0;
        virtual char Symbol() = 0;


        /*The const at the end means: "This method promises not to modify the object."
    
        Why is this useful? Suppose:
        const Person p; 
        The object itself is constant.
        The compiler will only allow calling methods that are marked const
        p.getName(); // ✅ if getName() is const

        */
        bool CanLandOn(const Piece *piece) const;
        bool CanTakeOn(const Piece *pice) const;
};
