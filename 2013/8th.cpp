//
// Created by zfzhou on 12/10/2018.
//
#include <bits/stdc++.h>
using namespace std;


/*
 * 一个串采用顺序存储结构，写一函数删除s中从第i个字符开始的j个字符
 */

void removeStr(char s[], int i, int j) {
    int len = strlen(s);
    if(i < 0 || i >= len || j < 1 || i + j >= len)
        return;
    int k, p;
    for(k = i+j, p = i; s[k] != '\0'; p++, k++) {
        s[p] = s[k];
    }
    s[p] = '\0';
}

/*
int main()
{
    char s[] = "helloworld";
    cout << strlen(s) << endl;
    cout << s << endl;
    removeStr(s, 2, 2);
    cout << s << endl;
    return 0;
}
*/
