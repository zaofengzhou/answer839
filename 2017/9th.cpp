//
// Created by zfzhou on 11/22/2018.
//
#include <bits/stdc++.h>
using namespace std;

#include "../util/binarytree.h"

/*
 * Given the level order traversal of a Complete Binary Tree,
 * determine whether the Binary Tree is a valid Min-Heap
 */

/*
Input : level = [10, 15, 14, 25, 30]
Output : True
The tree of the given level order traversal is
                     10
                    /  \
                   15   14
                  /  \
                 25   30
We see that each parent has a value less than
its child, and hence satisfies the min-heap
property
 */
/*
 * We need to check whether each non-leaf node(parent) satisfies the heap property.
 * For this we check whether each parent(at index i) is smaller than its
 * children(at indices 2*i+1 and 2*i+2, if the parent has two children). If only one, we only check
 * against index (2*i+1)
 */
bool isMinHeap(int level[], int n)
{
    // First non leaf node is at index (n/2-1).
    // Check whether each parent is greater than child
    for(int i = n/2-1; i >= 0; i--) {
        // Left child will be at index 2*i+1
        // Right child will be at index 2*i+2
        if(level[i] > level[2*i+1])
            return false;
        if(2*i+2 < n) { //when n is even First non leaf node's right child is not exist
            // If parent is greater than right child
            if(level[i] > level[2*i+2])
                return false;
        }
    }
    return true;
}

bool isMinHeap1(node* root) {
//    bool left = true, right=true;
//    if(root->left!=NULL && root->left->data > root->data)
//        left = false;
//    else if(root->right!=NULL && root->right->data > root->data)
//        right = false;
//    return isMinHeap1(root->left) && isMinHeap1(root->right);
    if(root->left == NULL && root->right == NULL)
        return true;
    if (root->right == NULL)
    {
        //  check heap property at Node
        //  No recursive call , because no need to check last level
        return (root->data <= root->left->data);
    } else {
        if(root->data <= root->left->data && root->data <= root->right->data)
            return isMinHeap1(root->left) && isMinHeap1(root->right);
        else
            return false;
    }
}

bool isMaxHeap(node* root) {
    //  Base case : single node satisfies property
    if(root->left == NULL && root->right == NULL)
        return true;
    // node will be in second last level
    if (root->right == NULL)
    {
        //  check heap property at Node
        //  No recursive call , because no need to check last level
        return (root->data >= root->left->data);
    } else {

        //  Check heap property at Node and
        //  Recursive check heap property at left and right subtree
        if(root->data >= root->left->data && root->data >= root->right->data)
            return isMaxHeap(root->left) && isMaxHeap(root->right);
        else
            return false;
    }
}

int main()
{
    int level[] = {10, 15, 14, 25, 30};
    int level1[] = {30, 56, 22, 49, 30, 51, 2, 67};
    int n = sizeof(level)/sizeof(int);
    if(isMinHeap(level, n))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    if(isMinHeap(level1, n))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    struct node* root = newNode(10);
    root->left = newNode(15);
    root->right = newNode(14);
    root->left->left = newNode(25);
    root->left->right = newNode(30);

    struct node* root1 = newNode(10);
    root1->left = newNode(9);
    root1->right = newNode(8);
    root1->left->left = newNode(7);
    root1->left->right = newNode(6);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);
    root1->left->left->left = newNode(3);
    root1->left->left->right = newNode(2);
    root1->left->right->left = newNode(1);
//    levelOrder(root);
    cout << isMinHeap1(root) << endl;
    cout << isMaxHeap(root1) << endl;
    return 0;
}

