//
// Created by 10240 on 2024/10/26.
//

//2020年真题5
//给定一个有向图，判断是否有环
/*思路分析：

可以使用深度优先搜索(DFS)来检测环
DFS遍历过程中维护一个访问状态数组:
0表示未访问
1表示在当前DFS路径上
2表示已完全访问完成

如果在DFS过程中遇到状态为1的节点，说明形成了环
如果一个节点的所有相邻节点都访问完成后，将其状态置为2

时间复杂度分析：
V为顶点数
E为边数

每个顶点最多被访问一次：O(V)
每条边最多被遍历一次：O(E)
总时间复杂度：O(V + E)

空间复杂度：
访问状态数组：O(V)
递归调用栈深度：最坏情况O(V)
总空间复杂度：O(V)
*/
#include <iostream>
#define maxsize 100
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



// DFS函数检测环
bool DFS(AGraph *G, int v, int visit[])
{
    // 如果当前节点在访问路径上，说明有环
    if(visit[v] == 1)
        return true;

    // 如果已经完全访问过，无需再访问
    if(visit[v] == 2)
        return false;

    // 标记当前节点正在访问
    visit[v] = 1;

    // 遍历所有邻接点
    ArcNode *p = G->adjlist[v].firstarc;
    while(p != NULL)
    {
        if(DFS(G, p->adjvex, visit))
            return true;
        p = p->nextarc;
    }

    // 标记当前节点已完全访问
    visit[v] = 2;
    return false;
}

// 判断图是否有环的主函数
bool hasCycle(AGraph *G)
{
    // 初始化访问数组，0表示未访问，1表示在访问路径上，2表示已完全访问
    int visit[maxsize] = {0};

    // 对每个未访问的顶点调用DFS
    for(int i = 0; i < G->numver; i++)
    {
        if(visit[i] == 0)
        {
            if(DFS(G, i, visit))
                return true;
        }
    }
    return false;
}