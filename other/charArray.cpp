//
// Created by zfzhou on 2018/11/17.
//
#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void change(int &x) {
    x = 1;
}

/*
int main()
{
    int a = 1, b = 2;
    int *p1 = &a, *p2 = &b;
    swap(p1, p2);
    printf("a = %d b = %d\n", *p1, *p2);

    int x = 10;
    change(x);
    printf("%d\n", x);
    int c = 10;
    change(c);
    printf("%d\n", c);
//    int a[5] = {1, 2, 3, 4 ,5};
//    memset(a, 0, sizeof(a));
//    for(int i = 0; i < 5; i++) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//    memset(a, -1, sizeof(a));
//    for(int i = 0; i < 5; i++) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");

//    char str[15];
//    int i;
//    for(i = 0; i < 3; i++) {
//        str[i] = getchar();
//    }
//    str[i] = '\0';
//    puts(str);
    return 0;
}
*/


