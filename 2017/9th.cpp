//
// Created by zfzhou on 11/22/2018.
//
#include <bits/stdc++.h>
using namespace std;
/*
 * Given the level order traversal of a Complete Binary Tree, determine whether the Binary Tree is a valid Min-Heap
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
bool isMinHeap(int level[], int n)
{
    for(int i = n/2-1; i >= 0; i--) {
        if(level[i] > level[2*i+1])
            return false;
        if(2*i+2 < n) {
            if(level[i] > level[2*i+2])
                return false;
        }
    }
    return true;
}
int main()
{
    int level[] = {10, 15, 14, 25, 30};
    int n = sizeof(level)/sizeof(int);
    if(isMinHeap(level, n))
        cout << "True";
    else
        cout << "False";
    return 0;
}

