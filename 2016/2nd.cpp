//
// Created by zfzhou on 12/10/2018.
//
#include<bits/stdc++.h>
using namespace std;

int bitsSwapRequired(int x, int y)
{
    int a = x, b = y;
    unsigned mask = 1;  //屏蔽码
    int count = 0;

    for(int i = 0; i < 32; i++) {
        mask <<= i;
        if( (a & mask) != (b & mask) )   //取出对应位的值比较
            count++;
    }
    return count;
}

/*
int main()
{
    int x = 1, y = -2;
    cout << bitset<sizeof(int)*8>(y) << endl;
    cout << bitset<sizeof(int)*8>(x) << endl;
    cout << bitsSwapRequired(x, y) << endl;
    //cout << (01 & 01) << endl;
    return 0;
}
*/
