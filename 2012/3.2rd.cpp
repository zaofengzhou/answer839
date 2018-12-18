//
// Created by zfzhou on 12/18/2018.
//
#include<bits/stdc++.h>
using namespace std;

// 输出一个无符号数二进制
void printBinary(unsigned n)
{
    if(n > 1)   //大于等于基数
        printBinary(n / 2);
    printf("%d", n % 2);
}

void printHex(unsigned n)
{
    if(n > 15)   //大于等于基数
        printHex(n / 16);
    int a = n % 16;
    if(a > 9)
        printf("%c", n % 16 - 10 + 'a');
    else
        printf("%c", n % 16 - '0');
}


void PRINT(char fmt[], unsigned value)
{
    int len = strlen(fmt);
    for (int i = 0; i < len; ++i) {
        int c = fmt[i];
        if(c != '%') {
            putchar(fmt[i]);
            continue;
        } else {    //c=='%'判断c的下一个字符，并输出value的相应形式
            c = fmt[i+1];
            i++;
        }
        switch (c) {
            case 'b':
                printBinary(value);
                break;
            case 'u':
                printf("%u", value);
                break;
            case 'x':
                printf("%x", value);
                break;
            case 'o':
                printf("%o", value);
                break;
            default:
                printf("%c", fmt[i+1]);
                break;
        }
    }
}

/*
int main()
{
    PRINT("hello%b\nworld", -1);
    //printBinary(-1);
    //printf("\n");
    //printHex(-1);
    return 0;
}
 */

