//
// Created by zfzhou on 2018/12/2.
//
#include <bits/stdc++.h>
using namespace std;

/*
 * 文件中存放着N^2*N^2(3<N<6)大小的矩阵,矩阵元素均为[1,N^2]的整数。请你写程序判断文件中保存的矩阵是否满足数独的要求
 */

bool check(int a, bool used[]) {
    if(used[a-1] == true)
        return false;
    else {
        used[a-1] = true;
        return true;
    }
}

bool isValidSudoku(int board[][9], int n) {
    int rows = n*n, cols = n*n;

    for(int i = 0; i < rows; i++) {
        bool used1[9] = {false}, used2[9] = {false}, used3[9] = {false};
        for(int j = 0; j < cols; j++) {
            if(!check(board[i][j], used1))  //check rows
                return false;
            if(!check(board[j][i], used2))  //check cols
                return false;
            int rowIdx = n * (i/n);    //each block's start point
            int colIdx = n * (i%n);
            if(!check(board[rowIdx+j/n][colIdx+j%n], used3))    //check blocks
                return false;
        }
    }
    return true;
}

int main()
{
    int board[][9] ={{5,3,4,6,7,8,9,1,2},
                     {6,7,2,1,9,5,3,4,8},
                     {1,9,8,3,4,2,5,6,7},
                     {8,5,9,7,6,1,4,2,3},
                     {4,2,6,8,5,3,7,9,1},
                     {7,1,3,9,2,4,8,5,6},
                     {9,6,1,5,3,7,2,8,4},
                     {2,8,7,4,1,9,6,3,5},
                     {3,4,5,2,8,6,1,7,9}
                    };
    cout << isValidSudoku(board, 3) << endl;
    return 0;
}

