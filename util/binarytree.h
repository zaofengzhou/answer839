//
// Created by zfzhou on 2018/11/22.
//

#ifndef ANSWER839_BINARYTREE_H
#define ANSWER839_BINARYTREE_H

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data);

unsigned int countNodes(struct node* root);

void preOrder(struct node* root);

void inOrder(struct node* root);

void postOrder(struct node* root);

void levelOrder(node* root);

void iterativePreOrder(struct node* root);

void iterativeInOrder(struct node* root);

void iterativePostOrder(struct node* root);

#endif //ANSWER839_BINARYTREE_H