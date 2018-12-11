//
// Created by zfzhou on 12/11/2018.
//
#include<bits/stdc++.h>
using namespace std;

#include "../util/binarytree.h"
#include "../util/listnode.h"
/*
 * 已知一颗二叉树的标准形式的存储结构，写出利用其叶子节点中的指针域，把所有叶子节点链接成一个带有表头结点的单链表的函数。
 * 要求：先简要写出编程的算法思想和主要步骤再写函数。
 */

/* function to print leaf nodes from left to right*/
void printLeafNodes(node *root) {
    if(!root)   return;

    if(root->left == NULL && root->right == NULL)
        cout << root->data << " ";

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void linkUtil(node *root, ListNode* &head)
{
    if(!root)   return;

    if(root->left == NULL && root->right == NULL) {
        ListNode *temp = new ListNode(root->data);
        head->next = temp;  //尾插法插入
        head = head->next;
    }

    linkUtil(root->left, head);
    linkUtil(root->right, head);
}

ListNode* linkLeafNodes(node *root) {
    ListNode* head = new ListNode(0);
    linkUtil(root, head);
    return head;
}

int main()
{
    // Let us create binary tree shown in
    // above diagram
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
//    root->left->left = newNode(4);
//    root->right->left = newNode(5);
//    root->right->right = newNode(8);
//    root->right->left->left = newNode(6);
//    root->right->left->right = newNode(7);
//    root->right->right->left = newNode(9);
//    root->right->right->right = newNode(10);
    //levelOrder(root);
    printLeafNodes(root);
    printf("\n");
    ListNode* head = linkLeafNodes(root);
    printList(head);
    return 0;
}