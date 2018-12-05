//
// Created by zfzhou on 12/4/2018.
//
#include <bits/stdc++.h>
using namespace std;

/*
 * 按要求写split函数，该函数将一个字符串以某个字符串作为分隔符进行分割，分隔的结果由若干个字符串组成的数组。
 */

int split(char *str, char key, char res[1000][1000])
{
    int i, index = 0, k = 0;

    for(i = 0; str[i] != '\0'; i++) {   //遍历字符串str如果str[i]不等于分隔符就赋给res
        if(str[i] != key) {
            res[index][k++] = str[i];
        }
        if(str[i] == key || i == strlen(str)-1) //str[i]等于分隔符的时候，要赋字符串结尾符；并令index++,k=0
        {
            res[index][k] = '\0';  //注意将字符串结尾赋值'\0'
            index++;
            k = 0;
            if(key != ' ')  //跳过空格
                i++;
        }
    }

    return index;
}


/*
int main()
{
    char *str = "The. Big, and. During, spread.";
    printf("%s\n", str);

    char res[1000][1000] = {};
    int cnt = split(str, '.', res);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}*/
