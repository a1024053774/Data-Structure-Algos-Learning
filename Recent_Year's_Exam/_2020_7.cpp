//
// Created by 10240 on 2024/10/27.
//

//2020年真题7
//已知有序整数序列用带头结点的单链表存储，请用算法描述两个数列的值是否相等
//若相等返回1，否则0

/*
思路分析：在两个链表上各声明一个指针，初值为第一个节点
每次判断，若相同，则都向后走
若最后其中一个走出循环条件指向空
再次判断，若他们都为空
则说明值都相等，长度也相等
*/

//时间复杂度：O(n) n为链表长度
//空间复杂度：O(1)

#include <stdio.h>
int is_equal(LinkList A, LinkList B) {
    LNode *p = A->next;
    LNode *q = B->next;

    while (p != NULL && q != NULL) {
        if (p->data != q->data) {  // 如果数据不相等，直接返回0
            return 0;
        }
        p = p->next;
        q = q->next;
    }

    if (p == NULL && q == NULL) {  // 都为空说明长度相等且所有数据都相等
        return 1;
    } else {                       // 一个为空一个不为空说明长度不等
        return 0;
    }
}