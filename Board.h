//
// Created by gilsh on 05/12/2021.
//

#ifndef HW2_BOARD_H
#define HW2_BOARD_H
#include "hex.h"
#include <string.h>
#include <stdlib.h>

/* Class Board
 * Represents a 11x11 Board of the Hex game
 * It has a boolean attribute represents the 2 players, Blue or Red.
 * Blue needs to connect left side to right side to win.
 * Red needs to connect top side to bottom side to win.
 * Blue makes the first move.
 * */

class Board {
private:
    Hex hexBoard[11][11];
    bool player;                        // 0 - Blue player ; 1 - Red player

public:
    Board();
    //~Board();                         // Default constructor is used
    // Board(const Board& b)            // No copy constructor is used because only 1 board is necessary
    // operator =                       // Default copy assignment operator
    void insertHex();
    bool checkWin();
    bool checkWinRec(int i, int j);
    void uncheckAll();
    void printBoard();
    string getInput();
    bool checkInput(string input);
    int getPlayer();
    void changePlayer();
};


#endif //HW2_BOARD_H
