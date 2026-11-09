#pragma once

#include <string>

class Position {
    private:
        int row = 0;
        int col = 0;

    public:
        Position();
        Position(int row, int col);
        Position(std::string position);
        bool set_position(int row, int col);
        int get_row() const;
        int get_col() const;
        std::string get_position() const;
};