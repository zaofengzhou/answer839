//
// Created by zfzhou on 11/13/2018.
//
/**
 * void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
 * base -- 指向要排序的数组的第一个元素的指针。
 * nitems -- 由 base 指向的数组中元素的个数。
 * size -- 数组中每个元素的大小，以字节为单位。
 * compar -- 用来比较两个元素的函数。
 */

#include<stdio.h>
#include<stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int cmp(const void* a, const void* b) {
    return ( *(int*)a - *(int*)b );
}

int cmp1(const void* a, const void* b) {
    return ( *(int*)b - *(int*)a );
}

/*int main()
{
    int n;

    printf("list before sort:\n");
    for( n = 0 ; n < 5; n++ ) {
        printf("%d ", values[n]);
    }
    printf("\n");

    qsort(values, 5, sizeof(int), cmp1);

    printf("list after sort:\n");
    for( n = 0 ; n < 5; n++ ) {
        printf("%d ", values[n]);
    }
    return 0;
}*/
