//
// Created by 10240 on 2024/11/4.
//

//2023 T5

//给定一个二叉树，更新每一个节点的data域值，即将数据域的值设为当前节点的左子树的值之和 + 当前节点的值

// 计算以bt为根的子树所有节点值之和
//时间复杂度O(n) n为二叉树节点个数
//空间复杂度:O(h) h为二叉树高度

#include <iostream>
int compute(BTNode *bt) {
    if (bt == NULL) {
        return 0;
    }
    // 递归计算左右子树的和,加上当前节点的值
    return bt->data + compute(bt->lchild) + compute(bt->rchild);
}

// 更新每个节点的值
void update(BTNode *bt) {
    if (bt == NULL) {
        return;
    }

    // 保存原始的节点值
    int originalValue = bt->data;//进入下一层递归bt->data就变了，需要用变量保存

    // 先递归处理左右子树
    update(bt->lchild);
    update(bt->rchild);

    // 更新当前节点的值:原始值 + 左子树所有节点值之和
    bt->data = originalValue;
    if (bt->lchild != NULL) {
        bt->data += compute(bt->lchild);
    }
}