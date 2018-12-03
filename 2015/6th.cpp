//
// Created by zfzhou on 12/3/2018.
//
#include <bits/stdc++.h>
using namespace std;

#include "../util/array.h"
/*
 * 顺序表原地逆置
 */

void reverse(int *a, int n) {
    for(int i = 0; i < n/2; i++) {
        int temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
}

/*
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    printArray(a, sizeof(a)/ sizeof(a[0]));
    reverse(a, sizeof(a)/ sizeof(a[0]));
    printArray(a, sizeof(a)/ sizeof(a[0]));
    return 0;
}
*/
