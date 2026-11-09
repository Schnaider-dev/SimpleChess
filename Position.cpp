#include "./c++_headers/Position.h"
#include <string>
#include <stdexcept>


Position::Position() = default;

Position::Position(int row, int col) {
    // If the position is set true is return and exception never run, other exception is set.
    if (!set_position(row, col)) {
        throw std::invalid_argument("Position coordinates must be between 1 and 8");
    }
};

Position::Position(std::string position) {
    if (position.size() != 2 || position[0] < 'a' || position[0] > 'h' ||
        position[1] < '1' || position[1] > '8') {
        throw std::invalid_argument("Position must be a chess square such as e4");
    }

    /* 
    => Take the ascii code of 'a', and with the substraction, calculate the difference between the postion[0] and 'a'.

    => This will then be used to transform to the row number
    For exemple: position[0] is 'a' which ascii code is 97
    then 97 - 97 + 1 = 1
    then the letter 'a' will be placed at col 1.

    => All this can be done by taking advantage of the fact that these letters ascii code are contiguous. 'a' = 97, 'b' = 98, 'c' = 99, ect

    => Same thing for row, but i had a protection, row cannot be '0'.
    Because 57 - 57 = 0 but row won't never start at 0, so an invalid_argument will be thrown if row is '0'.
    */

    col = position[0] - 'a';
    row = '8' - position[1];
};

//To check if the position set is valid and return true or false in either case.
bool Position::set_position(int row, int col) {
    bool valid_row = row >= 0 && row <= 7;
    bool valid_col = col >= 0 && col <= 7;
    if (valid_row && valid_col) {
        this->row = row;
        this->col = col;
        return true;
    }
    return false;
};

int Position::get_row() const {
    return row;
};

int Position::get_col() const {
    return col;
};

std::string Position::get_position() const {
    if (row == -1 || col == -1) {
        throw std::logic_error("Position has not been set");
    }

    /*
    => The goal is to convert the coordinates back into a chess-like position(e5).
    to do this we use the ascii code for 'a' as the foundation: 'a' + col - 1 
    If col = 3, and 'a' = 97, then 97 + 3 - 1 become 99, and 99 = 'c'. 
    Same thing here : '0' + row but the value from which we start to calculate the row is '0', which is 48. Because col will start at 1, and 48 + 1 = 49 and 49 = '1'. From there, same calculation occurs. 
    
    => The expression: {'a' + col - 1} actually produces an int, not a char. So: 'a' + 3 - 1 equal 99.
    To turn 99 back into 'c', we cast: static_cast<char>(99) 
    Result: 'c'

    => std::string(1, static_cast<char>('a' + row - 1)) This constructor means: std::string(count, character).
    The first argument is the number of times to repeat the character. And the result is a string {" "}.
    Example: std::string(5, 'x'); produces: "xxxxx"
    */

    return std::string(1, static_cast<char>('a' + col)) +
           static_cast<char>('8' - row); 
           // Ex: "c" + '5' The std::string class overloads + appending a character to a string is valid.
};



