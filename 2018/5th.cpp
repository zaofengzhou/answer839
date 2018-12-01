//
// Created by zfzhou on 2018/12/1.
//
//#include <bits/stdc++.h>
//using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 * 两个班的成绩分别存放在两个文件当中。每个文件有多行，每行都是由空格分隔的学号、姓名和成绩。
 * 现在要将两个班的成绩合并到一起进行排序，排序规则按照成绩从高到低，成绩相同则按学号由小到大排序。
 * 将结果输出一个文件当中。两个输入文件名与输出文件名再程序运行时用命令行参数指定。请你编写一个程序完成上述功能
 * 主要考查的是结构体排序和命令行参数的用法
 */

#define MAX 200
struct stuNode {
    char stuId[20];
    char name[20];
    int score;
};

int comp(const void *a, const void *b)
{
    stuNode m = *(stuNode*)a, n = *(stuNode*)b;
    if(m.score != n.score)
        return n.score-m.score;
    else
        return strcmp(m.stuId, n.stuId);
}

int loadData(FILE *fp, stuNode *stu) {
    int i = 0;
    while (fscanf(fp, "%s", stu[i].stuId) != EOF) {
        fscanf(fp, "%s%d", stu[i].name, &stu[i].score);
        i++;
    }
    return i;
}

/*
int main(int argc, char *argv[])
{
    stuNode a[MAX], b[MAX], res[MAX];
//    printf("%d\n", argc);
//    printf("%s\n", argv[0]);
//    printf("%s\n", argv[1]);
//    printf("%s\n", argv[2]);
    FILE *fin1, *fin2, *fout;
//    fin1 = fopen("../2018/data.in", "r");
//    fin2 = fopen("../2018/data2.in", "r");
//    fout = fopen("../2018/data.out", "w");
    //使用命令行参数指定文件名
    fin1 = fopen(argv[1], "r");
    fin2 = fopen(argv[2], "r");
    fout = fopen(argv[3], "w");
//    int i = 0;
//    while(fscanf(fin1, "%s", a[i].stuId) != EOF) {
//        fscanf(fin1, "%s%d", a[i].name, &a[i].score);
//        i++;
//    }
    int num1 = loadData(fin1, a);
    int num2 = loadData(fin2,b);
    for(int i = 0; i < num1; i++) {
        res[i] = a[i];
    }
    for(int i = num1; i < num1+num2; i++) {
        res[i] = b[i-num1];
    }

    qsort(res, num1+num2, sizeof(stuNode), comp);

    for(int i = 0; i < num1+num2; i++) {
        fprintf(fout, "%s %s %d\n", res[i].stuId, res[i].name, res[i].score);
    }
    return 0;
}
 */
