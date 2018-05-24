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
    block2 = generateSuperArrY();
    block3 = generateSuperArrY();
    
    
    
    while(checkPairOfBlocks(block1, block2)== false){
        block2 = generateSuperArrY();

    }
    
    block1.insert(block1.end(), block2.begin(), block2.end());
    block1.insert(block1.end(), block3.begin(), block3.end());
    
    
    return block1;
    
}


vector<int> Nums::generateSuperArrY(){
    
    
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


vector<int> Nums::generateNumYThirdLine(vector<int> v1, vector<int> v2){
    
    vector<int> v3;
    vector<int> forbiddenNums;
    
    for(int i =0; i<3; i++){
        forbiddenNums.push_back(v1[i]);
        forbiddenNums.push_back(v2[i]);

    }
    

    
    for(int i = 1; i<10; i++){
        if(contains(forbiddenNums, i)== false){
            v3.push_back(i);
        }
        
    }
    
    forbiddenNums.clear();
    for(int i =3; i<6; i++){
        forbiddenNums.push_back(v1[i]);
        forbiddenNums.push_back(v2[i]);

    }
    
    
    for(int i = 1; i<10; i++){
        if(contains(forbiddenNums, i)== false){
            v3.push_back(i);
        }
        
    }
    
    
    forbiddenNums.clear();
    
    for(int i =6; i<9; i++){
        forbiddenNums.push_back(v1[i]);
        forbiddenNums.push_back(v2[i]);

    }
    

    
    
    
    for(int i = 1; i<10; i++){
        if(contains(forbiddenNums, i)== false){
            v3.push_back(i);
        }
        
    }

    return v3;
}


vector<int> Nums::generateNumsY(){
//    srand(int(time(0)));
    vector<int> newV;
    
    // because 9 elements in a sudoku row 
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
    
    for(int i = 0; i<9; i++){
        for(int j=i; j<v1.size(); j+=9){
            if(v1[j] == v2[j]){
                return false;
            }
    
        
            if((j+9 < 27) && v1[j] == v2[j+9]){
                return false;
            }

            if((j+18 < 27) && v1[j] == v2[j+18]){
                return false;
            }
          

        }

    }
    
    return true;
}


bool Nums::yVectorCheck(vector<int> v1, vector<int> v2, vector<int> v3, int sVal, int endVal){
    
    // this is necessary.
    for(int i = sVal; i<endVal; i++){
        for(int j = sVal; j< endVal; j++){
            // if statement provides slight optimization to run time
            if(v1[i]==v2[j]){
                return false;
            }
            for(int z = sVal; z< endVal; z++){
                if(v1[i]== v2[j] || v1[i] == v3[z] || v2[j] == v3[z]){
                    return false;
                }
            }
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
