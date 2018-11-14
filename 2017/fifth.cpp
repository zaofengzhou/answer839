//
// Created by zfzhou on 11/6/2018.
//
/**
 * 文本文件data.in当中，有多行数字，每行有4个浮点数x1 y1 x2 y2，分别表示矩形的左下角与右上角顶点的两个坐标(x1,y1) (x2,y2).
 *  现在请你写一个程序，对这些矩形进行排序。排序的规则为：
 *  先按矩形面积从小到大排序，
 *  如果面积相同，则按左下角到顶点的距离从小到大排序，
 *  如果再相同，按左下角顶点的横坐标x1从小到大排序。
 *  将排序后的数据再写到文件data.out当中，面积为0的矩形不输出
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXN 200;

typedef struct pNode
{
    double x1, y1;
    double x2, y2;
    double area, distance;
}Point;

int cmp(const void* a, const void* b) {
    Point m = *(Point*)a, n = *(Point*)b;
    if(m.area != n.area)
        return m.area - n.area;
    else if(m.distance != n.distance)
        return m.distance - n.distance;
    else
        return m.x1 - n.x1;
}

/*int main()
{
    printf("Hello World!\n");
    return 0;
}*/

