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



vector<int> Nums::generateNumsX(vector<int> xVector){

    for(int j = 0; j<xVector.size(); j++){
        int randNum = (rand() % 9) + 1;
        xVector[j] = randNum;
    }

    return xVector;
    
}



vector<int> Nums::generateNumsY(vector<int> yVector){
//    srand(int(time(0)));
    vector<int> newV;
    
    for(int j = 0; j<yVector.size(); j++){
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
