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
void inOrder1(struct node* root) {
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
        s.pop();

        cout << curr->data << " ";
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

// NLR  LRN
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
    root->left->right  = newNode(5);
    /* 4 becomes left child of 2
                   1
              /          \
             2            3
           /    \        /  \
          4       5    NULL  NULL
        /  \     /   \
     NULL NULL NULL  NULL
    */
//    preOrder(root);
//    printf("\n");
//    inOrder(root);
//    printf("\n");
//    postOrder(root);
//    printf("\n");
//    cout << height(root) << endl;
//    printGivenLevel(root, 3);
    printLevelOrder(root);
    printf("\n");
//    levelOrder(root);
    iterativePreorder(root);
    printf("\n");
    inOrder1(root);
    printf("\n");
    iterativePostorder(root);
    return 0;
}
