//
// Created by zfzhou on 11/29/2018.
//
/*
 * 定义函数getBits(unsigned x int p int n)，返回值是整数x的从第p位起向低位数的共n位。
 * 例如getBits(x,4,3)返回x的第4位，第3位和第2位
 */
#include <bits/stdc++.h>
using namespace std;

/* getBits函数:返回x中从第p位开始的n位 */
/*
 * x >> (p+1-n)将期望获得的字段移位到字的最右端。~0的所有位都为1，这里
 * 使用语句~0<<n 将~0左移n位，并将最右边的n位用0填补。再使用~运算对它取反，建立最右边
 * n位全为1的屏蔽码。
 */
unsigned getBits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/*
int main()
{
    unsigned a = 20;
    //cout << bitset<sizeof(int)*8>(~(~0 << 3) << 2) << endl;
    cout << bitset<sizeof(int)*8>(a) << endl;
    cout << bitset<sizeof(int)*8>(getBits(a, 4, 4)) << endl;
    return 0;
}
*/

