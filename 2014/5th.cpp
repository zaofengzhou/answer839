//
// Created by zfzhou on 12/4/2018.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * 按要求写程序 对文本中的字符串排序
 */
#define MAXLENGTH 10000

struct lineNode {
    int hashValue;
    int len;
    char *str;
};

int hash(char *s)
{
    int len = strlen(s);
    int sum = 0;
    for(int i = 0; i < len; i++) {
        if(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z' ||
            s[i] >= 'A' && s[i] <= 'Z') {
            sum += s[i];
        }
    }
    return sum % 10007;
}

int cmp14(const void *a, const void *b) {
    lineNode *m = (lineNode*)a;
    lineNode *n = (lineNode*)b;
    if(m->hashValue != n->hashValue) {
        return m->hashValue - n->hashValue;
    } else if(m->len != n->len) {
        return n->len - m->len;
    } else {
        return strcmp(n->str, m->str);
    }
}


/*
//int main(int argc, char *argv[])
int main()
{
    FILE *fin, *fout;
//    int n = atoi(argv[1]);
    int n = 4;
    lineNode line[n];

    fin = fopen("../2014/data.in", "r");
    fout = fopen("../2014/data.out", "w");

    char str[MAXLENGTH+1];
    int i = 0;

    while(fscanf(fin, "%s", str) != EOF)
    {
        line[i].hashValue = hash(str);
        line[i].len = strlen(str);
        // 给结构体里的字符串分配内存空间
        line[i].str = (char*)malloc(sizeof(char)*(line[i].len+1));
        strcpy(line[i].str, str);
        i++;
    }

    qsort(line, n, sizeof(line[0]), cmp14);


    for(int i = 0; i < n; i++)
    {
        fprintf(fout, "%s\n", line[i].str);
    }

    return 0;
}
*/
