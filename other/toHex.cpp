#include <bits/stdc++.h>
using namespace std;

char* toHex3(int num) {
    char *p = (char*)malloc(sizeof(char)*9);
    sprintf(p,"%x",num);
    return p;
}

char* toHex4(int num) {
    char map[] = {'0', '1', '2', '3', '4', '5', '6', '7','8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned int n = num;
    int size = 0;

    if(n == 0)  return (char*)"0";
    while(n > 0) {  //统计有多少位
        n /= 16;
        size++;
    }
    n = num;

    char *ans = (char*)malloc(sizeof(char*)*size);
    ans[size] = '\0';
    while(n > 0) {
//        cout << bitset<sizeof(int)*8>(n) << endl;
//        char c = n % 16;
//        (c < 10) ? (c += '0') : (c += 'a'-10);
//        ans[--size] = c;
        ans[--size] = map[n%16];
        n = n / 16;
    }

    return ans;
}

/*
int main() {
//    cout << toHex(26) << endl;
//    cout << hex << 26 << endl;
//    int a = - (1 << 31);
//    unsigned b = a;
//    cout << toHex1(-2) << endl;
    cout << toHex3(-2) << endl;
    cout << toHex4(-2) << endl;
    cout << toHex4(127) << endl;

    printf("%c\n", 9 + '0');
    //printf("%d\n", 9 + '0');
    printf("%d\n", '0');
    printf("%d\n", 'A');
    printf("%d\n", 'a');
    //cout << hex << -2 << endl;
    //cout << bitset<sizeof(int)*8>(-2) << endl;
    //cout << bitset<sizeof(unsigned int)*8>(a) << endl;
//    cout << dec <<  a << endl;
//    cout << bitset<sizeof(int)*8>(a) << endl;
//    cout << bitset<sizeof(int)*8>(b) << endl;
    return 0;
}
*/
