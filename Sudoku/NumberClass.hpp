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
    
    // misnomer contains 3 rows of values
    vector<int> generateSuperArrY();
    
    // will contain all sudoku numbers when finished
    vector<int> generateSudokuPlane(); 
    
    vector<int> generateNumsY();
    vector<int> generateNumYThirdLine(vector<int> v1, vector<int> v2);
    vector<int> generateForbiddenNums(int sVal, int endVal, vector<int> v1, vector<int> v2);
    vector<int> thirdLineHelper(vector<int> forbiddenNums, vector<int> v3);
    
    
    bool contains(vector<int> v, int num);
    bool yVectorCheckMinor(vector<int> v1, vector<int> v2, int sVal, int endVal);
    bool checkPairOfBlocks(vector<int> v1, vector<int> v2);
    
    friend class Board;
    int randNum();
    
    
};

#endif /* NumberClass_hpp */
