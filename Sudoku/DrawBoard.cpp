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
    sudokuPlane = {};
    Nums * num = new Nums;
    sudokuPlane = num->generateSudokuPlane();
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
            drawVerticalLines();
        }


        j += 3;
    }
    
    
}

//misnomer draws horizontal lines with numbers 
void Board::drawVerticalLines(){
    
    // ok I admit using a static variable isn't great - my bad
    static int z = 0;
    
    for(int i = 1; i<13; i++){
        if(i%4 == 0){
            cout<<"*  ";
        }
        else{
           
            cout<<"* "<<sudokuPlane[z]<<" ";
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






// used for testing

void Board::printNumValues(){

    for(int i = 0; i<27; i++){
        cout<<sudokuPlane[i]<<" ";
    }
    
}




