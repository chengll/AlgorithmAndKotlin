#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
  基于图的广度优先遍历算法的 最短路径算法
*/
  //队列数据结构
  typedef struct  Queue{
       char  data;
       struct Queue * prior; //队头指针
       struct Queue *next;   //队尾指针
  }Queue,*Queue;

  #define VERNUM 20;
  typedef struct {
       VextexType vexs[VERNUM];
       int arcs[VERNUM][VERNUM];
       int verNum,arcNum;
  }MGraph;

void BFSearchLeastPath(MGraph G,int  vi,int vj,Queue *Q){
int w,v,vj;
    //将每个顶点的标志访问改为未访问状态，
    for(int i=0;i<G.vexNum;i++){
     visited[i]=0;
    }

    InitQueue(&Q);
    Enqueue(Q,vi);visited[vi]=1;
    while(!QueueIsEmpty(Q)){
       v=Dequeue(Q);
      for( w=0;w<G.vexNum;w++){
       if(G.arcs[v][w] && visited[w]==0){
         visited[w]=1;Enqueue(Q,w);
         if(w==vj)break;
       }
      }
      if(w>G.vexNum) break;
    }
}
//进对列的方法

void Enqueue(Queue *Q,QElemType e){
     Queue *p;
     p=(Queue*)malloc(sizeOf(Queue));
     p->data=e;
     p->next=NULL;
     p->prior=Q->front;
     Q->rear->next=p;
     Q->rear=p;
}

//出队

void Dequeue(Queue *Q){
   Q->front=Q->front-next;
}
