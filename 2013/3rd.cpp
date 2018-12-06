//
// Created by zfzhou on 12/6/2018.
//
#include <bits/stdc++.h>
using namespace std;

#include "../util/array.h"
/*
 * 1.不正确，因为指针类型的变量不能做加法运算，指针与指针只可以进行减法运算，所以可以改为 middle=first+(last-first)/2 指针与指针相减的结果是一个整数，指针可以与整数进行加法运算。
 * 2.不完全正确，first+last可能数据溢出（虽然一般不会，可能开不出那么大的数组） 为防止加法溢出，可以写为middle=last-(last-first)/2
 */

int compareints(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

static int values[] = { 50, 20, 60, 40, 10, 30 };

void *bsearch1(void* key,void* base,size_t num,size_t width,
        int(*compare)(const void* elem1, const void* elem2))
{
    size_t start = 0, end = num;
    int result;

    while(start <= end) {
        size_t mid = start + (end - start)/2;
        result = compare(key, (size_t*)base + mid*width);
        if(result == 0)
            return (size_t*)base + mid*width;
        else if(result < 0)
            end = mid-1;
        else
            start = mid+1;
    }
    return NULL;
}

int main()
{
    int *pItem;
    int key = 40;
    qsort(values, 6, sizeof(int), compareints);
    printArray(values, 6);

    //pItem = (int*)bsearch(&key, values, 6, sizeof(int), compareints);
    pItem = (int*)bsearch1(&key, values, 6, sizeof(int), compareints);

    cout << pItem - values << endl;
    cout << *pItem<< endl;
    return 0;
}
