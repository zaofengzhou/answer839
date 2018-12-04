//
// Created by zfzhou on 12/4/2018.
//
#include <bits/stdc++.h>
using namespace std;

#include "../util/binarytree.h"
/*
 * 已只一棵二叉树标准形式的存储结构，写一函数生成它的扩充标准形式的存储结构。(还有一个指针域指向父节点)
 */

struct e_node {
    int data;
    struct e_node *left;
    struct e_node *right;
    struct e_node *parent;
};

//递归
e_node* expend(node* root) {
    e_node* eroot = (e_node*)malloc(sizeof(e_node));
    eroot->parent = NULL;
    eroot->data = root->data;

    if(root->left) {    //左子树非空，递归扩充左子树
        eroot->left = expend(root->left);
        eroot->left->parent = eroot;
    }
    if(root->right) {   //右子树非空，递归扩充右子树
        eroot->right = expend(root->right);
        eroot->right->parent = eroot;
    }
    return eroot;
}


/*
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    //root->left->right = newNode(5);
    struct e_node* eroot = expend(root);

    cout << "helloworld" << endl;
    return 0;
}
*/

