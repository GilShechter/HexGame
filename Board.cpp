//
// Created by gilsh on 05/12/2021.
//

#include "Board.h"

Board::Board(){
    player = false;
}
//Board::~Board();

void Board::insertHex(){
    string input;
    int row;                    // A-Z
    int col;                    // 1-11
    char currPlayer;            // 'R' or 'B'
    while(true){
        input = getInput();
        col = input[0] - 'A';
        input.erase(0, 1);
        row = atoi(input.c_str()) - 1;
        getPlayer() ? currPlayer = 'R' : currPlayer = 'B';
        if (hexBoard[row][col].setValue(currPlayer)){
            break;
        }
    }
}

void Board::printBoard() {
    string spaces = "";
    for (int i=0; i<11; i++){
        cout << spaces;
        for (int j=0; j<11; j++){
            cout << hexBoard[i][j].getValue();
            if (j != 10) cout << " ";
        }
        cout << endl;
        spaces += " ";
    }
}


bool Board::checkWinRec(int i, int j){
    if (i < 0 || j < 0 || i > 10 || j > 10) return false;
    if (getPlayer()){
        if (hexBoard[i][j].getValue() != 'R') return false;
        if (i == 10 && hexBoard[i][j].getValue() == 'R') return true;
    }else{
        if (hexBoard[i][j].getValue() != 'B') return false;
        if(j == 10 && hexBoard[i][j].getValue() == 'B') return true;
    }
    if (hexBoard[i][j].isChecked()) return false;
    hexBoard[i][j].setCheck();
    bool a, b, c, d, e, f;
    a = checkWinRec(i, j+1);
    b = checkWinRec(i, j-1);
    c = checkWinRec(i+1, j);
    d = checkWinRec(i-1, j);
    e = checkWinRec(i+1, j-1);
    f = checkWinRec(i-1, j+1);
    return ( a || b || c || d || e || f);
}

bool Board::checkWin(){
    bool currPlayer = getPlayer();
    for (int i=0; i<11; i++){
        if (currPlayer){
            if (hexBoard[0][i].getValue() == 'R'){
                if (checkWinRec(0, i)) return true;
            }
        }else if(hexBoard[i][0].getValue() == 'B'){
            if (checkWinRec(i, 0)) return true;
        }
    }
    return false;
}

void Board::uncheckAll(){
    for (int i=0; i<11; i++){
        for (int j=0; j<11; j++){
            if (hexBoard[i][j].isChecked()) hexBoard[i][j].setCheck();
        }
    }
}


string Board::getInput(){
    string input;
    while (true){
        cin >> input;
        if (checkInput(input)){
            return input;
        }else{
            cout << "Invalid move; the game awaits a valid move." << endl;
        }
    }
}

bool Board::checkInput(string input){
    int index;
    string temp;
    if (input == "QUIT"){
        getPlayer() ? cout << "R: " : cout << "B: ";
        cout << "QUIT" << endl;
        exit(0);
    }
    temp = input;
    if (input.length() < 2 || input.length() > 3) return false;
    if (input[0] < 'A' || input[0] > 'K')         return false;

    temp.erase(0, 1);

    if (temp[0] < '1' || temp[0] > '9')           return false;
    if (temp.length() == 2){
        if (temp[1] < '0' || temp[1] > '1')       return false;
    }
    index = atoi(temp.c_str());
    if (index < 1 || index > 11)                  return false;

    return true;
}

int Board::getPlayer(){
    return this->player;
}

void Board::changePlayer(){
    player = !player;
}