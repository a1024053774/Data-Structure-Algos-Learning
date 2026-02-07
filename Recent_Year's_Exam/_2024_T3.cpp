//
// Created by 10240 on 2024/11/26.
//

//2024_T4
//求二叉树某一节点的父节点，如果所要查找的节点是根节点，返回-1，找到其父节点返回1。
#include <iostream>

typedef struct BTNode{
    int data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BiTree,*BTNode;

BTNode* findParent(int  *target,BTNode *root){
    if(root == NULL || root->data == target){
        return NULL;
    }

    if(root->lchild != NULL && root->lchild->data == target){
        return root;
    }
    if (root->rchild != NULL && root->rchild->data == target)
    {
        return root;
    }
    BTNode * left_parent = findParent(target,root->lchild);
    if (left_parent != NULL)
    {
        return left_parent;
    }
    BTNode * right_parent = findParent(target,root->rchild);
    if (right_parent != NULL)
    {
        return right_parent;
    }

    return NULL;
}

int func(BTNode *root,int target){

    BTNode * parent = findParent(target,root);
    if (parent != NULL)
    {
        cout<< parent->data;
        return 1;
    } else {
        return -1;
    }

}