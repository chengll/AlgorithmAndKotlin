#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//基于邻接表的存储结构的连通图的广度优先遍历算法
void bf_traver(ALGraph G,int v0){
  /* 队列Q存放已经访问过的顶点的编号，
     v0为出发开始访问的结点
  */
  int v;ArcNode p;
  InitQueue(Q);
  println(G->adjList[v0].vextex);
  visited[v]=1;Enqueeu(Q,v0);
  while(!isEmptyQueue(Q)){
    v=Dequeue(Q);
    p=G->adjList[v].firstArc;
    while(p!=NULL){
        w=p->adjvex; //w表示p顶点的编号
        if(visited[w]==0){
         println(G->adjList[w].adjvex);
         visited[w]=1;
         Enqueue(Q);
        }
        p=p->nextArc;//p指向与它邻接的下一条边
    }
  }
}

/*非连通图的深度（广度）优先遍历算法
 具体实现时候 该图的存储结构既可以是基于邻接矩阵的也可以是基于邻接表的
 n为图中顶点的数目
*/

void traverGraph(Graph G){
    int v,n,visited[n];
    for(v=0;v<n;v++){
      visited[v]=0;
    }

    for(v=0;v<n;v++){
        if(visited[v]==0){
         bf_traver(G,v); //这是广度遍历的算法 ，也可以调用深度遍历的方法 dfTraveradjMatrix（）
        }
    }
}

/*通过DFS查找图中是否有环的算法
    1).对顶点vi做深度优先遍历时，  先计算顶点vi的度di与该顶点vi有邻接关系的访问标志数vi;
    2).如果di==vi，则出现回路循环，否则继续查找。
*/

void DFS(MGraph G,int i,int visited[]){
 visited[i]=1;
 for(int di=0,vi=0,j=0;j<G.vexNum;j++){
    if(G.arcs[i][j]){
     di++;
     if(visited[j]) vi++;
    }
 }
 if(di==vi){
  println("图中有回路"); return;
 }

 for(j=0;j<G.vexNum;j++){
    if(G.arcs[i][j] && !visited[j]){
     DFS(G,j,visited);
    }
    }
}
