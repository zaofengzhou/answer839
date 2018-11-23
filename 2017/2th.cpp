//
// Created by zfzhou on 11/6/2018.
//
#include <bits/stdc++.h>
using namespace std;

/*
 *
 * 将x从第p位开始的n个（二进制）位求反（即，1变成0，0变成1），x的其余各位保持不变
 * 建立一个从第p位开始n个为1，其余各位为0的屏蔽码，和x异或。x中从第p位开始，若为0，和1异或得1，取反；若为1，和1异或得0，亦取反。
 * 其余各位和0异或保持不变。
 * ~0 << n
 * ~(~0 << n)   最后n位为1，其余位为0
 * ~(~0 << n) << p+1-n  从第p位开始n个为1，其余各位为0
 */
unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << (p+1-n));
}

/*
int main()
{
    unsigned a = 20;
    //cout << bitset<sizeof(int)*8>(~(~0 << 3) << 2) << endl;
    cout << bitset<sizeof(int)*8>(a) << endl;
    cout << bitset<sizeof(int)*8>(invert(a, 4, 3)) << endl;
    cout << bitset<sizeof(int)*8>(invert(a, 5, 4)) << endl;
    return 0;
}
*/
