#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 /*
   普里姆算法---最小生成树
   n:表示图中所有的顶点数
 lowCost[];  lowCost数组初始值存放的是两个顶点初始化的权值，如果是i-i即自己到自己的
            权值由自己人为规定的，为 0或者无穷，而两个顶点之间如果有边，则lowCost中
            存该边对应的权值，如果没有边，则在lowCost中存放 无穷。
            eg:lowCost[0]:表示当前最小生成树到顶点 0权值最小边的权值
  vset[i]: 如果vset[i]=1表示i顶点已经并入了已生成的最小生成树中，反之，没有被并入，
  比如：    vset[0]=1,表示顶点0 已经被并入到生成的最小生成树中；

  v:表示刚要并入最小生成树的顶点。
  min：存放最小的权值
 */
 typedef struct {
  int vi;       //存储生成树上的顶点的下标
  int vj;       //存放待选顶点的下标
  int weight;   //存放待选边的权值
 }lowCost;

void prim(int n,float MGraph[][n],int v0,float &sum){
     int lowCost[n],v; //lowCost数组初始值存放的是两个顶点初始化的权值，如果
     int vset[n];
     lowCost=(LowCost*)malloc(sizeOf(LowCost)*G.vexNum);
     for(int i=0;i<n;i++){
      lowCost[i]=MGraph[v0][i];
      vset[i]=0;
     }
     v=v0;
     vset[v]=1;
     sum=0;
     for(int i=0;i<n-1;++i){
        min=INF;
        for(int j=0;j<n;++j){
         if(vset[j]==0 && min>lowCost[j]){
          min=lowCost[j];
          k=j;
         }
         vset[k]=1;
         v=k;
         sum+=min;
         for(int m=0;m<n;m++){
          if(vset[m]==0 && lowCost[m]>MGraph[v][m]){
                lowCost[m]=MGraph[v][m];
          }
         }
        }
     }
}

prim算法使用了双层for循环，因此该算法的时间复杂度为 o(n*n).

/*最小生成树---佛洛依德算法
  算法思想：先构造一个只含有n个顶点的子图SG,然后从权值最小的边开始，若它的添加
  不使的SG图不产生回路，则在SG上添加该边，如此重复，直至 加上n-1条边为止
*/
#define maxSize 20;
typedef struct {
  int a,b; //a,b分别表示一条边依附的2个顶点
  int weight; //表示a-b这两个顶点对应边上的权值
}Road;
Road road[maxSize];

//将所有的边存储为
void sort(Road[] road,int e){
 int temp;
 for(int i=0;i<e;i++){
   for(int j=0;j<n-i-1;j++){
     if(road[j].weight>road[j+1].weight){
        temp=road[j].weight;
        road[j].weight=road[j+1].weight;
        road[j+1]=temp;
     }
   }
 }
}

/*
  找根结点，因为只要根结点的双亲是它自己 v[0]=0; 表示 0是根结点;
  并查集中存放的 子结点和 双亲的关系
  子节点（p）：双亲结点(v[p])
   0       0
   1       0
   2       1
   3       0
   4       2
   5       3
   通过以下getRoot()方法来获取当前结点的双亲结点，比如当p=5时，v[p]=3
   表示p结点的双亲为3
*/

int getRoot(int p){
     while(p!=v[p]){
       p=v[p];
     }
     return p
}

//核心算法 n为顶点数，e为边的总数

void Kruskal(Road[] road,int n,int e ,int &sum){
    int a,b;
    sum=0;
    for(int i=0;i<n;i++){
        v[i]=i;
    }
    sort(road,e);
    for(int  i=0;i<e;i++){
        a=getRoot(road[i].a);
        b=getRoot(road[i].b);
        if(a!=b){
          v[a]=b;
          sum+=road[i].weight;
        }
    }
}
