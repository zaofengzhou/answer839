//
// Created by zfzhou on 12/18/2018.
//
#include<bits/stdc++.h>
using namespace std;

/*
 * 使用杨辉三角计算组合数
 */
#define MAXN 100

// 递归超时
long long C(int n, int k)
{
    if(k == 0 || n == k)
        return 1;
    return C(n-1, k-1) + C(n-1, k);
}

/*
 * 递归转DP
 */
long long C1(int n, int k)
{
    long long int a[n+1];

    //将数组所有元素初始化为0 非常重要
    memset(a, 0, (n+1)*sizeof(long long int));

    a[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j >= 1; j--) //从后往前赋值
            a[j] = a[j] + a[j-1];   //递推
    }
    return a[k];
}


int main()
{
    printf("%lld\n", C1(50, 25));
    return 0;
}
