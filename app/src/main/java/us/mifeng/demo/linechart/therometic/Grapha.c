#include<stdi0.h>
#include<stdlib.h>
#include<string.h>
无向图的数据结构描述
typedef struct ArcBox{
 int marked; //标识给顶点是否被访问过，
 int ivext,jvext;//依附的i 和 j的两个顶点的位置
 struct ArcBox* hLink,tLink; //依附i的下一个顶点的指针和依附j的下一个顶点指针
 infoType *info;    //边的一些信息
}AcrBox;       //边的数据结构描述

头结点的数据结构
typedef struct VexBox{
 VertexType data;   //结点数据类型
 ArcBox *firstArc;//指向第一条边的指针
}VexBox;

无向图的数据结构
#define MAX_VERTEXT_SIZE 20;
typedef struct AMLGrapha{
VexBox adjmuList[MAX_VERTEXT_SIZE];
int arcNum,verNum;
}AMLGrapha;


//图的深度遍历的递归算法
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

//图的深度遍历的非递归算法，图的深度遍历算法，图的深度遍历是基于栈的操作，
//每个结点被访问一次，不能重复访问

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

