//
//  NumberClass.hpp
//  Sudoku
//
//  Created by Ray Sabbineni on 5/20/18.
//  Copyright © 2018 Ray Sabbineni. All rights reserved.
//

#ifndef NumberClass_hpp
#define NumberClass_hpp

#include <stdio.h>
#include <vector>
using namespace std;


class Nums {
    
    vector<int> generateNumsX(vector<int> xVector);
    vector<int> generateNumsY(vector<int> yVector);
    
    int randNum();
    
    bool contains(vector<int> v, int num); 
    friend class Board;
    
};

#endif /* NumberClass_hpp */
