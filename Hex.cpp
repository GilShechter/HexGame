//
// Created by gilsh on 05/12/2021.
//

#include "Hex.h"


Hex::Hex(){
    this->value = 'O';
    this->check = false;
}

bool Hex::setValue(char value){
    if( this->value == 'O' ){
        this->value = value;
        return true;
    }
    cout << "Invalid move; the game awaits a valid move." << endl;
    return false;
}

char Hex::getValue(){
    return this->value;
}

void Hex::setCheck(){
    check = !check;
}
bool Hex::isChecked(){
    return this->check;
}