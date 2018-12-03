//
// Created by zfzhou on 12/3/2018.
//
#include <bits/stdc++.h>
using namespace std;

#include "../util/array.h"

/*
 * 分别写出用冒泡排序和选择排序对序列[7,3,8,2,9]的每一趟过程
 * 冒泡排序：
 * 3,7,2,8,9
 * 3,2,7,8,9
 * 2,3,7,8,9
 * 2,3,7,8,9
 * 选择排序：
 * 2,3,8,7,9
 * 2,3,8,7,9
 * 2,3,7,8,9
 * 2,3,7,8,9
 */

void bubbleSort(int a[], int n) {
    for(int i = 0; i < n-1; i++) {  //n-1趟
        for(int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1]) {
                swap(a, j, j+1);
            }
        }
        printArray(a, 5);
    }
}

void selectSort(int a[], int n) {

    int minIdx;
    for(int i = 0; i < n-1; i++) {
        minIdx = i;
        for(int j = i+1; j < n-1; j++) {
            if(a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        swap(a, i, minIdx);
        printArray(a, 5);
    }
}

/*
int main()
{
    int a[] = {7, 3, 8, 2, 9};
//    bubbleSort(a, 5);
    selectSort(a, 5);
    printArray(a, 5);
    return 0;
}*/
