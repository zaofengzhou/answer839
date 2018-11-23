//
// Created by zfzhou on 11/6/2018.
//
#include <bits/stdc++.h>
using namespace std;

void minprintf(char *fmt, ...)
{
    va_list ap;     //依次指向每个无名参数
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);  //将ap指向第一个无名参数，必须被调用一次
    for(p = fmt; *p; p++) {
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval  = va_arg(ap, char*);  *sval ; sval++) {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); //结束时的清理工作
}

void myprintf(char *fmt, ...)
{
    va_list ap;     //依次指向每个无名参数
    char *p, *sval;
    int ival;
    double dval;
    int num = 0;
    char tmp[33];

    va_start(ap, fmt);  //将ap指向第一个无名参数，必须被调用一次
    for(p = fmt; *p; p++) {
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'b':
                ival = va_arg(ap, int);     //转化二进制有bug 负数
                do {
                    tmp[num++] = (ival % 2) + '0';
                    ival /= 2;
                } while(ival > 0);
                for(int i = num-1; i >= 0; i--) {
                    printf("%c", tmp[i]);
                }
                break;
            case 'o':
                ival = va_arg(ap, int);
                printf("%o", ival);
                break;
            case 'x':
                ival = va_arg(ap, int);
                printf("%x", ival);
                break;
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval  = va_arg(ap, char*);  *sval ; sval++) {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); //结束时的清理工作
}

/*
int main()
{
    int c;

//    while((c = getchar()) != EOF) {
//        putchar(tolower(c));
//    }
    char *s = "hello, world";
    char *p = (char*)malloc(100);
//    minprintf("%d\n", strlen(s));
//    minprintf("HelloWorld%s%d%\n", s, 10);
    printf("HelloWorld%s%d\n", s, 10);
    myprintf("%b %o %d %x\n", 15, -1, -1, -1);
    printf("%x %o\n", 1, 1);
    cout << bitset<sizeof(int)*8>(-1) << endl;
//    char *string1 = (char*)malloc(33);
//    sprintf(string1, "%x", -1);
//    cout << string1;


//    printf("HelloWorld%s\n", s);
//    printf("%d\n", strlen(s));
//    printf("%s\n", s);
//    printf("%10s\n", s);
//    printf("%.10s\n", s);
//    printf("%-10s\n", s);
//    printf("%.15s\n", s);
//    printf("%-15s\n", s);
//    printf("%15.10s\n", s);
//    printf("%-15.10s\n", s);
//    sprintf(p,"%x %o", -1, -1);
//    printf("%s\n", p);
    return 0;
}
*/
