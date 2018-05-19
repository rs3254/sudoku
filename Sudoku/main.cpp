//
//  main.cpp
//  Sudoku
//
//  Created by Ray Sabbineni on 5/19/18.
//  Copyright © 2018 Ray Sabbineni. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "DrawBoard.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    
    cout<<"Below is the sudoku puzzle\n"<<endl;
    Board *boardObj = new Board;
    boardObj->drawBoard();
    
    cout<<""<<endl;
    
    return 0;
}
