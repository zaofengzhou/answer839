//
// Created by zfzhou on 11/15/2018.
//
#include <bits/stdc++.h>
using namespace std;

#include "../../util/binarytree.h"

/*
 * Compute the "height" of a tree -- the number of nodes along
 * the longest path from the root node down to the farthest leaf node.
 */
int height(struct node* root) {
    if(root == NULL)
        return 0;
    // compute the height of each subtree
    int lheight = height(root->left) + 1;
    int rheight = height(root->right) + 1;
    return lheight > rheight ? lheight : rheight;
}

// Print nodes at a given level
void printGivenLevel(struct node* root, int level) {
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root->data);
    else if(level > 1) {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

/*
    //Function to print level order traversal of tree
    printLevelorder(tree)
        for d = 1 to height(tree)
            printGivenLevel(tree, d);

    //Function to print all nodes at a given level
    printGivenLevel(tree, level)
    if tree is NULL then return;
    if level is 1, then
        print(tree->data);
    else if level greater than 1, then
        printGivenLevel(tree->left, level-1);
        printGivenLevel(tree->right, level-1);
*/
// Function to print level order traversal a tree
void printLevelOrder(struct node* root) {
    int h = height(root);
    for(int i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

/*
    1) Create an empty stack S.
    2) Initialize current node as root
    3) Push the current node to S and set current = current->left until current is NULL
    4) If current is NULL and stack is not empty then
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right
     c) Go to step 3.
    5) If current is NULL and stack is empty then we are done.
 */
void iterativeInorder(struct node* root) {
    stack<struct node*> s;
    struct node* curr = root;

    while (curr != NULL || !s.empty()) {
        // Reach the left most Node of the curr Node
        while(curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        // Current must be NULL at this point
        curr = s.top();
        cout << curr->data << " ";
        s.pop();
        // we have visited the node and its left subtree.  Now, it's right subtree's turn
        curr = curr->right;
    }

}

/*
1) Create an empty stack nodeStack and push root node to stack.
2) Do following while nodeStack is not empty.
….a) Pop an item from stack and print it.
….b) Push right child of popped item to stack
….c) Push left child of popped item to stack
*/
void iterativePreorder(struct node* root) {
    if(root == NULL)
        return;
    stack<node*> s;
    s.push(root);
    // Right child is pushed before left child to make sure that left subtree is processed first
    while (!s.empty()) {
        node *curr = s.top();
        printf("%d ", curr->data);
        s.pop();
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
}

//LRN的逆序NRL
/*
1. Push root to first stack.
2. Loop while first stack is not empty
   2.1 Pop a node from first stack and push it to second stack
   2.2 Push left and right children of the popped node to first stack
3. Print contents of second stack
 */
//Iterative preorder traversal can be easily implemented using two stacks.
// The first stack is used to get the reverse postorder traversal.
// The steps to get a reverse postorder are similar to iterative preorder.
void iterativePostorder(struct node* root) {
    if(root == NULL)
        return;
    stack<node*> s1;
    stack<node*> s2;
    s1.push(root);

    while (!s1.empty()) {
        node *curr = s1.top();
        s2.push(curr);
        s1.pop();
        if(curr->left)
            s1.push(curr->left);
        if(curr->right)
            s1.push(curr->right);
    }
    // Print all elements of second stack
    while (!s2.empty()) {
        node* temp = s2.top();
        printf("%d ", temp->data);
        s2.pop();
    }
}

/*
1.1 Create an empty stack
2.1 Do following while root is not NULL
    a) Push root's right child and then root to stack.
    b) Set root as root's left child.
2.2 Pop an item from stack and set it as root.
    a) If the popped item has a right child and the right child
       is at top of stack, then remove the right child from stack,
       push the root back and set root as root's right child.
    b) Else print root's data and set root as NULL.
2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
*/
void iterativePostorder1(struct node* root) {
    if(root == NULL)
        return;
    stack<node*> s;
    do {
        // Move to leftmost node
        while(root) {
            // Push root'right child and then root to stack
            if(root->right)
                s.push(root->right);
            s.push(root);
            // Set root as root's left child
            root = root->left;
        }
        // Pop an item from stack and set it as root
        root = s.top();
        s.pop();
        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if(root->right && !s.empty() && s.top() == root->right) {
            s.pop();    //remove right child from stack
            s.push(root);   //push root back to stack
            root = root->right; // change root so that the right
                                // child is processed next
        } else {    // Else print root's data and set root as NULL
            printf("%d ", root->data);
            root = NULL;
        }
    }while(!s.empty());

}

//Push directly root node two times while traversing to the left.
// While poping if you find stack top() is same as root then go for root->right else print root
void iterativePostorder2(struct node* root) {
    stack<node*> s;
    while(true) {
        while(root != NULL) {
            s.push(root);
            s.push(root);
            root = root->left;
        }
        // check for empty stack
        if(s.empty())   return;
        root = s.top();
        s.pop();

        if(!s.empty() && s.top() == root)   root = root->right;
        else {
            printf("%d ", root->data);
            root = NULL;
        }
    }
}


//int main()
//{
//    /*create root*/
//    struct node* root = newNode(1);
//    /* following is the tree after above statement
//          1
//        /   \
//       NULL  NULL
//    */
//    root->left = newNode(2);
//    root->right = newNode(3);
//    /* 2 and 3 become left and right children of 1
//             1
//           /   \
//          2      3
//       /    \    /  \
//      NULL NULL NULL NULL
//    */
//    root->left->left  = newNode(4);
//    root->left->right  = newNode(5);
//    /* 4 becomes left child of 2
//                     1
//                /         \
//              2            3
//            /    \        /  \
//           4       5    NULL  NULL
//         /  \     /  \
//     NULL  NULL NULL  NULL
//    */
//    preOrder(root);
//    printf("\n");
//    inOrder(root);
//    printf("\n");
//    postOrder(root);
//    printf("\n");
//    cout << height(root) << endl;
//    printGivenLevel(root, 3);
//    printLevelOrder(root);
//    printf("\n");
//    levelOrder(root);
//    iterativePreorder(root);
//    printf("\n");
//    iterativeInOrder(root);
//    printf("\n");
//    iterativePostorder(root);
//    printf("\n");
//    iterativePostorder1(root);
//    printf("\n");
//    iterativePostorder2(root);
//    return 0;
//}
