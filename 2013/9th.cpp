//
// Created by zfzhou on 12/10/2018.
//

#include <bits/stdc++.h>
using namespace std;

#include "../util/array.h"

/*
 * 已知一组数(9,2,8,6,1)，分别采用插入排序和合并排序进行排序，写出排序过程中每遍处理的结果
 * 插入排序：
 * 2 9 8 6 1
   2 8 9 6 1
   2 6 8 9 1
   1 2 6 8 9
 * 归并排序：
 * 2,9,8,6,1
 * 2,8,9,6,1
 * 2,8,9,1,6
 * 1,2,6,8,9
 */

/*
int main()
{
    //int a[] = {12, 11, 13, 5, 6, 7};
    //int a[] = {38, 27, 43, 3, 9, 82, 10};
    int a[] = {9, 2, 8, 6, 1};
    //int arr[1][2][2] = {{{1,2},{1,2}}};

    int arr_size = sizeof(a)/sizeof(a[0]);
    //printArray(a, arr_size);

    //mergeSort(a, 0, arr_size-1);
    //insertSort(a, arr_size);
    //printArray(a, arr_size);

    return 0;
}*/
