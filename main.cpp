#include "Board.h"

int main() {
    Board* b = new Board();
    int movesPlayed = 0;
    while(true){
        b->printBoard();
        b->getPlayer() ? cout << "R:" : cout << "B:";
        cout << endl;
        b->insertHex();
        movesPlayed++;
        if (movesPlayed >= 22){
            if ( b->checkWin() ) break;
            b->uncheckAll();
        }
        b->changePlayer();
    }
    b->getPlayer() ? cout << "R" : cout << "B";
    cout << " wins the game." << endl;
    return 0;
}
