//
// Created by 10240 on 2024/11/2.
//

//2022 T6
//输出二叉树最深层的节点

//层次遍历，输出最后一层的节点

//用数组实现队列，数组中还要加上一个记录该节点所在层次的结构体属性
#include <iostream>
typedef struct BTNode {
    int val;
    struct BTNode* left;
    struct BTNode* right;
} BTNode;

typedef struct{
    BTNode *p;
    int level_no;
}custom[MAXSIZE];

void Higest(BTNode *bt){
    custom queue[MAXSIZE];
    int rear =0,front = 0;
    if(bt!=NULL){
        queue[rear].p = bt;//根入队
        queue[rear].level_no = 1;
        rear++;
        while( rear != front){
            bt = queue[front++].p;//根节点出队
            int level = queue[front].level_no;
            if(bt->lchild != NULL){
                queue[rear].p = bt->lchild;
                queue[rear].level_no = level+1;
                rear++;
            }

            if(bt->rchild != NULL){
                queue[rear].p = bt->rchild;
                queue[rear].level_no = level+1;
                rear++;
            }

        }
    }//树层次遍历完成

    //结束时front指针位于最后一个节点位置
    int lastLevel = queue[front-1].level_no;//front指针指向的前一个位置是队列中最后一层的元素，获取层号
    for(int i=0;i < rear;i++){
        if(queue[i].level_no == lastLevel){
            cout<< queue[i].p->data;//指针向后走了，但是数值实际上还在队列中
        }
    }

}