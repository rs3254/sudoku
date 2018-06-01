//
//  DrawBoard.cpp
//  Sudoku
//
//  Created by Ray Sabbineni on 5/19/18.
//  Copyright © 2018 Ray Sabbineni. All rights reserved.
//


#include "DrawBoard.hpp"
#include <iostream>
using namespace std;

// any space on the sudoku board can be represented as coordinate pairs, (x, y)
Board::Board() {
    

    // plane of sudoku numbers
    Nums * num = new Nums;
    sudokuPlane = num->generateSudokuPlane();
    sudokuPuzzle = hiddenNums(sudokuPlane); 
    delete num;
    
}

void Board::drawBoard(int num){
    int j = 3;
    int z = 0;
    vector<int> v1;
    if(num != 1){
         v1 = sudokuPuzzle;
    }
    else{
        v1 = sudokuPlane;
    }
    for(int i = 0; i <12; i++){
        if(j%12 == 0 && j != 0){
            drawHorizontalLines();
            cout<<"\n";
        }
        else{
            drawHorizontalLines();
            drawLinesWithNums(v1, z);
            z += 9;
            
        }
        j += 3;
    }
}



void Board::drawLinesWithNums(vector<int> sPlane, int count){
    
    
    for(int i = 1; i<13; i++){
        if(i%4 == 0){
            cout<<"*  ";
        }
        else{
            if(sPlane[count] != 0){
                cout<<"* "<<sPlane[count]<<" ";
                
            }else{
                cout<<"* "<<" "<<" ";
            }
            count += 1;
        }
    }
    cout<<"\n";
}





void Board::drawHorizontalLines(){
    int j = 1;
    for (int i =0; i<42; i++){
    
        if(j%14 == 0){
            cout<<"  ";
        }
        else{
            cout<<"*";
        }
        
        j+= 1;
    }
    cout<<"\n";
    
    
}


vector<int> Board::hiddenNums(vector<int> sudokuPlane){
    int randNums;
    vector<int> v1 = sudokuPlane;
    for(int i =0; i<9; i++){
        randNums = rand()%81 + 1;
        v1[randNums] = 0;
    }
    
    return v1;
}


// used for testing

void Board::printNumValues(){

    for(int i = 0; i<27; i++){
        cout<<sudokuPlane[i]<<" ";
    }
    
}




