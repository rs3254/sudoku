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
    
    vector<int> x1;
    vector<int> x2;
    vector<int> x3;
    
    x1 = generateSuperArrY();
    x2 = generateSuperArrY();
    x3 = generateSuperArrY();
    
    
    
    return sudokuV;
    
}


vector<int> Nums::generateSuperArrY(){
    
    
    vector<int> v1 = generateNumsY();
    vector<int> v2 = generateNumsY();
    vector<int> v3 = generateNumsY();
    
    while (yVectorCheck(v1, v2, v3, 0, 3)== false || yVectorCheck(v1, v2, v3, 3, 6)== false || yVectorCheck(v1, v2, v3, 6, 9) == false){
        v2 = generateNumsY();
        v3 = generateNumsY();
    }

        
        
        
    v1.insert(v1.end(), v2.begin(),v2.end());
    v1.insert(v1.end(), v3.begin(), v3.end());
    
//    for(int i = 0; i<27; i++){
//        cout<<v1[i]<<" "; 
//    }
    return v1;
    
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

vector<int> Nums::generateNumsX(vector<int> xVector){
    
    for(int j = 0; j<xVector.size(); j++){
        int randNum = (rand() % 9) + 1;
        xVector[j] = randNum;
    }
    
    return xVector;
    
}



// helper functions


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
