//
// Created by zfzhou on 12/6/2018.
//
#include <bits/stdc++.h>
using namespace std;

/*
 * 双向链表（头指针为head）中，删除值为y的结点的函数
 */

struct dbListNode {
    int data;
    dbListNode *pre;
    dbListNode *next;
};

dbListNode *newdbNode(int x) {
    dbListNode* node = (dbListNode*)malloc(sizeof(dbListNode));
    node->data = x;
    node->pre = node->next = NULL;
    return node;
}

void printdbList(dbListNode *head) {
    dbListNode *cur = head->next;
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void removeY(dbListNode *head, int y) {
    dbListNode *pre = head;
    dbListNode *cur = head->next;
    while(cur != NULL) {
        if(cur->data == y) {
            pre->next = cur->next;
            cur->next = pre;
        }
//        if(cur->data == y && cur->next == NULL) {
//            pre->next = NULL;
//        }
        pre = cur;
        cur = cur->next;
    }
}

/*
int main()
{
    dbListNode *head = newdbNode(0);    //头结点
    dbListNode *first = newdbNode(1);
    dbListNode *second = newdbNode(2);
    dbListNode *third = newdbNode(3);
    head->next = first;
    first->pre = head;
    first->next = second;
    second->pre = first;
    second->next = third;
    third->pre = second;

    printdbList(head);
    removeY(head, 3);
    printdbList(head);

//    cout << "hello world" << endl;
    return 0;
}
*/
