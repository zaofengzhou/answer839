//
// Created by zfzhou on 12/4/2018.
//
#include <bits/stdc++.h>
using namespace std;

/*
计算tribonacci数列
tribonacci数列定义为
T(0)=0,T(1)=T(2)=1
T(n)=T(n-1)+T(n-2)+T(n-3) (当n>2时)
1.定义一个递归函数计算 T(n)
2.定义一个非递归函数计算T(n)
3.比较1.和2.中两个函数，执行函数计算T(10)时各自的加法执行次数是几次?
 哪个函数计算快?
 t  96次
 t2 8次 t2快
4.当n较大时，定义的函数各自可能存在什么问题?
 递归函数会占用较多内存空间以保存中间调用的过程，n稍大就会因内存栈用尽而不能运算。(栈溢出)
 非递归函数则可能因数据超出数据范围而计算出错误的结果。
 */

int t(int n) {
    if(n == 0)
        return 0;
    if(n == 1 || n == 2)
        return 1;
    return t(n-1)+t(n-2)+t(n-3);
}

int t2(int n) {
    if(n == 0)
        return 0;
    if(n == 1 || n == 2)
        return 1;
    int n0=0, n1=1,n2=1;
    int res;
    for(int i=3; i<=n; i++) {
        res = n0+n1+n2;
        n0 = n1;
        n1 = n2;
        n2 = res;
    }
    return res;
}

/*
int main()
{
    for(int i = 0; i <= 10; i++)
        cout << t(i) << " ";
    cout << endl;
    for(int i = 0; i <= 10; i++)
        cout << t2(i) << " ";
    return 0;
}
*/
