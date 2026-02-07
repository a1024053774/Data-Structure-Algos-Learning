//
// Created by 10240 on 2024/11/4.
//

//2023 T3


/*给定一个单链表，每两个节点为一组进行翻转
如：1->2->3->4->5->6
输出：2->1->4->3->6->5
*/
//思想
//1.定义三个指针，pre,cur,next
//2.每次翻转两个节点，pre->next = next,cur->next = next->next,next->next = cur
//3.更新pre,cur,next
//4.直到cur或next为空
//5.返回头节点
//时间复杂度O(n) n为链表长度
//空间复杂度:O(1)

#include <iostream>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

void ReversePair(LinkList &L){
    if(L->next == NULL || L->next->next == NULL) return;//链表长度不足2

    LNode *pre = L;
    LNode *cur = L->next;
    LNode *next = cur->next;

    while(cur != NULL && next != NULL){
        LNode *temp = next->next;

        pre->next = next;
        cur->next = temp;
        next->next = cur;//翻转两个节点

        pre = cur;
        cur = temp;
        if(cur != NULL){
            next = cur->next;
        }
    }

}