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