//
// Created by zfzhou on 2018/12/6.
//
#include <stdio.h>
#include <stdlib.h>

#include "../util/array.h"
/*
 * 1.不正确，因为指针类型的变量不能做加法运算，指针与指针只可以进行减法运算，所以可以改为
 * middle=first+(last-first)/2 指针与指针相减的结果是一个整数，指针可以与整数进行加法运算。
 * 2.不完全正确，first+last可能数据溢出（虽然一般不会，可能开不出那么大的数组）
 * 为防止加法溢出，可以写为middle=first+(last-first)/2
 * 3.写代码
*/

int compareints(const void *a, const void *b)
{
    if( *(int*)a < *(int*)b )   return -1;
    if( *(int*)a > *(int*)b )   return 1;
    if( *(int*)a == *(int*)b )   return 0;
}

static int values[] = { 50, 20, 60, 40, 10, 30 };

/**
 *
 * @param key为要查找元素的地址
 * @param base为数组开始的地址
 * @param num为数组的元素个数
 * @param width为每个元素占的字节数
 * @param compare为数组排序时使用的比较函数
 * @return
 */
void *bsearch1(void *key, void *base, size_t num, size_t width,
               int (*compare)(const void *elem1, const void *elem2))
{
    size_t start = 0, end = num-1;
    int result;

    while(start <= end) {
        size_t mid = start + (end - start)/2;
        result = compare(key, base + mid*width);
        if(result == 0)
            return base + mid*width;
        else if(result < 0)
            end = mid-1;
        else
            start = mid+1;
    }
    return NULL;
}

void *bsearch2(void *key, void *base, size_t num, size_t width,
               int (*compare)(const void *elem1, const void *elem2))
{
    void *pivot;
    int result;

    while(num > 0) {
        pivot = base + (num >> 1) * width;
        result = compare(key, pivot);

        if(result == 0)
            return pivot;

        if(result > 0) {
            base = pivot + width;
            num--;
        }
        num >>= 1;
    }
    return NULL;
}

/*
int main()
{
    int *pItem;
    int key = 50;
    qsort(values, 6, sizeof(int), compareints);
    //printArray(values, 6);

    //pItem = (int*)bsearch(&key, values, 6, sizeof(int), compareints);
    //pItem = (int*)bsearch1(&key, values, 6, sizeof(int), compareints);
    pItem = (int*)bsearch2(&key, values, 6, sizeof(int), compareints);

    printf("%d\n", pItem - values);
    printf("%d\n", *pItem);

    return 0;
}
*/

