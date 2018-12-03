//
// Created by zfzhou on 2018/12/2.
//
#include <bits/stdc++.h>
using namespace std;

#ifndef ANSWER839_LISTNODE_H
#define ANSWER839_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head);


#endif //ANSWER839_LISTNODE_H
