//
// Created by 10240 on 2024/10/29.
//

//2021年真题5
//判断二叉树是否为镜像对称的问题:

/*思想解析:


镜像对称的二叉树意味着它沿着根节点的中轴线对折后,左右两边完全重合
我们可以将此问题转化为:判断左子树和右子树是否互为镜像
两个子树互为镜像需要满足:

根节点值相同
1.左子树的左子树与右子树的右子树互为镜像
2.左子树的右子树与右子树的左子树互为镜像
3.递归判断左右子树是否互为镜像即可
 */
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 判断两个子树是否互为镜像
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // 两个节点都为空,视为镜像
    if (left == NULL && right == NULL) {
        return true;
    }
    // 其中一个为空,另一个非空,不是镜像
    if (left == NULL || right == NULL) {
        return false;
    }

    // 三个条件都满足才是镜像:
    // 1. 当前节点值相等
    // 2. left的左子树和right的右子树互为镜像
    // 3. left的右子树和right的左子树互为镜像
    return (left->val == right->val)
           && isMirror(left->left, right->right)
           && isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    // 空树也是对称的
    if (root == NULL) {
        return true;
    }
    // 判断左右子树是否互为镜像
    return isMirror(root->left, root->right);
}