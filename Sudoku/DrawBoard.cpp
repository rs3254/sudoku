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

void Board::drawBoard(){
    int j = 3;
    for(int i = 0; i <12; i++){
        if(j%12 == 0 && j != 0){
            drawHorizontalLines();
            cout<<"\n";
        }
        else{
            drawHorizontalLines();
            drawVerticalLines(sudokuPuzzle);
            
        }


        j += 3;
    }
    
}

void Board::drawSolution(){
    int j = 3;
    for(int i = 0; i <12; i++){
        if(j%12 == 0 && j != 0){
            drawHorizontalLines();
            cout<<"\n";
        }
        else{
            drawHorizontalLines();
            drawVerticalLines2(sudokuPlane);
            
        }
        
        
        j += 3;
    }
    
}


//misnomer draws horizontal lines with numbers 
void Board::drawVerticalLines(vector<int> sPlane){
    
    // ok I admit using a static variable isn't great - my bad
    static int z = 0;
    
    for(int i = 1; i<13; i++){
        if(i%4 == 0){
            cout<<"*  ";
        }
        else{
            if(sPlane[z] != 0){
                cout<<"* "<<sPlane[z]<<" ";

            }else{
                cout<<"* "<<" "<<" ";
            }
            z += 1;
            
        }
       
    }
    cout<<"\n";
}



// for drawing solutions
void Board::drawVerticalLines2(vector<int> sPlane){
    
    // ok I admit using a static variable isn't great - my bad
    static int z = 0;
    
    for(int i = 1; i<13; i++){
        if(i%4 == 0){
            cout<<"*  ";
        }
        else{
            if(sPlane[z] != 0){
                cout<<"* "<<sPlane[z]<<" ";
                
            }else{
                cout<<"* "<<" "<<" ";
            }
            z += 1;
            
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




