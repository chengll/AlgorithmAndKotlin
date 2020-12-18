#include<string.h>
#include<stdlib.h>
#include<stdlib.h>
/* 
 链式队列
 为了便于操作，用一个头指针记住链表的头结点（头结点的直接后继结点是队头），
 用一个尾指针记住链表的尾结点（队尾)
 */

// 链队列结点和指向结点的指针数据类型描述
typedef struct qnode{
    int data;//QueueElmtype 使用int代替，表示结点存放的数据类型
    struct qnode *next;//下个结点的指针
}Qnode,*QueueLink;

//链队列的数据类型描述
typedef struct{
  QueueLink front;
  QueueLink rear;
}QLink;

//1.初始化链队列
int InitLinkQueue(QLink *LQ){
 LQ->front=LQ->rear=(QueueLink)malloc(sizeof(Qnode));
  if (LQ->front==NULL){return 0;}
  LQ->front->next=NULL;
  return 1;
}

//2.判断链队列是否是空的,队头和队尾指针相等 则是空的
int LinkQueueEmpty(QLink LQ){
    if (LQ.front=LQ.rear){return 1;}
    return 0;
}

//3.求链队列的长度
int LinkQueueLength(QLink LQ){
    QueueLink p;
    int n=0;
    if (LQ.rear=LQ.front){return  0;}
    p=LQ.front->next;
    while (p!=LQ.rear)
    {
       n++;
       p=p->next;
    }
    return n;
}
//4.得到队头
int getLinkHead(QLink LQ,char e){
    if (LQ.rear=LQ.front){return 0;}
    //头指针的后继结点是队头，因此是LQ->front->next->data
    strcpy(e,LQ.front->next->data);
    return 1;
}

//5.进队操作
int EnqueueLink(QLink *LQ,int e){
    QueueLink p=malloc(sizeof(Qnode));
    if (p==NULL){
        printf("申请空间失败");
        return 0;
        }
    p->next=NULL;
    p->data=e;
    //或者 strcpy(p->data,e);
    //插入操作在队尾，因此修改的是LQ->rear
    p->next=LQ->rear->next;
    LQ->rear->next=p;
    return 1;
}

//6.出队操作
int DeLinkQueue(QLink *LQ,char *e){
    QueueLink p;
    if (LQ->front=LQ->rear){return 0;}
    strcpy(e,LQ->front->next->data);
    //让p指向队头
    p=LQ->front->next;
    LQ->front->next=p->next;
    //如果队列中只有一个元素，则当删除该结点后能够保证头指针和尾指针指向同一个地方
    if (LQ->rear==p)
    {
        LQ->rear=LQ->front;
    }
    free(p);
    return 1;
}

//遍历链队列

 int LinkQueueTravers(QLink LQ){
     QueueLink p;
     if (LQ.front=LQ.rear){return 0;}
     p=LQ.front->next;
    while (p!=LQ.rear)
    {  printf("%d",p->data);
        p=p->next;
    }
    return 1;
 }
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


