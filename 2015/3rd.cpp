//
// Created by zfzhou on 2018/12/2.
//
#include <bits/stdc++.h>
using namespace std;

#include "../util/array.h"
/*
 * 设A和B是两个已有元素个数分别为n和m的按升序排序的整数数组，现在要合并A和B,并且合并后仍然按照升序排序。
 * 假设数组A中有足够的空间存放合并后的结果，要求在不使用临时缓冲区的情况下实现合并的功能。写出函数定义。
 * 函数原型为：void Merge(int *A,int n,int *B,int m);
 */

void Merge(int *A,int n,int *B,int m) {
    int p1 = n-1, p2 = m-1, r = n+m-1;  //r为正确元素存放的位置
    while(p1 >= 0 && p2 >= 0) {
        if(A[p1] >= B[p2]) {
            A[r--] = A[p1--];
        } else {
            A[r--] = B[p2--];
        }
    }
    while(p2 >= 0) {
        A[r--] = B[p2--];
    }
}

/*
int main()
{
    int a[10] = {1, 3, 5, 7};
    int b[] = {2, 4, 6};
    printArray(a, 10);
    Merge(a, 4, b, 3);
    printArray(a, 10);
    return 0;
}
*/
