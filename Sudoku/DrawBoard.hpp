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
using namespace std; 

class Board{
    
    public:
    
        vector <int> x;
        vector <int> y;
    
        Board();
    
        void drawBoard();
        void drawVerticalLines();
        void drawHorizontalLines();
        void generateRow():
    
};


#endif /* DrawBoard_hpp */
