//
// Created by zfzhou on 2018/12/2.
//
#include <bits/stdc++.h>
using namespace std;

#include "../util/listnode.h"

void RemoveDuplicates(ListNode* head) {
    ListNode *cur, *pre, *tmp;
    cur = head;
    while(cur != NULL) {
        tmp = cur->next;    //从cur后结点开始比较
        pre = cur;  //记录要删除结点的前驱
        while(tmp != NULL) {
            if(tmp->val == cur->val) {
                pre->next = tmp->next;
                tmp = pre->next;
            } else {
                pre = tmp;
                tmp = tmp->next;
            }
        }
        cur = cur->next;
    }
}

/*
int main()
{
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(1);
    ListNode* fourth = new ListNode(2);
    ListNode* fifth = new ListNode(3);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next= fifth;
    printList(first);
    RemoveDuplicates(first);
    printList(first);
    return 0;
}*/
