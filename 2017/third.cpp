//
// Created by zfzhou on 11/6/2018.
//
#include <bits/stdc++.h>
using namespace std;

const string HEX = "0123456789abcdef";

//位运算
string toHex(int num) {
    if(num == 0)    return "0";
    string res;
    while(num != 0 && res.size() < 8) { //without condition res.size()<8, it will trap into infinite loop
        res = HEX[num & 0xf]+ res;
        num >>= 4;
    }
    return res;
}

string toHex1(int num) {
    if(num == 0)    return "0";
    string res;
    //num would be 0 anyways after doing 'num >>= 4' eight times if you treat it as an unsigned integer
    unsigned n = num;   // use unsigned n instead of num
    while(n != 0) {
        //cout << bitset<sizeof(int)*8>(n) << endl;
        res = HEX[n & 0xf]+ res;
        n >>= 4;
    }
    return res;
}

//除基取余法：重复做n % 16 和 n / 16 直到n为0  注意先得到的余数为最高位
char* toHex2(int num) {
    char map[] = {'0', '1', '2', '3', '4', '5', '6', '7','8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned int n = num;
    int size = 0;

    if(n == 0)  return "0";
    while(n > 0) {  //统计有多少位
        n /= 16;
        size++;
    }
    n = num;

    char *ans = (char*)malloc(sizeof(char*)*size);
    ans[size] = '\0';
    while(n > 0) {
        int t = n % 16;
        ans[--size] = t < 10 ? t + '0' : t - 10 + 'a';
//      ans[--size] = map[n%16];
        n = n / 16;
    }

    return ans;
}

/*
int main()
{
    cout << hex << -2 << endl;
    cout << toHex(-2) << endl;
    cout << toHex1(-2) << endl;
    cout << toHex2(-2) << endl;
    cout << toHex2(127) << endl;
    return 0;
}
*/

