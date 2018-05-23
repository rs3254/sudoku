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
    
    vector<int> generateSuperArrY();
    bool yVectorCheck(vector<int> v1, vector<int> v2, vector<int> v3, int sVal, int endVal);
    
    vector<int> generateNumsX(vector<int> xVector);
    vector<int> generateNumsY();
    
    int randNum();
    
    bool contains(vector<int> v, int num); 
    friend class Board;
    
    
    
};

#endif /* NumberClass_hpp */
