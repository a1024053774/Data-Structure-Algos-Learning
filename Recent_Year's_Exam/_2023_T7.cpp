//
// Created by 10240 on 2024/11/4.
//
//2023 T7
#include <iostream>
typedef struct ArcNode
{
    int adjvex; //边所指向节点的位置
    struct ArcNode *nextarc;
} ArcNode, *Node; //边结点结构体

typedef struct
{
    int data;
    ArcNode *firstarc;
} Vnode; //顶点结构体

typedef struct
{
    Vnode adjlist[maxsize];
    int numver, numedg;
} AGraph; //图
//给定一个有向图，找到该图的母节点，即从该节点出发能访问到所有的节点
//思路：遍历所有节点，若有一个节点的所有节点都被访问过，则该节点为母节点
//时间复杂度O(n^2) n为节点个数
//空间复杂度:O(n)

void DFS(AGraph *G,int v,int visit[]){
    visit[v] = 1;
    ArcNode *p = G->adjlist[v].firstarc;
    while(p != NULL){
        if(visit[p->adjvex] == 0){
            DFS(G,p->adjvex,visit);
        }
        p =p->nextarc;
    }
}

VNode find_Mother(AGraph *G){
    int visit[G->numver] = {0};
    for (int i = 0;i < G->numver;i++){
        DFS(G,i,visit);
        for(int j = 0;j < G->numver; j++){
            if(visit[j] == 0){
                break;//如果有为链接的节点，直接break
            } else {
                return G->adjlist[i].data;//返回节点的值
            }
        }
        visit[] = {0};//该节点遍历完后不是结果，则重置visit数组，重新遍历下一个节点
    }
}