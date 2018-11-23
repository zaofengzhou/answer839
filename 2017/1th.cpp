//
// Created by zfzhou on 11/23/2018.
//
#include <bits/stdc++.h>
using namespace std;

/*
 * 一、
    (1) int fun() { return fun(); } 执行这段代码会出现什么问题
    (2)int a;请问数值a<<sizeof(a)*8+1的值为多少。
 */

//编译没有错误，可以编译成可执行文件，但一旦运行起来就会造成内存耗尽而崩溃。一直递归没有出口。
int fun() {
    return fun();
}

/*int main()
{
    //fun();
    int a = 1;
    //可能在一些环境中，试验这个表达式会得到x<<1的值。这是编译器将移位操作提前做了取余，从移位的理论上讲是数值应是0
    int b = a << sizeof(a)*8 + 1;
    cout << bitset<sizeof(int)*8>(a) << endl;
    cout << bitset<sizeof(int)*8>(b) << endl;
    return 0;
}*/
