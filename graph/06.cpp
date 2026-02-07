#include <iostream>
#include "algraph.cpp"
using namespace std;
// 用DFS判断无向图是否是树
void DFS(AGraph *G, int start, int &vn, int visit[])
{
  visit[start] = 1;
  ++vn;
  ArcNode *p = G->adjlist[start].firstarc;
  while (p != NULL)
  {
    if (visit[p->adjvex] == 0)
      fun(G, p->adjvex, vn, visit);
    p = p->nextarc;
  }
}
bool GisTree(AGraph *G)
{
  int vn = 0;
  int visit[maxsize];
  for (int i = 0; i < G->numver; ++i)
    visit[i] = 0;
  DFS(G, 1, vn, visit);
  if (vn == G->numver && (G->numver - 1) == G->numedg)
    return true;
  else
    return false;
}
int main()
{
  AGraph *G = aaaa(4, 3);
  if (GisTree(G))
    cout << "是";
  else
    cout << "否";
  return 0;
}