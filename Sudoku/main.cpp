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

    int finished;
        
    
    cout<<"Below is the sudoku puzzle. Solve it an another piece of paper. Press 1 when finished to display solutions.\n"<<endl;
    
    Board *boardObj = new Board;
    boardObj->drawBoard();
    cout<<""<<endl;
    
    cin>>finished;
    if(finished == 1){
        cout<<" "<<endl;
        cout<<" "<<endl;
        cout<<"solution below"<<endl;
        boardObj->drawBoard(1);


    }
    else{
        cout<<"invalid input program terminating"<<endl;
    }

    delete boardObj;
    
    
    
    
//    
//    vector<int> arr = shuffle();
//    for(int i =0; i<9; i++){
//        cout<<arr[i]<<endl;
//    }
//
    return 0;
}
