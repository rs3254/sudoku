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
    
    // x coordinates
    x = {1, 2,3,4,5,6,7,8,9};
    // y coordinates
    y = {1, 2,3,4,5,6,7,8,9};
    
    Nums * num = new Nums;

    x = num->generateNumsX(x);
    y =  num->generateNumsY(y);
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
    int z = 0;
    Nums * num = new Nums;
    for(int i = 1; i<13; i++){
        if(i%4 == 0){
            cout<<"*  ";
        }
        else{
           
            cout<<"* "<<y[z]<<" ";
            z += 1;
            
            if(z == 9){
                updateYValues();
            }
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


void Board::updateYValues(){
    
    Nums * num = new Nums;
    y = num->generateNumsY(y);
}

void Board::printValues(){
    for(int i = 0; i<x.size(); i++){
        cout<<x[i]<<" ";
    }


}


