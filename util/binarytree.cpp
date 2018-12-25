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

void inOrder(struct node* root) {
    if(root != NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct node* root) {
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void postOrderIterative(struct node* root) {
    stack<node* > s;
    node* cur = root;
    node* last = NULL;

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
        struct node* now = q.front();   //取出队首元素
        printf("%d ", now->data);   //访问队首元素
        q.pop();
        if(now->left != NULL)  q.push(now->left);   //左子树非空，入队
        if(now->right != NULL) q.push(now->right);  //右子树非空，入队
    }
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    levelOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    postOrderIterative(root);
    return 0;
}

