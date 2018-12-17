//
// Created by zfzhou on 12/11/2018.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../util/listnode.h"

/*
 * 定义函数sortLinkedList(h)，其将h所指的一个单项链表按照节点中存放的字符串值的字典升序排序，返回指向排序后的第一个节点的指针。不能使用临时的结点缓冲区。
   函数原型为：NODE* sortLinkedList
   LINK的定义为：typedef struct Node { char *data;s truct Node *next; ) NODE;
   其中data指向不等长的字符数组表示的字符串。
 */


void print(NODE *head)
{
    while (head != NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

/*
 * 用类似于插入排序的方法
 */
NODE* sortLinkedList(NODE *h) {
    if(h == NULL)
        return h;
    NODE* dummy = newNode("a");
    NODE* cur = h;
    NODE* pre = dummy;
    NODE* next = NULL;

    while(cur) {
        next = cur->next;
        // find the right place to insert
        while (pre->next != NULL && strcmp(pre->next->data, cur->data) < 0)
            pre = pre->next;
        cur->next = pre->next;  //insert
        pre->next = cur;

        cur = next;
        pre = dummy;
    }
    return dummy->next;
}


/*
int main()
{
    NODE *head = newNode("abc");
    head->next = newNode("adb");
    head->next->next = newNode("ac");
    head->next->next->next= newNode("aaac");
    print(head);
    NODE* res = sortLinkedList(head);
    print(res);
//    printf("%d\n", strcmp("abc", "aaa"));
//    printf("%d\n", strcmp("aaa", "abc"));
    return 0;
}
*/
