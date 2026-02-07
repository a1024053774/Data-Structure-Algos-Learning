//
// Created by 10240 on 2024/11/1.
//
//2022 T4
//给定一个单链表，循环左移K次，即找到第k个位置后断开，后一段放前面。例如:A B C D F,k = 2，则变成C D F A B

//思想：
//感觉没必要用快慢指针找第k个，因为不是找链表后面k个元素
//设置一个变量n，每次后移，n++，但是第k个索引为k-1,条件为n<k-1,最后一次刚好n停在k位置
#include <iostream>
void Reverse(LinkList &L, int k){
    int n = 0;
    LNode *p = L->next;

    while(n < k-1 && p!= NULL){
        p = p->next;
        n++;
    }
    if(p ==NULL) return;//长度不满足k，返回
    LNode *q = p->next;
    p->next = NULL;

    p = L->next; //p回到链头，例子中A的位置，用于最后链接

    L->next = q;

    while(q->next!= NULL){
        q=q->next;//q来到链尾
    }

    q->next = p;//例子中的F链接到A
}

// 时间复杂度:O(n) n为链表长度
// 空间复杂度:O(1)