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
#include <fstream>
#include <unistd.h>

using namespace std;



int main(int argc, const char * argv[]) {

    system("rm -f Solutions.txt");
    system("rm -f Soduku.txt");
    
    srand(int(time(0)));
    int finished;
    
    fstream sudokuFile;
    fstream solutionFile;
    sudokuFile.open("Sudoku.txt",fstream::out);
    solutionFile.open("Solutions.txt",fstream::out);
    
    cout<<"Generating Puzzle.\n"<<endl;
    Board *boardObj = new Board;
    streambuf *backup;
    backup = cout.rdbuf();
    
    cout.rdbuf(sudokuFile.rdbuf());
    cout<<"Press 1 in Xcode console when finished to display solutions\n"<<endl;
    cout<<"\n"<<endl;
    boardObj->drawBoard();
    sudokuFile.close();

    
    
    // write into solutions file
    cout.rdbuf(solutionFile.rdbuf());
    cout<<"Solutions\n"<<endl;
    boardObj->drawBoard(1);
    cout<<"\n"<<endl;
    solutionFile.close();

    
    cout.rdbuf(backup);
    system("Open Sudoku.txt");
    
    cout<<"The Sudoku puzzle is in Sudoku.txt. Solve it. Press 1 when finished to display solutions.\n"<<endl;
    

    
    cout<<""<<endl;
    
    cin>>finished;
    if(finished == 1){

        system("Open Solutions.txt");

    }
    else{
        
        cout<<"invalid input program terminating"<<endl;
    }

    



    delete boardObj;
    
    
    

    return 0;
}
