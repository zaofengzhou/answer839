//
// Created by zfzhou on 12/7/2018.
//
#include <bits/stdc++.h>
using namespace std;

int MCNuggest(int n)
{
    for(int a = 0; a <= n ; a++) {
        for(int b = 0; b <= n-6*a; b++) {
            for(int c = 0; c <= n-6*a-9*b; c++) {
                if(6*a + 9*b + 20*c == n) {
                    printf("%d %d %d\n", a, b, c);
                        return 1;
                }
            }
        }
    }
    return 0;
}

int MCNuggest1(int n)
{
    if(n < 6)
        return 0;
    if(n == 6 || n == 9 || n == 20)
        return 1;
    return MCNuggest1(n-6) || MCNuggest(n-9) || MCNuggest(n-20);

}

/*
int main()
{

    cout << MCNuggest(100) << endl;
    cout << MCNuggest1(100) << endl;
    //cout << sizeof(size_t) << endl;
    return 0;
}
*/
