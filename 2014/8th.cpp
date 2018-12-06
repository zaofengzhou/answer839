//
// Created by zfzhou on 12/6/2018.
//
#include <bits/stdc++.h>
using namespace std;

/*
 * 填空，将串s2加到串s1的末尾形成新的s1串，即s1=s1+s2；其中MAXN为s1数组的容量
 */

#define MAXN 100

int strcat1(char s1[], char s2[])
{
    int i, j, k;
    if( (i = strlen(s1)) + (j=(strlen(s2)) ) >= MAXN)   //注意等号，也无法复制 ?  貌似等号也能复制
        return -1;
    for(k = 0; k <= j; k++)
        s1[i+k] = s2[k];
    return 0;
}


/*
int main()
{
//    char str[80];
//    strcpy(str, "hello");
//    strcat(str, "world");
//    puts(str);
    char s1[10] = "hello";
    char s2[] = "world";
    cout << strlen(s1) << endl;
    puts(s1);
    strcat1(s1, s2);
    puts(s1);
    //printf("%s\n", s1);
    return 0;
}
*/
