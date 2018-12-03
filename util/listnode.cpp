//
// Created by zfzhou on 2018/12/2.
//

#include "listnode.h"
#include <bits/stdc++.h>
using namespace std;

void printList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}