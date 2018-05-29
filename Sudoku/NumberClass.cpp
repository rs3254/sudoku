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
    
    //blocks contain 3 correct sudoku rows -> also known as "superArrY".
    vector<int> block1;
    vector<int> block2;
    vector<int> block3;
    
    block1 = generateSuperArrY();
    block2 = generateSecondSuperArr(block1);
    

    while(checkPairOfBlocks(block1, block2)== false){
        block2 = generateSecondSuperArr(block1);

    }
    
    block1.insert(block1.end(), block2.begin(), block2.end());
    
    block3 = generateThirdSuperArr(block1);

    
    
//    block1.insert(block1.end(), block2.begin(), block2.end());
    block1.insert(block1.end(), block3.begin(), block3.end());
    
    
    return block1;
    
}


vector<int> Nums::generateSuperArrY(int num){
    
    
    vector<int> v1 = generateRows();
    vector<int> v2 = generateRows();

    while(checkRows(v1, v2, 0, 3)== false || checkRows(v1, v2, 3, 6)== false || checkRows(v1, v2, 6, 9)== false){
        v2 = generateRows();

    }
    
    vector<int> v3 = generateThirdRow(v1, v2);

    v1.insert(v1.end(), v2.begin(),v2.end());
    v1.insert(v1.end(), v3.begin(), v3.end());
    
    return v1;
    
}

//generate third "superArr" differently for saving time
vector<int> Nums::generateThirdSuperArr(vector<int> block1){
    
    
    vector<int> v1 = genLastNums(block1);
    
    while(checkDuplicates(v1) == false){
        v1 = genLastNums(block1);
       
    }
    
    
    block1.insert(block1.end(), v1.begin(), v1.end());
    
    
    vector<int> v2 = genLastNums(block1);
    
    while(checkDuplicates(v2) == false){
        v2 = genLastNums(block1);
        
    }
    
    
    block1.insert(block1.end(), v2.begin(), v2.end());
    vector<int> v3 = genLastLine(block1);


    
    v1.insert(v1.end(), v2.begin(), v2.end());
    v1.insert(v1.end(), v3.begin(), v3.end());

    
    return v1;
}


bool Nums::checkDuplicates(vector<int> v1){
    
    sort(v1.begin(), v1.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    if(v1.size() <9){
        return false;
    }
    else{
        return true;
    }
    
}

// generate last line differently to save time
vector<int> Nums::genLastLine(vector<int> superBlock){
    
    vector<int> lastLine;
    
    for(int i = 0; i< 9; i++){
        vector<int> yVec;
        for(int j = i; j<superBlock.size(); j+=9){
            yVec.push_back(superBlock[j]);
        }
        for(int z = 1; z<10; z++){
            if(contains(yVec, z) == false && contains(lastLine, z) == false){
                lastLine.push_back(z);
                break; 
            }
        }
        
    }
    
 
    return lastLine;
    
}

vector<int> Nums::genLastNums(vector<int> superBlock){
    
    
    vector<int> lastLine;
    
    for(int i = 0; i< 9; i++){
        vector<int> yVec;
        for(int j = i; j<superBlock.size(); j+=9){
            yVec.push_back(superBlock[j]);
        }
        int z = rand()%9 + 1;
        if(contains(yVec, z) == false && contains(lastLine, z) == false){
                lastLine.push_back(z);
            }
        else{
            while(contains(yVec, z) == true || contains(lastLine, z) == true){
                 int z = rand()%9 + 1;
                if(contains(yVec, z) == false){
                    lastLine.push_back(z);
                    break;
                }
            }
        }

        }
        
 
    return lastLine;
    
    
}



// builds second block, "superArr",  in a quick way
vector<int> Nums:: generateSecondSuperArr(vector<int> block1){
    vector<int> v1 = generateRows(block1);
    block1.insert(block1.end(), v1.begin(), v1.end());
    vector<int> v2 = generateRows(block1);
    
    while(checkRows(v1, v2, 0, 3)== false || checkRows(v1, v2, 3, 6)== false || checkRows(v1, v2, 6, 9)== false){
        v2 = generateRows(block1);
        
    }
    
    vector<int> v3 = generateThirdRow(v1, v2);
    
    v1.insert(v1.end(), v2.begin(),v2.end());
    v1.insert(v1.end(), v3.begin(), v3.end());
    
    return v1;
    
}

// ugly but has optimizations that save time
vector<int> Nums::generateRows(vector<int> v1){
    
    
    vector<int> newV;
    
    for(int j = 0; j<9; j++){
        vector<int> y1;
        for(int i = j; i <v1.size(); i+= 9){
            y1.push_back(v1[i]);
        }
        int randNum = (rand() % 9) + 1;
        if(v1.size()==0 && contains(newV, randNum) == false){
            newV.push_back(randNum);

        }
        else if(contains(newV, randNum) == false && contains(y1, randNum) == false){
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





vector<int> Nums::generateThirdRow(vector<int> v1, vector<int> v2){
    
    vector<int> v3;
    vector<int> forbiddenNums;
    
    for(int i = 0; i<7; i+=3){
        forbiddenNums = generateForbiddenNums(i, i+3, v1, v2);
        v3 = thirdLineHelper(forbiddenNums, v3);
    }

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




// helper functions


//actually checks each square to see that it is correct
bool Nums::checkRows(vector<int> v1, vector<int> v2, int sVal, int endVal){
    
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
