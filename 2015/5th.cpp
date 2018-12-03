//
// Created by zfzhou on 2018/12/2.
//
#include <bits/stdc++.h>
using namespace std;

/*
 * 文件中存放着N^2*N^2(3<N<6)大小的矩阵,矩阵元素均为[1,N^2]的整数。请你写程序判断文件中保存的矩阵是否满足数独的要求
 */
#define MAXSIZE 9

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

void printSodoku(int board[][9], int n) {
    int rows = n*n, cols = n*n;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << board[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //按块遍历
//    for(int i = 0; i < rows; i++) {
//        for(int j = 0; j < cols; j++) {
//            int rowIdx = 3*(i/3);   //每块的起点
//            int colIdx = 3*(i%3);
//            cout << board[rowIdx+ (j/3)][colIdx+ (j%3)] << " ";
//        }
//        cout << endl;
//    }
    for(int r = 0; r < 3; r++) {
        for(int c = 0; c < 3; c++) {
            for(int i = r*3; i < r*3+3; i++) {
                for(int j = c*3; j < c*3+3; j++) {
                    cout << board[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
}

/*
int main()
{

//    int board[][9] ={{5,3,4,6,7,8,9,1,2},
//                     {6,7,2,1,9,5,3,4,8},
//                     {1,9,8,3,4,2,5,6,7},
//                     {8,5,9,7,6,1,4,2,3},
//                     {4,2,6,8,5,3,7,9,1},
//                     {7,1,3,9,2,4,8,5,6},
//                     {9,6,1,5,3,7,2,8,4},
//                     {2,8,7,4,1,9,6,3,5},
//                     {3,4,5,2,8,6,1,7,9}
//                    };
    FILE *fp;
    int N, size;
    fp = fopen("../2015/dataIN", "r");
    fscanf(fp, "%d", &N);
    size = N*N;
    int board[MAXSIZE][MAXSIZE] = {};   //不能用动态数组

//    int a[9];
//    for(int i = 0; i < size; i++)
//        fscanf(fp, "%d", a+i);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            fscanf(fp, "%d", &board[i][j]);
        }
    }
    //printSodoku(board, N);

    if(isValidSudoku(board, N))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
*/

