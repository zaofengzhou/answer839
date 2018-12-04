//
// Created by zfzhou on 12/4/2018.
//
#include <bits/stdc++.h>
using namespace std;


void split(char *str, char key, char res[][1000])
{
    int i;
    while(str!="\0") {
        i = 0;
        int j = 0;
        if(*(str) != key) {
            res[i][j++] = *(str++);
        } else {
            i++;
            j = 0;
        }
    }
}


int main()
{
    char *str = "hello. world";
    printf("%s", str);
    return 0;
}
