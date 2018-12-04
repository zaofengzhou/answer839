//
// Created by zfzhou on 12/4/2018.
//
#include <bits/stdc++.h>
using namespace std;

#define TIMES 6000000

struct T {
    int key, value;
};

/*
 * 模拟掷两颗骰子的点数之和，运行TIMES=6000000次的试验，
 * 程序中可以认为频率等于概率，计算各点数之和的概率，可知程序的输出
 *  1: 0.00
    2: 0.03
    3: 0.06
    4: 0.08
    5: 0.11
    6: 0.14
    7: 0.17
    8: 0.14
    9: 0.11
   10: 0.08
   11: 0.06
   12: 0.03
 */

/*
int main()
{
    int i;
    struct T a[12];
    for(i = 0; i < 12; i++) {
        a[i].key = i+1;
        a[i].value = 0;
    }
    srand((unsigned)time(0));
    for(i=0; i<TIMES; i++) {
        int v=(rand()%6+1) + (rand()%6+1);
        a[v-1].value++;
    }
    for(i=0; i<12; i++)
        printf("%2d: %.2f\n", a[i].key, (double)a[i].value/TIMES);
    return 0;
}
*/
