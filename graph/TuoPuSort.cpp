//
// Created by 10240 on 2024/10/11.
//

// 拓扑排序
#include <iostream>
#define maxsize 100
typedef struct ArcNode
{
    int adjvex;//边节点索引
    struct ArcNode *nextarc;
} ArcNode, *Node; //边结点结构体

typedef struct VNode
{
    int data;
    int indegree;//顶点入度
    ArcNode *firstarc;
} Vnode; //顶点结构体

typedef struct AGraph
{
    Vnode adjlist[maxsize];
    int numver, numedg;
} AGraph; //图

int TuoPuSort(AGraph G){
    int stack[maxsize], top = -1;
    int i,j,k;
    int num = 0;//记录输出的顶点数
    ArcNode *p;

    for(i = 0; i < G.numver; ++i){
        if(G->adjlist[i].indegree == 0){
            stack[++top] = G->adjlist[i].data;
        }
    }//将入度为0的顶点入栈

    while(top != -1){
        k = stack[top--];//出栈
        num++;//输出顶点数加1
        cout << k << " ";
        p = G->adjlist[k].firstarc;//指向k的第一个邻接点
        while(p != NULL){
            j = p->adjvex;
            if(--G->adjlist[j].indegree == 0){//入度减1
                stack[++top] = G->adjlist[j].data;//入度为0，则入栈
            }
            p = p->nextarc;
        }

    }
    if(num == G->numver)
        return 1;
    else
        return 0;
}

