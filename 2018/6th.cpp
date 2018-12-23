#include <bits/stdc++.h>
using namespace std;

/*
 * 一个数组A[N]中元素类型为整型，请写一个高效的函数将其调整为左右两部分，
 * 使得左边元素为奇数，右边部分为偶数，并分析它的时间复杂度
 */

void printA(int a[], int n)
{
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

//two pointer TimeComplexity O(n)
/*
 * 类似快排，使用两根指针l, r同时从左右两边遍历，当左边读到偶数，右边读到奇数时，
 * 交换着两个数的值，直到l = r。
 */
void classify(int *a, int n)
{
    int l = 0, r = n-1;
    while(l < r) {
        while(l < r && a[l] % 2 == 1)   //从前往后找到一个偶数
            l++;
        while(l < r && a[r] % 2 == 0)   //从后往前找到一个奇数
            r--;
        if(l < r) {
            int temp = a[l];
            a[l] = a[r];
            a[r] = temp;
        }
    }
}

/*
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    printA(a, sizeof(a)/sizeof(a[0]));
    classify(a, 6);
    printA(a, 6);
}*/
