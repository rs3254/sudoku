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
    
        vector <int> sudokuPlane;
        vector<int> sudokuPuzzle; 
    
        Board();
        void drawBoard();
        void drawSolution();
        void drawVerticalLines(vector<int> sPlane);
        void drawVerticalLines2(vector<int> sPlane); 
        void drawHorizontalLines();
    
        vector<int> hiddenNums(vector<int> sudokuPlane);
    
        // used for testing 
        void printNumValues();

    
};


#endif /* DrawBoard_hpp */
