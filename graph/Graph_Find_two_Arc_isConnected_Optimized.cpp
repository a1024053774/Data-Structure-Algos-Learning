#include <iostream>
#include "algraph.cpp"
using namespace std;

void Init_VisitedColumn(AGraph *G, int visit[])
{
    for (int i = 0; i < G->numver; ++i)
        visit[i] = 0;
}

void DFS(AGraph *G, int start, int visit[])
{
    visit[start] = 1;
    ArcNode *p = G->adjlist[start].firstarc;
    while (p != NULL)
    {
        if (visit[p->adjvex] == 0)
            DFS(G, p->adjvex, visit);
        p = p->nextarc;
    }
}

bool is_Connected(int end, int visit[])
{
    return visit[end] == 1;
}

int main()
{
    AGraph *G = aaaa(4, 3); // 这里的aaaa假设是构建图的函数
    int visit[maxsize];      // 确保maxsize是定义好的，或者根据G->numver动态分配
    Init_VisitedColumn(G, visit);
    DFS(G, 0, visit);
    if (is_Connected(2, visit))
        cout << "存在路径";
    else
        cout << "不存在路径";
    return 0;
}
