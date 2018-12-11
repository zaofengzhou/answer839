//
// Created by zfzhou on 12/11/2018.
//
#include<bits/stdc++.h>
using namespace std;

/*
 * 由题目可知，按商品名排序，相同品名的商品都相邻，这样不需要造hash表。 每读到一行就与上一行的商品名相比，
 * 如果一样就累加收入，不一样则就把上一个商品输出到文件，再开始对下一个商品进行累计。
 */
/*
int main()
{
    FILE *fin, *fout;
    char brand[2][82];
    double sum = 0, price;
    int k = 0;

    fin = fopen("../2016/data.in", "r");
    fout = fopen("../2016/data.out", "w");

    fscanf(fin, "%s%lf", brand[k], &price); //最先读入的商品名在brand[0]
    sum = price;

    while(fscanf(fin, "%s%lf", brand[1-k], &price) != EOF)  //下一个读入的商品名放在brand[1]
    {
        // 比较两商品名是否相同，相同则累加，
        // 不同先输出，在将sum改为另一种商品价格，k修改
        if(strcmp(brand[0], brand[1]) == 0)
        {
            sum += price;
        } else {
            fprintf(fout, "%s %.2f\n", brand[k], sum);
            sum = price;
            k = 1-k;
        }
    }
    fprintf(fout, "%s %.2f\n", brand[k], sum);
    fclose(fin);
    fclose(fout);
    return 0;
}
*/
