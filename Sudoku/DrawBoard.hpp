//
//  DrawBoard.hpp
//  Sudoku
//
//  Created by Ray Sabbineni on 5/19/18.
//  Copyright © 2018 Ray Sabbineni. All rights reserved.
//

#ifndef DrawBoard_hpp
#define DrawBoard_hpp

#include <stdio.h>
#include <vector>
#include "NumberClass.hpp"

using namespace std; 

class Board{
    
    public:
        // all nums -> finished puzzle
        vector <int> sudokuPlane;
        // some nums left blank for user to solve 
        vector<int> sudokuPuzzle; 
    
        Board();
        void drawBoard(int num = 0);
    
        // basically just draws lines that consists of stars
        void drawHorizontalLines();
    
        //outputs horizontal lines with numbers
        void drawLinesWithNums(vector<int> sPlane, int count);
    
    
    
        // generates random places in the puzzle that will be left blank so the user
        // has something to do.
        vector<int> hiddenNums(vector<int> sudokuPlane);
    
    
    

    
        // used for testing 
        void printNumValues();

    
};


#endif /* DrawBoard_hpp */
