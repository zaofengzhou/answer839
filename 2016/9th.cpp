//
// Created by zfzhou on 12/11/2018.
//
#include<bits/stdc++.h>
using namespace std;

#include "../util/binarytree.h"
/*
 * 已知一颗二叉树的标准形式的存储结构，写出利用其叶子节点中的指针域，把所有叶子节点链接成一个带有表头结点的单链表的函数。
 * 要求：先简要写出编程的算法思想和主要步骤再写函数。
 */

/*
 * 题目要求将叶子节点按自左向右的次序连接成一个单链表，因此很容易考虑到的便是将整棵二叉树按照先序或中序或后序的方式遍历一次
 * 在遍历的过程中对叶子节点单独判读，如果是叶子结点，则将其做个标识（比如用额外的指针指向该结点），接着遍历下一个叶子结点，
 * 遍历到另一个叶子结点后，然后让已被标识的叶子结点的右孩子指向该结点，依次便可将叶子结点连接成单链表。
 * 整个过程类似于尾插法建立单链表
 */

/* function to print leaf nodes from left to right*/
void printLeafNodes(node *root) {
    if(!root)   return;

    if(root->left == NULL && root->right == NULL)
        cout << root->data << " ";

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

static node* head = NULL;   //指向第一个叶子结点
static node* r = NULL;     // 记录叶子链表的当前结点

void linkLeafNodes(node *root) {
    if(root == NULL)
        return;
    if(root->left==NULL && root->right==NULL) {
        if(r == NULL) {
            head = root;
        } else {
            r->right = root;    //链接时用叶子结点的right域存放指针
        }
        r = root;
    }
    linkLeafNodes(root->left);
    linkLeafNodes(root->right);
}

void static print(node* head){
    node *p = head;
    while(p) {
        printf("%d ",p->data);
        p = p->right;
    }
    printf("\n");
}

/*
int main()
{
    // Let us create binary tree shown in
    // above diagram
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);
    //levelOrder(root);
    printLeafNodes(root);
    printf("\n");

    linkLeafNodes(root);
    print(head);

    return 0;
}
 */
