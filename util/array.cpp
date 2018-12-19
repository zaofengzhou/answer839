//
// Created by zfzhou on 2018/12/2.
//

#include "array.h"
#include "bits/stdc++.h"
using namespace std;

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

/*
 * 第i趟排序为：在含有i-1个元素的有序子序列中插入一个元素，使之成为含有i个元素的有序字序列。
 * 在查找插入位置的过程中，同时后移元素。
 */
void insertSort(int a[], int n)
{
    for(int i = 1; i < n; i++) {
        int j = i-1;
        int temp = a[i];    //暂存要插入的元素，复制过程中会丢失
        while(j >=0 && temp < a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;  //插入正确位置
        printArray(a, n);
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = a[l+i];
    for(j = 0; j < n2; j++)
        R[j] = a[m+1+j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }
    while(i < n1) {
        a[k++] = L[i++];
    }
    while(j < n2) {
        a[k++] = R[j++];
    }
    printArray(a, 5);
}

/*
 *  Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves.
 *  The merge() function is used for merging two halves.
 *  The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
 */

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int a[], int l, int r)
{
    int m;
    if(l < r) {
        m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);

        merge(a, l, m, r);
    }
}

/*
int main()
{
    //int a[] = {12, 11, 13, 5, 6, 7};
    //int a[] = {38, 27, 43, 3, 9, 82, 10};
    int a[] = {9, 2, 8, 6, 1};
    int arr_size = sizeof(a)/sizeof(a[0]);
    printArray(a, arr_size);
    mergeSort(a, 0, arr_size-1);
    //printArray(a, arr_size);
    return 0;
}
*/





