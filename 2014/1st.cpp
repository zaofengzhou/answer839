//
// Created by zfzhou on 12/4/2018.
//

/*
 * 第一题
    1.在C99标准中，类型int和类型long long之间的区别是什么?
        占用空间不同，int类型4字节，long long类型8字节。相应的可表示的数据范围也不同，int类型可表示
        [-2^31, 2^31-1]的数据，long long类型可表示[-2^63, 2^63-1]的数据。
    2.在程序中注解的作用是什么?
        在程序的开头加入注释，可以写明程序的一些必要信息，如创建者，时间，程序实现的功能以及参考来源等内容。
        程序代码当中适当加入一些注释，可以增加程序的易读性，便于与共同开发者进行交流。
    3.使用库函数时包含相应的头文件的目的是什么?例如，使用sqrt函数要包含math.h头文件
        包含头文件在编译时相当于对指定库函数进行声明，这样在程序编译过程时才能调用到正确的函数。
    4.设定义int v[16], i,j,s=0;指出下面的语句执行完成后i,j,s的值。

    5.你经常使用的C语言编译器是哪一个?C程序的开发环境是哪一个?在调试程序时设置断点的目的是什么?
        C语言的编译器gcc，（还有clang,cl,mscc等），开发常用编辑器vim和sublime Text，或者集成开发环境有Visual Studio 2017, codeblocks, dev C++等。
        (注意，不要将集成开发环境、编译器、编辑器等概念混淆)。设置断点是为了在程序调试时监视变量的变化以及程序的流程，常用于循环的边界调度或递归结构的调试。
 */

#include <bits/stdc++.h>
using namespace std;

/*
int main()
{
//    cout << sizeof(int) << endl;
//    cout << sizeof(long long) << endl;
    int v[16], i, j, s = 0;
    for(i = 0; i <16; i++)  v[i]=2*i+1;
    i = 0;
    while(i<=10) {
        for(j=0; j <=i; j++)    if(j%2==0)  s+=v[j]; else   s-=v[j];
        i++;
    }
    cout << i << " " << j << " " << s << endl;
    return 0;
}*/

