#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "c++_headers/Board.h"
#include "c++_headers/Player.h"
#ifdef _WIN32
#include <windows.h>
#endif

// Call once at program start
void initTerminal();
std::vector<std::string> Split(std::string text, char delimiter);
void DisplayGameInterface();
void clearScreen();
void enterGameScreen();
void leaveGameScreen();

// Runs the game menu and manages turns, input, moves, and captures.
int main() {
    initTerminal();
    std::string user_choice, user_input;
    bool open = true;

    do {

        DisplayGameInterface();
        std::cout << "Please choose an option: ";
        //std::cin >> user_choice leaves the Enter key in the buffer. The next getline then reads an empty line. Reading the menu choice with getline fixes it.
        std::getline(std::cin, user_choice);

        if (user_choice == "1") {
            bool is_playing = true;
            bool white_turn = true;

            Player white(true);
            Player black(false);

            Board board(std::vector<Player*>{&white, &black});

            enterGameScreen();
            std::vector<std::vector<Piece*>> captured_pieces(2);
            board.DisplayBoard(&captured_pieces);
            std::cout << "\nType 'quit' to end the game.\n";


            do
            {

                //std::cout << white_turn ? "White" : "Black"; prints 1/0. The insertion operator "<<" binds tighter than "?" and ":", so i need parentheses: 
                std::cout <<"\n" <<( white_turn ? "(White)" : "(Black)") << " ";

                std::cout << "Please enter your move: ";
                std::getline(std::cin, user_input);


                if (user_input == "quit") {
                    is_playing = false;
                    continue;
                }

                std::vector<std::string> positions = Split(user_input, ' ');

                if(positions.size() != 3) {
                    std::cout << "Invalid move. This move is not allowed.";
                    continue;
                }

                // if(std::getline(std::cin, user_input, 'x')){
                //     positions = Split(user_input, 'x');
                //     command = "attack";
                // }
                // else if(std::getline(std::cin, user_input, 'o')) {
                //     positions = Split(user_input, 'o');
                //     command = "move";
                // }
                // else {
                //     std::cout << "Invalid input. Please try again.";
                //     continue;
                // }
                std::string command = positions[0];
                std::string from = positions[1];
                std::string to = positions[2];

                Piece *moving_piece = board.At(from);
                Piece *capture_piece = board.At(to);

                if(moving_piece == nullptr) {
                    std::cout << "Invalid move. No piece at this position.";
                    continue;
                }

                if (moving_piece->m_white != white_turn) {
                    std::cout << "You cannot move this piece. It's not your turn yet. \n";
                     continue;
                }

                bool success;
                if (command == "capture")
                {
                    success = moving_piece->Capture(to, capture_piece);
                } 
                else if (command == "move"){
                    success = moving_piece->MoveTo(to, capture_piece);
                } else {
                    std::cout << "      Invalid command. Try again";
                    continue;
                }    
                
                if(command == "capture" && success) {
                    captured_pieces[white_turn].push_back(capture_piece);
                    board.RemovePiece(capture_piece);
                }
                
                if (success) {
                    white_turn = !white_turn;
                    board.UpdatedBoard();
                    board.DisplayBoard(&captured_pieces);
                    
                }
                else {
                    std::cout << "    This" << " " << command << " was unsuccessful. Try again.\n";
                }
                
            } while (is_playing);
            leaveGameScreen();
        }
        else if(user_choice == "2"){
            
        }
        else {
            open = false;
        }
    } while (open);

}

// Splits a string into parts wherever the chosen delimiter appears.
std::vector<std::string> Split(std::string text, char delimiter) {
    std::istringstream stream(text);
    std::string piece;
    std::vector<std::string> parts;

    while(std::getline(stream, piece, delimiter )) {
        parts.push_back(piece);
    }

    return parts;
}

// Prints the game's main menu.
void DisplayGameInterface() {
        clearScreen();
        std::string menu_text;
        menu_text += "\n\nWelcome to Nai's Chess Game \n";
        menu_text += std::string(40, '*');
        menu_text += "\n";
        menu_text += "1. New Game \n";
        menu_text += "2. Help \n";
        menu_text += "3. Quit \n";
        menu_text += std::string(40, '*');
        menu_text += "\n";
        std::cout << menu_text;
}

// Enables terminal settings needed for the board display on Windows.
void initTerminal() {
#ifdef _WIN32
    // Enables ANSI escape codes on Windows 10+
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(h, &mode);
    SetConsoleMode(h, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    clearScreen();
#endif
}

// Clears the terminal and moves the cursor to the top-left corner.
void clearScreen() {
    std::cout << "\033[2J\033[H" << std::flush;
}

// Uses the terminal's separate screen buffer so game output does not enter scrollback.
void enterGameScreen() {
    std::cout << "\033[?1049h\033[2J\033[H" << std::flush;
}

void leaveGameScreen() {
    std::cout << "\033[?1049l" << std::flush;
}
