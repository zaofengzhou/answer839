/*
1.举例说明表达式的值不确定的情况
    表达式的值和计算次序不确定，就是指复合求值的时候，C语言标准未明确规定计算次序可能导致的
    不同平台不同编译器下运算得到的结果不同，例如k = k++ + k--, 这是一个合法的表达式，但k的值
    取决于自增自减运算次序和加法的先后。
2.结构体的大小是否等于各结构成员之和
    结构体的大小并不等于所有结构体成员之和，例如一个结构体中有char类型与double类型的成员，那么
    结构体的大小是2*sizeof(double),而不是sizeof(char)+sizeof(double)，这是为了寻址方便规定的。
 */
#include<stdio.h>

struct st {
    char a;
    int b;
//    int c;
    double d;
};
/*
int main()
{
    int c = 2;
    int ans = c + --c;
    printf("%d\n", ans);
    struct st s;
    s.a = 'a';
    s.b = 12;
    s.d = 0.1314;
    printf("%d\n", sizeof(s));    //16 = 2*sizeof(double)
    return 0;
}
*/

