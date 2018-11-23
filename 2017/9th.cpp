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

//链式存储
bool isMinHeap1(node* root) {
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

/*
 * Given a binary tree we need to check it has heap property or not,
 * Binary tree need to fulfill following two conditions for being a heap –
 *  It should be a complete tree (i.e. all levels except last should be full).
 *  Every node’s value should be greater than or equal to its child node (considering max-heap).
 */

// This function checks if the binary tree is complete or not
bool isCompleteUtil(struct node* root, unsigned int index, unsigned int number_nodes)
{
    // An empty tree is complete
    if(root == NULL)
        return true;
    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if(index >= number_nodes)
        return false;
    // Recur for left and right subtrees
    return isCompleteUtil(root->left, 2*index+1, number_nodes) &&
            isCompleteUtil(root->right, 2*index+2, number_nodes);
}

/*
 * isHeapUtil function is written considering following thing
 *  1.Every Node can have 2 children, 0 child(last level nodes)or 1 child(there can be at most one such node)
 *  2.if Node has No child then it's a leaf node and return true(Base case)
 *  3.if Node has one child(it must be left child because it is complete tree),hen we need to compare this node with its single child only.
 *  4.if Node has both child then check heap property at Node at recur for both subtrees.
 */
// This Function checks the heap property in the tree.
bool isHeapUtil(node* root) {
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
            return isHeapUtil(root->left) && isHeapUtil(root->right);
        else
            return false;
    }
}

// Function to check binary tree is a Heap or not
bool isHeap(struct node* root)
{
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;

    if(isCompleteUtil(root, index, node_count) && isHeapUtil(root))
        return true;
    return false;
}
/*
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
//    root->left->left->right = newNode(40);

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
//    cout << countNodes(root) << endl;
    unsigned int node_count = countNodes(root);
    cout << isCompleteUtil(root, 0, node_count) << endl;
//    cout << isMinHeap1(root) << endl;
//    cout << isHeapUtil(root1) << endl;
    if(isHeap(root1))
        cout << "Given binary tree is a Heap" << endl;
    else
        cout << "Given binary tree is not a Heap" << endl;
    return 0;
}
*/
