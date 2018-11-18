//
// Created by zfzhou on 11/15/2018.
//
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
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

void preOrder(struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node* root) {
    if(root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct node* root) {
    if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void levelOrder(node* root) {
    if(root == NULL)    return;
    queue<node*> q;
    q.push(root);
    while(q.empty() == false) {
        struct node* now = q.front();   //取出队首元素
        printf("%d ", now->data);   //访问队首元素
        q.pop();
        if(root->left != NULL)  q.push(root->left);
        if(root->right != NULL) q.push(root->right);
    }
}

int main()
{
    /*create root*/
    struct node* root = newNode(1);
    /* following is the tree after above statement
          1
        /   \
       NULL  NULL
    */
    root->left = newNode(2);
    root->right = newNode(3);
    /* 2 and 3 become left and right children of 1
             1
           /   \
          2      3
       /    \    /  \
      NULL NULL NULL NULL
    */
    root->left->left  = newNode(4);
    /* 4 becomes left child of 2
                 1
             /       \
            2          3
          /   \       /  \
         4    NULL  NULL  NULL
        /  \
      NULL NULL
    */
//    preOrder(root);
//    printf("\n");
//    inOrder(root);
//    printf("\n");
//    postOrder(root);
//    printf("\n");
    levelOrder(root);
    return 0;
}
