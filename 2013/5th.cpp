//
// Created by zfzhou on 12/7/2018.
//
#include <bits/stdc++.h>
using namespace std;


int preCheck(char *s)
{
    if(strlen(s) != 18)
        return 0;
    for(int i = 0; i < 17; i++) {
        if(!isalnum(s[i]))
            return 0;
    }
    return 1;
}

int generateT(char *s)
{
    int a[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int sum = 0;
    for(int i = 0; i < 17; i++) {
        sum += (s[i]-'0')*a[i];
    }
    return sum % 11;
}

int check(int t, char c)
{
    char s[] = "10X98765432";
    return  s[t] == c;
}

/*
int main()
{
    char idNum[20];
    scanf("%s", idNum);
    printf("%s\n", idNum);
    if(preCheck(idNum)) {
        int t = generateT(idNum);
        if(check(t, idNum[17])) {
            printf("Valid\n");
        } else {
            printf("not Valid\n");
        }
    } else {
        printf("not Valid\n");
    }
    return 0;
}
*/
