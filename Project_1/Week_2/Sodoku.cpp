/*
    Problem: Week 2 - Count number of sudoku solutions
    author: Vu Van Hao - 20215572
*/
#include<bits/stdc++.h>
int count = 0;

bool checked(int table[][9], int row, int column, int num){
    //check row
    for(int i = 0; i < 9; i++){
        if(table[row][i] == num)
            return false;
    }

    //check column
    for(int i = 0; i < 9; i++){
        if(table[i][column] == num)
            return false;
    }

    //check 3x3 sub-square

    int row_sub = row / 3;
    int column_sub = column / 3;
    for(int i = 3*row_sub; i < 3*row_sub + 3; i++){
        for(int j = 3*column_sub; j < 3*column_sub + 3; j++){
            if(table[i][j]  == num)
                return false;
        }
    }

    return true;
}

void sodoku(int table[][9], int row, int column){
    if(column == 9){
        if(row == 8)
            count++;
        else
            sodoku(table, row + 1, 0);

    }else if(table[row][column]  == 0){
        for(int i = 1; i <= 9; i++){
            if(checked(table, row, column, i)){
                table[row][column] = i;
                sodoku(table, row, column + 1);
                table[row][column] = 0;
            }
        }

    }else{
        sodoku(table, row, column + 1);
    }    
}

void input_table(int table[][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            std::cin >> table[i][j];
        }
    }
}

int main(){
    int table[9][9];
    input_table(table);
    sodoku(table, 0, 0);
    std::cout << count;
    return 0;
}