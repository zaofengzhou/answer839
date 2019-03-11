//
// Created by zfzhou on 2018/11/22.
//

#include "binarytree.h"
#include <bits/stdc++.h>
using namespace std;

/* newNode() allocates a new node with the given data and NULL left and
   right pointers. */
struct node* newNode(int data) {
    // Allocate memory for new node
    struct node* node = (struct node*)malloc(sizeof(struct node));
    // Assign data to this node
    node->data = data;
    // Initialize left and right children as NULL
    node->left = NULL;
    node->right = NULL;
    return node;
}

// This function counts the number of nodes in a binary tree
unsigned int countNodes(struct node* root) {
    if(root == NULL)
        return 0;
    return 1 + countNodes(root->left)+countNodes(root->right);
}

void preOrder(struct node* root) {
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void iterativePreOrder(struct node* root) {
    if(root == NULL)
        return;
    stack<node* > s;
    s.push(root);
    while(!s.empty()) {
        // 栈顶元素出栈
        node* cur = s.top();
        printf("%d ", cur->data);
        s.pop();
        // right child is pushed first so that left is
        // processed first
        if(cur->right != NULL)
            s.push(cur->right);
        if(cur->left != NULL)
            s.push(cur->left);
    }
}

void inOrder(struct node* root) {
    if(root != NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void iterativeInOrder(struct node* root) {
    stack<node* > s;
    node* cur = root;
    while(cur != NULL || !s.empty()) {
        if(cur != NULL) {
            s.push(cur);
            cur = cur->left;
        } else {
            // cur must be NULL at this time
            cur = s.top();
            printf("%d ", cur->data);
            s.pop();
            cur = cur->right;
        }
    }
}

void postOrder(struct node* root) {
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void iterativePostOrder(struct node* root) {
    stack<node* > s;
    node* cur = root;
    node* last = NULL;  //最近访问结点

    while(cur || !s.empty()) {
        if(cur) {
            s.push(cur);
            cur = cur->left;
        } else {
            node* top = s.top();
            // if right child exists and traversing node
            // from left child, then move right
            if(top->right && last != top->right) {
                cur = top->right;
            } else {
                cout << top->data << " ";
                last = top;
                s.pop();
            }
        }
    }
}

void levelOrder(node* root) {
    if(root == NULL)    return;
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node* now = q.front();   //取出队首元素
        printf("%d ", now->data);   //访问队首元素
        q.pop();
        if(now->left != NULL)  q.push(now->left);   //左子树非空，入队
        if(now->right != NULL) q.push(now->right);  //右子树非空，入队
    }
}

/*
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    levelOrder(root);
    printf("\n");
    iterativePreOrder(root);
    printf("\n");
    iterativeInOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    iterativePostOrder(root);
    return 0;
}
*/

