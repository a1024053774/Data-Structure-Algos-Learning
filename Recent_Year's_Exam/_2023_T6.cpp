//
// Created by 10240 on 2024/11/4.
//
//2023 T6
//删除无向图中度数小于k的顶点

//由于需要遍历计算所有顶点的度
//还需要删除度数小于k顶点的所有边，使用邻接表十分繁琐
//先写一个方法，用来计算当前节点的度
//在remove方法中先遍历所有节点的度，保存在degree数组中，数组下标为节点的值，数组值为节点的度
//然后删除所有度小于k的节点，删除时，由于是无向图，G.edge[i][j]和G.edge[j][i]两个方向的边都需要置为0，然后将vertice数组中值置为"\0",并更新边数和节点数
//若有一个节点删除，则其他节点的入度可能变化成小于k，所以需要bool类型变量来控制do while循环，若删除了一个节点，置为true，然后需要再次执行循环，重新计算新的度，删除度小于看的
//直到最后
#include <iostream>
typedef struct
{
    char verticle[maxsize];//顶点数组，若该位置为空，说明无节点
    int Edge[maxsize][maxsize];
    int numver, numedg;
} mgraph;

//用邻接矩阵方便删除

int cal_degree(MGraph &G,int vertex){//输入边节点序号，计算它的度
    int degree = 0;
    for(int j = 0;j < G.numver;j++){
        if(G.Edge[vertex][j] == 1){
            degree++;
        }
    }
    return degree;
}

//删除度数小于k的顶点
void remove(MGraph &G,int k){
    bool needRepeat;//若删除了一个节点，那么需要重新遍历，因为删除一个结点之后，其他节点的入度也发生了变化
    int deletedVer_Num = 0;
    do {
        needRepeat = false;
        //计算所有节点的度数，保存在degree数组中
        int  degree[maxsize] = {0};
        for(int i=0; i < G.numver;i++){
            if(G.verticle[i] !="\0"){//只计算有节点的位置，优化遍历时间
                degree[i] = cal_degree(G,i);//数组下标为节点的值，数组值为节点的度
            }
        }

        //标记并删除度数小于k的节点
        for(int i = 0; i < G.numver; i++){
            if(G.verticle[i] !="\0" && degree[i] < k){
                //删除相关边
                for(int j=0;j< G.numver;j++){
                    if(G.Edge[i][j] == 1){
                        //若有边
                        G.Edge[i][j] = 0;
                        G.Edge[j][i] = 0;
                        G.numver--;//边数-1  无向图虚拟上有两个方向的边，实际上只有一条
                    }
                }
                G.verticle[i] = "\0";//将顶点数组的值置为空
                deletedVer_Num++;//删除的顶点数
                needRepeat = true;
            }
        }
    }while (needRepeat);//若needRepeat为真，说明有节点删除，需继续遍历，删除改变后度小于k的

    G.numver -= deletedVer_Num;//更新节点数目
}

//总时间复杂度为  外层do while 为顶点个数 O(|V|) 次 ，最多删除所有顶点
/*每次循环中：
计算所有顶点的度数：O(|V|?)
遍历所有顶点 O(|V|)
对每个顶点计算度数需要遍历一行邻接矩阵 O(|V|)
检查并删除度数小的顶点：O(|V|?)
遍历所有顶点 O(|V|)
对每个要删除的顶点，需要修改一行和一列的边 O(|V|)

总时间复杂度为：O(|V| × |V|?) = O(|V|?)
*/

/*空间复杂度分析：

邻接矩阵存储：O(|V|?)
度数数组 degree[maxsize]：O(|V|)
其他变量（如needRepeat, deletedVertices等）：O(1)

总空间复杂度为：O(|V|?)*/
