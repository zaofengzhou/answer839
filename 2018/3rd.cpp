//
// Created by zfzhou on 11/29/2018.
//
#include <bits/stdc++.h>
using namespace std;

#include "../util/array.h"
/*
 * 设计并定义一个排序函数sort(算法自定)对一个数组排序，
 * 要求数组元素个数，数组中元素的类型和排序标准都要有函数参数来指定.
 * qsort() ?
 */

/* printd函数: 打印十进制数n */
void printd(int n)
{
    if(n < 0) {
        putchar('-');
        n = -n;
    }
    if(n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

int cmp2(const void* a, const void* b)
{
    return ( *(int*)a - *(int*)b );
}

/*
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// qsort函数：以递增顺序对v[left] ...v[right]进行排序
void qsort(int v[], int left, int right)
{
    int i, last;

    if(left >= right)   // 若数组包含的元素少于两个，则不执行任何操作
        return;
    swap(v, left, (left+right)/2);  //将划分子集的元素移动到v[0]
    last = left;
    for(i = left+1; i <= right; i++)    //划分子集
        if(v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);    //恢复划分子集的元素

    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
*/

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j)
{
    void* temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort1(void *v[], int left, int right, int (*comp)(const void *,const void *))
{
    int i, last;

    if(left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for(i = left+1; i <= right; i++)
        if((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort1(v, left, last-1, comp);
    qsort1(v, last+1, right, comp);
}

/*
int main()
{
    //char *a[] = {"3", "5", "4", "2", "1"};
    int a[] = {3, 5, 4, 2, 1};
    printArray(a, 5);
    //qsort(a, 5, sizeof(int), cmp2);
    //printd(123);
    qsort1((void **)a, 0, 4, cmp2);

    printArray(a, 5);

    return 0;
}
 */

