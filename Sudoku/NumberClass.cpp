//
//  NumberClass.cpp
//  Sudoku
//
//  Created by Ray Sabbineni on 5/20/18.
//  Copyright © 2018 Ray Sabbineni. All rights reserved.
//

#include "NumberClass.hpp"
#include <iostream>

using namespace std; 




vector<int> Nums::generateSudokuPlane(){
    
    vector<int> sudokuV;
    
    //blocks contain 3 correct sudoku rows -> also known as superArrY'.
    vector<int> block1;
    vector<int> block2;
    vector<int> block3;
    
    block1 = generateSuperArrY();
    block2 = generateSecondSuperArr(block1);
    block3 = generateSuperArrY();
    
    
    
    while(checkPairOfBlocks(block1, block2)== false){
        block2 = generateSecondSuperArr(block1);

    }
    
    block1.insert(block1.end(), block2.begin(), block2.end());
    block1.insert(block1.end(), block3.begin(), block3.end());
    
    
    return block1;
    
}


vector<int> Nums::generateSuperArrY(int num){
    
    
    vector<int> v1 = generateNumsY();
    vector<int> v2 = generateNumsY(); 

    while(yVectorCheckMinor(v1, v2, 0, 3)== false || yVectorCheckMinor(v1, v2, 3, 6)== false || yVectorCheckMinor(v1, v2, 6, 9)== false){
        v2 = generateNumsY();

    }
    
    vector<int> v3 = generateNumYThirdLine(v1, v2);

    v1.insert(v1.end(), v2.begin(),v2.end());
    v1.insert(v1.end(), v3.begin(), v3.end());
    
    return v1;
    
}


// builds second block in a quick waw
vector<int> Nums:: generateSecondSuperArr(vector<int> block1){
    vector<int> v1 = generateYNumsWithVerticalCheck(block1);
    block1.insert(block1.end(), v1.begin(), v1.end());
    vector<int> v2 = generateYNumsWithVerticalCheck(block1);
    
    while(yVectorCheckMinor(v1, v2, 0, 3)== false || yVectorCheckMinor(v1, v2, 3, 6)== false || yVectorCheckMinor(v1, v2, 6, 9)== false){
        v2 = generateYNumsWithVerticalCheck(block1);
        
    }
    
    vector<int> v3 = generateNumYThirdLine(v1, v2);
    
    v1.insert(v1.end(), v2.begin(),v2.end());
    v1.insert(v1.end(), v3.begin(), v3.end());
    
    return v1;
    
}

// need this to build second block otherwise takes to long
vector<int> Nums::generateYNumsWithVerticalCheck(vector<int> v1){
    
    
    vector<int> newV;
    
    for(int j = 0; j<9; j++){
        vector<int> y1;
        for(int i = j; i <v1.size(); i+= 9){
            y1.push_back(v1[i]);
        }
        int randNum = (rand() % 9) + 1;
        if(contains(newV, randNum) == false && contains(y1, randNum) == false){
            newV.push_back(randNum);
        }
        else{
            while (contains(newV, randNum)== true || contains(y1, randNum) == true){
                randNum = (rand() % 9) + 1;
                if(contains(newV, randNum)== false){
                    newV.push_back(randNum);
                    break;
                }
              
            }
        }
    }
    
    return newV;
}





vector<int> Nums::generateForbiddenNums(int sVal, int endVal, vector<int>v1, vector<int> v2){
    
    vector<int> forbiddenNums;
    
    for(int i= sVal; i<endVal; i++){
        forbiddenNums.push_back(v1[i]);
        forbiddenNums.push_back(v2[i]);
    }
    
    
    return forbiddenNums; 
    
}





vector<int> Nums::generateNumYThirdLine(vector<int> v1, vector<int> v2){
    
    vector<int> v3;
    vector<int> forbiddenNums;
    
    
    forbiddenNums = generateForbiddenNums(0, 3, v1, v2);
    v3 = thirdLineHelper(forbiddenNums, v3);
    
    
    forbiddenNums = generateForbiddenNums(3, 6, v1, v2);
    v3 = thirdLineHelper(forbiddenNums, v3);
    
    
    forbiddenNums = generateForbiddenNums(6, 9, v1, v2);
    v3 = thirdLineHelper(forbiddenNums, v3);
    

    return v3;
}


vector<int> Nums::thirdLineHelper(vector<int> forbiddenNums,  vector<int>  v3){


    for(int i=1; i<10; i++){
        if(contains(forbiddenNums, i)== false){
            v3.push_back(int(i));
        }
    }
    forbiddenNums.clear();
    
    return v3;

}

// try to optimize this ? 
vector<int> Nums::generateNumsY(){

    vector<int> newV;
    
    for(int j = 0; j<9; j++){
        int randNum = (rand() % 9) + 1;
        if(contains(newV, randNum) == false){
            newV.push_back(randNum);
        }
        else{
            while (contains(newV, randNum)== true){
                randNum = (rand() % 9) + 1;
                if(contains(newV, randNum)== false){
                    newV.push_back(randNum);
                    break;
                }
            }
        }
    }

    return newV;
}





// helper functions

bool Nums::yVectorCheckMinor(vector<int> v1, vector<int> v2, int sVal, int endVal){
    
    for(int i =sVal; i<endVal;i++){
        for(int j = sVal; j<endVal; j++){
            if(v1[i]==v2[j]){
                return false;
            }
        }
    }
    return true;
}


bool Nums::checkPairOfBlocks(vector<int> v1, vector<int> v2){
    
    
    for(int j = 0; j<9; j++){
        if(v1[j] == v2[j] || v1[j] == v2[j+9] || v1[j] == v2[j+18]){
            return false;
        }
        if(v1[j+9] == v2[j] || v1[j+9] == v2[j+9] || v1[j+9] == v2[j+18]){
            return false;
        }

        if(v1[j+18] == v2[j] || v1[j+18] == v2[j+9] || v1[j+18] == v2[j+18]){
            return false;
        }
        
    }
    
    return true;
}



bool Nums::contains(vector<int> v, int num){
    
    if(find(v.begin(), v.end(), num)!= v.end()){
        return true;
    }
    else{
        return false;
    }
    
}

int Nums::randNum(){
    int randNum = (rand()%9) + 1;
    return randNum;
}
