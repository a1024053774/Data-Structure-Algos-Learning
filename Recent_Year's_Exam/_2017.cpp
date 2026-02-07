//
// Created by 10240 on 2024/10/22.
//

//2017年真题
#include <stdio.h>
//二叉排序树中的结点为整型，设计递归算法递增有序输出树中大于等于x的所有元素。并返回输出的节点个数
//结构体定义
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
    }BSTNode,*BSTree;

//递归算法
int func(BSTNode* p, int x, int &count) {
    if (p == NULL) return 0;

    int left = func(p->lchild, x, count);
    int right = func(p->rchild, x, count);

    if (p->key >= x) {
        cout << p->key << ' ';
        count += 1;
    }
    return left + right +(p->key >= x ? 1 : 0);//在最外层递归时，p指向根节点，所以要判断根节点是否大于等于x
}
