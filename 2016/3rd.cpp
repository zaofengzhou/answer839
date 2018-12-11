//
// Created by zfzhou on 12/10/2018.
//
#include<bits/stdc++.h>
using namespace std;

/*
 * 定义一个函数htoi(s)，其将一个十六进制字符串(包括可选的0x或0X开头)转换成等值的整数值。
 * s可包括字符0到9，a到f，A到F，及x和X。
   例如：htoi(“11”)的值为17；htoi((0xa)的值为10。
   函数原型为：int htoi(char *s)
 */

int htoi(char *s)
{
   int len = strlen(s);
   int sum = 0, base = 1;
   for(int i = len-1; i >=0; i--) {
       if(s[i] == 'x' || s[i] == 'X')
           break;
       if(s[i] >= 'a' && s[i] <= 'f')
           sum += (10 + s[i]-'a') * base;
       else if(s[i] >= 'A' && s[i] <= 'F')
           sum += (10 + s[i]-'A') * base;
       else
           sum += (s[i] - '0') * base;
       base = base * 16;
   }
   return sum;
}

/*
int main()
{
    cout << htoi("11") << endl;
    cout << htoi("0xa") << endl;
    return 0;
}
*/

