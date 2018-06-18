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
#include <map>
using namespace std;


class Nums {
    
    // misnomer contains 3 rows of values
    vector<int> generateSuperArrY(vector<int> block1 = {});
    
    // will contain all sudoku numbers when finished
    vector<int> generateSudokuPlane(); 
    
    vector<int> generateRows(vector<int> v1= {});
    vector<int> generateThirdRow(vector<int> v1, vector<int> v2);
    vector<int> generateForbiddenNums(int sVal, int endVal, vector<int> v1, vector<int> v2);
    vector<int> thirdLineHelper(vector<int> forbiddenNums, vector<int> v3);
    
    
    bool contains(vector<int> v, int num);
    bool checkRows(vector<int> v1, vector<int> v2, int sVal, int endVal);
    bool checkPairOfBlocks(vector<int> v1, vector<int> v2);
    
    vector<int> generateSecondSuperArr(vector<int> block1);
    vector<int> generateThirdSuperArr(vector<int> block1);
    vector<int> genLastLine(vector<int> superBlock);
    vector<int> genLastNums(vector<int> superBlock);
    
    vector<int> merge(vector<int> v1, vector<int> v2, vector<int>v3); 
    
    bool checkDuplicates(vector<int> v1); 

    
    vector<int> genRowsFast(vector<int> v1 = {}); 
    
    friend class Board;
    int randNum();
    
    
};

#endif /* NumberClass_hpp */
