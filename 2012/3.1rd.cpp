//
// Created by zfzhou on 12/17/2018.
//
#include<bits/stdc++.h>
using namespace std;

/*
 * 函数Insert将一个由参数p指向的结点按序插入到一个已按data成员升序排序
 * 的头指针为head的链表中，返回插入结点后的链表表头指针。
 */

typedef struct intNode {
    int data;
    struct intNode *next;
}NODE;

NODE* newNode1(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

static void print(NODE *head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


NODE* Insert(NODE* head, NODE* p)
{
    // 生成头结点统一处理空表和非空表
    NODE* dummy = newNode1(0);
    dummy->next = head;

    // 找到待插入结点的前驱
    NODE* pre = dummy;
    while(pre->next != NULL && pre->next->data < p->data) {
        pre = pre->next;
    }
    p->next = pre->next;    //插入p
    pre->next = p;

    return dummy->next;
}

/*
int main()
{

    NODE* head = newNode1(1);
    head->next = newNode1(2);
    head->next->next = newNode1(4);
//    NODE* head = NULL;

    print(head);
    NODE* p = newNode1(3);
    head = Insert(head, p);
    print(head);

    cout << "hello world!" << endl;
    return 0;
}
*/



