#include<stdi0.h>
#include<stdlib.h>
#include<string.h>
//无向图十字链表的数据结构描述

边的数据结构描述
typedef struct EBox{
 int marked; //标识给顶点是否被访问过，
 int ivext,jvext;//依附的i 和 j的两个顶点的位置
 struct EBox* iLink,jLink; //依附i的下一个顶点的指针和依附j的下一个顶点指针
 infoType *info;    //边的一些信息
}EBox;

头结点的数据结构
typedef struct VexBox{
 VertexType data;   //结点数据类型
 EBox *firstedge;//指向第一条边的指针
}VexBox;

无向图的数据结构
#define MAX_VERTEXT_SIZE 20;
typedef struct AMLGrapha{
VexBox adjmuList[MAX_VERTEXT_SIZE];
int arcNum,verNum;
}AMLGrapha;


//邻接表的数据结构描述
typedef struct ArcNode{
  int adjvex;       //表示当前顶点在数组中的位置
  struct ArcNode * nextArc; //指向下个边的指针
  weightInfo  weight; //权值信息，可有可无，如果有就表示，没有就不表示
}ArcNode; //边结点信息

#define Char VextexType;//假设顶点中的数据类型为char
typedef struct VexNode{
 VertexType vertext;      //结点信息
 ArcNode *firstArc; //指向第一条边的指针
}VexNode;      //顶点的数据结构

#define MAX_VER_NUM 20;
typedef struct {
VexNode adjList[MAX_VER_NUM]; //图中通过数组存放所有的顶点
int arcNum,vexNum;      //存放边数和顶点数
}ALGraph;

//创建有向图的邻接表算法
void build_adjList(ALGraph *G){
int i,j,k; ArcNode p;
    scanf(&G->vexNum,&G->arcNum); //输入图的顶点数和变数
    for（ i=0;i<G->vexNum;i++){
        scanf(&G->adjList[i].vertext); //输入结点信息
        G->adjList[i].firstArc=NULL;   //将图中的指向第一条边的指针初始化
    }
    for(k=0;k<G->arcNum;k++){
        scanf(&i,&j);
        p=(ArcNode*) malloc(sizeOf(ArcNode));
        p->adjVext=j-1;
        p->nextArc=G->adjList[i-1].firstArcNode;
        G->adList[i-1].firstArc=p;
    }
}

//连通图的——深度遍历的递归算法
/**
@param Grapha 为图的结构
@param v,表示深度遍历从哪个顶点出发
@param visited[]数组，存储顶点是否被访问过饿状态，0未访问，1已访问
*/
void df_traver(Grapha G,int v,int visited[]){
     println(v);//表示访问该顶点
     visited[v]=1; //将其修改为已访问状态
     w=FirstAdjVex(G,v); //w表示当前访问结点v的第一个邻接点。
        while(w){
             if(visited[w]==0){
              do_traver(G,w,visited[w]);
              w=nextAdjVex(G,w);
             }
        }
}

//连通图的——深度遍历的非递归算法，图的深度遍历算法，图的深度遍历是基于栈的操作，
void df_traver2(Grapha G,int v){
    Stack s;initStack(&s);int visited[100];
    for(int i=0;i<G->vexNum;i++){
        visited[i]=0;
    }
    //对顶点的操作时：访问 入栈 修改状态
    print(v); pushStack(s,v);
    visited[v]=1;
    while(!stackIsEmpty(s)){
     k=getTop(s);
     w=FirstAdjVex(G,k); //取出k结点的第一个相邻结点，
     while (w){//表示w不为空
        if(visited[w]==0){
        print(w);pushStack(s,w);
        visited[w]=1;
        break;
        }
     }
     if(!w){ //表示w不存在
     pop(s);
          }
    }
}



//有向图的十字链表的数据结构描述
十字链表的数据结构类型
typedef struct ArcNode{
int tailvex,headvex; //弧尾弧头在数组中的下标值
struct ArcNode *hLink,*tLink; //指向下一个弧头和下一个弧尾的指针
InfoType *info; //该弧相关的信息的指针
}ArcNode

十字链表的表头结点数据结构类型
typedef struct VexNode{
 VertexType data;       //结点信息
 ArcNode *fistIn,*firstOut; //第一个进入的指针和第一个出去的指针
}VexNode;

十字链表的图的数据结构类型
#define MAX_VER_NUM 100;
typedef struct {
    VexNode xList[MAX_VER_NUM];  //数组存放图中所有的结点
    int arcNum,vexNum;          //存放图中的边数和顶点数目
}OLGraph


//邻接矩阵的数据结构描述
#define VERNUM 20; //图中顶点的最大数目
typedef struct {
 VextexType vexs[VERNUM]; //存储顶点信息
 int arc[VERNUM][VERNUM]; //存储顶点关系，如果两个顶点之间有边则是存放权值，否则为无穷
 int arcNum,vexNum;      //存储边数和顶点数
}MGraph;

//基于邻接矩阵存储结构的----图的深度遍历
void dfTraveradjMatrix(MGraph  G,int v,int visited[]){
    int j,p;
    //1.访问当前结点，通过给出的索引找到对应的结点
    println(G.vexs[v]);
    //2.修改状态为已访问状态
    visited[v]=1;
    scanf(&i,&j);
    for(j=0,p=-1;j<G.vex;j++){
      if(G.arcs[v][j]!=0){  //找到第一个邻接点
        p=j;
        break;
      }

      while(p=-1){
        if(visited[p]==0) dfTraveradjMatrix(G,p,visited);
        for(j=p+1,p=-1;j<G.vexNum;j++){
         if(G.arcs[v][j]!=0){
          p=j;break;
         }
        }
      }
    }
}

//基于——邻接表--的图的深度遍历 非递归算法

void df_traver_ALG_no(ALGraph G int v){
     int i,k;ArcNode p;
     SqStack  S,InitStack(&S);
     for(i=0;i<G.vexNum;i++ ){visited[i]=0;}
     println(G.adjList[v].vextex);
     visited[v]=1;
     pushStack(S,v);
     while( !StackIsEmpty(S)){
       k=getTop(S);
       p=G.adjList[k].firstArc;
       while(p){
            if(p && visited[p->adjVex].vextex){
             visited[p->adjvex]=1;
             pushStack(S,p->adjvex);
             break;
            }
            p=p->nextArc;
       }
       if(p==NULL){pop(S);}
     }
}


