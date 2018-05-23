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

    srand(int(time(0)));

    
    cout<<"Below is the sudoku puzzle\n"<<endl;
    Board *boardObj = new Board;
    boardObj->drawBoard();
    
    cout<<""<<endl;
    
//    for(int i = 0; i<boardObj->y.size(); i++){
//        cout<<boardObj->y[i]<<" ";
//    }
    
    
    cout<<"\n"<<endl;
    
    
    
    return 0;
}
