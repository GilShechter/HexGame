//
// Created by gilsh on 05/12/2021.
//

#ifndef HW2_HEX_H
#define HW2_HEX_H
#include <iostream>
using namespace std;

/* Class Hex
 * Hex represent one hexagonal cell in the board
 * It has value attribute that can obtain  'O', 'R' or 'B'
 * It has a boolean attribute for the winning check method
 * */

class Hex {
private:
    char value;
    bool check;
public:
    Hex();                              // Constructor
    // Hex(const Hex &h);                  No copy constructor is used
    // ~Hex();                             Default destructor is used
    // operator =                          Default copy assignment operator
    bool setValue(char value);
    char getValue();
    void setCheck();
    bool isChecked();
};


#endif //HW2_HEX_H
