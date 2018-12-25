//
// Created by zfzhou on 2018/12/1.
//
#include <bits/stdc++.h>
using namespace std;

#include "../util/binarytree.h"
/*
 * 在一棵二叉树（链式存储结构）中查找值为x的结点，请写出能输出值为x的结点的所有祖先的函数，
 * 假设值为x的结点最多只有1个。先简要地写出算法的思路和与主要步骤，在函数中的主要语句应当有注释
 */

bool findX(node* root, int x) {
    if(root == NULL)
        return false;
    if(root->data == x)
        return true;
    else
        return findX(root->left, x) || findX(root->right, x);
}

/*
 * if x is present in tree, then prints the ancestors
 * and returns true, otherwise return false.
 */
bool printAnsectors(node* root, int x) {
    if(root == NULL)
        return false;
    if(root->data == x)
        return true;
    // 如果x出现在这个结点的左子树或者右子树中，打印这个结点
    if( printAnsectors(root->left, x) ||
        printAnsectors(root->right, x) )
    {
        printf("%d ", root->data);
        return true;
    }
    return false;
}

/*
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    levelOrder(root);
    printf("\n");
    cout << findX(root, 4) << endl;
    //printAnsectors(root, 7);
    return 0;
}
*/

