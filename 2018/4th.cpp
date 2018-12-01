//
// Created by zfzhou on 11/30/2018.
//
#include <bits/stdc++.h>
using namespace std;

/*
 * 定义函数cubeSqrt，其计算一个数的立方根，算法自定，但尽可能使用
 * 算法复杂度低的算法。
 */

//Binary search method
double mySqrt(double x)
{
    double l=0, r = x, m, precision = 1e-7;

    if(x < 1) {
        l = x;  // root is in the range [l, r]
        r = 1;
    }
    while(l <= r) {
        m = l + (r-l)/2;
        if(abs(m*m - x) < precision)
            return m;
        else if(m*m > x)
            r = m;
        else
            l = m;
    }
    return (l+r)/2;
}

//Newton-Raphson method
/*
 * 迭代公式
 * Xn+1 = Xn - f(Xn) / f'(Xn)
 */

double mySqrt1(double x) {
    double precision = 1e-6;
    double r = x;
    while(abs(r * r - x) > precision) {
        r = (r + x / r) / 2;
    }
    return r;
}

//Binary search method
double cubeSqrt(double x)
{
    double l = 0, r = x, precision = 1e-8;
    double m;
    if(x < 1) {
        l = x,
        r = 1;
    }
    while(abs(m*m*m - x) > precision) {
        m = l + (r-l)/2;

        if(m*m*m > x){
            r = m;    //r减少精度值
        } else {
            l = m;
        }
    }
    return m;
}

double cubeSqrt2(double x)
{
    double l=0, r = x, m, precision = 1e-8;

    if(x < 1) {
        l = x;  // root is in the range [l, r]
        r = 1;
    }
    while(l <= r) {
        m = l + (r-l)/2;
        if(abs(m*m*m - x) < precision)
            return m;
        else if(m*m*m > x)
            r = m;
        else
            l = m;
    }
    return (l+r)/2;
}

//Newton-Raphson method
double cubeSqrt1(double x) {
    double precision = 1e-6;
    double r = x;   //初值
//    while(abs(r*r*r - x) > precision) {
//        r = (2*r + x / (r*r) ) / 3;
//    }
    //未在精度范围内就迭代
    while(abs(r*r*r - x) > precision) {
        r = r - (r*r*r-x)/(3*r*r);
    }
    return r;
}
/*
int main()
{
//    printf("%f\n", sqrt(2));
//    printf("%f\n", mySqrt(2));
//    printf("%f\n", mySqrt1(2));
//    printf("%f\n", sqrt(0.01));
//    printf("%f\n", mySqrt(0.01));
//    printf("%f\n", sqrt(3));
//    printf("%f\n", mySqrt(3));
    printf("%f\n", cbrt(27));
    printf("%f\n", cubeSqrt(27));
    printf("%f\n", cubeSqrt1(27));
    printf("%f\n", cbrt(9));
    printf("%f\n", cubeSqrt(9));
    printf("%f\n", cubeSqrt1(9));
    printf("%f\n", cubeSqrt2(9));
    printf("%f\n", cbrt(0.001));
    printf("%f\n", cubeSqrt(0.001));
    printf("%f\n", cubeSqrt1(0.001));
    printf("%f\n", cubeSqrt2(0.001));
//    printf("%f\n", 1e-6);
    return 0;
}
*/