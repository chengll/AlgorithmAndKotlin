#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
/* 
  顺序队列相关的内容
  1.队列是一边插入一边删除 ，左侧队头 ，右侧（队尾),
    队头删除， 队尾插入
 */
//顺序队列的数据结构描述
typedef struct {
    int front; //指向队头指针，
    int rear; //尾指针，指向队尾的下一个元素
    int queueSize;//队列的容量
    //存放队列数据元素的数组 QueueElemType data[MAXSIZE]; 用char QueueElemType
    char data[MAXSIZE]; 
}SqQueue;
//1.初始化循环队列,对队头队尾指针赋值，同时给队列最大的容量
int initSqQueue(SqQueue *LQ){
    LQ->front=LQ->rear=0;
    LQ->queueSize=MAXSIZE;
    return 1;
}
//2.判断队列是否为空的
int QueueEmpty(SqQueue LQ){
    if (LQ.front==LQ.rear) return 1;
    else return 0;
}

//3.求队列长度
int sqQueueLength(SqQueue LQ){
    return (LQ.rear- LQ.front+LQ.queueSize) %LQ.queueSize;
}
//4.获取队头，通过指针的形式返回地址,当队列不为空时，根据队头指针就可以得到队头
int sqGetHead(SqQueue LQ,char *e){
 if (LQ.front=LQ.rear){return -1;}
else
 *e=LQ.data[LQ.front];
 return 1;
}
//5.进队操作，如果队列不是满的，就进行进队操作,修改尾指针
int Enqueue(SqQueue *LQ,char e){
    if ((LQ->rear+1)%LQ->queueSize==LQ->front){return 0;}
    else{
     LQ->data[LQ->rear]=e;
     LQ->rear=(LQ->rear+1)%LQ->queueSize;
     return 1;
    }
    return 0;
}
//6.c出队的操作，如果队列不是空的，使用指针变量记住，然后修改队头指针的值
int DeQueue(SqQueue *LQ,char *e){
    if (LQ->front==LQ->rear){return 0;}
    *e=LQ->data[LQ->front];
    LQ->front=(LQ->front +1) %LQ->queueSize;
    return 1;
}
//7.遍历队列，如果队列不是空的 依次从头遍历每个元素
  int QueueTravers(SqQueue LQ){
      int n=LQ.front;
      if (LQ.front==LQ.rear){return 0;}
      while (n!=(LQ.rear+1)%LQ.queueSize)
      {
         printf("%d ",LQ.data[n]);
         n=(n+1)%LQ.queueSize;
      }
      printf("\n");
      return 1;
  }

int main(int argc, char const *argv[])
{
   SquPer Q1,Q2;           //模拟只挂两个专家的号
   int n1,n2;              //用来记录看那个医生的编号
   PER x;                 //病人
   initSqQueue(&Q1);//初始化1号医生的队列
   initSqQueue(&Q2);//初始化2号医生的队列
   int menuN= menu();
   while (1){
    switch (menuN){
        case  1:
        printf("请输入专家1/专家2和病人的名，用空格隔开\n");
        scanf("%s %s",x.docName,x.pName);
        if (strcmp(x.docName,"专家1")==0){
            x.seq++;
          //  Enqueue(&Q1,x);  入Q1队列
        }
        if (strcmp(x.docName,"专家2")==0)
        {
           x.seq++;
           //Enqueue(&Q2,x); //入Q2队列
        }
        printf("请按任意键继续\n");
        getch();
        break;
        case  2: 
            printf("专家1开始叫号");
            DeQueue(&Q1,&x);//第一个病人被叫到，则出队列
            sqGetHead(Q1,*x);
            printf("%s %s",x.pName,x.seq);//输出正在看医生的姓名和编号
            printf("\n");
            getch();
        break;
        case  3:
          DeQueue(&Q2,&x);
          sqGetHead(Q2,&x);
          printf("%s %s",x.pName,x.seq);//输出正在看医生的姓名和编号
          printf("\n");
          getch();
        break;
        case  4://显示正在救治的用户
            sqGetHead(Q1,&x);
            printf("正在 1 诊室的是%3d 号 %s",x.seq,x.pName);
            printf("目前1号诊室中还有 %d 号人在等候等待就诊\n",sqQueueLength(Q1)-1);
            printf("\n");
            sqGetHead(Q2,&x);
            printf("正在 2 诊室的是%3d 号 %s",x.seq,x.pName);
            printf("目前1号诊室中还有 %d 号人在等候等待就诊\n",sqQueueLength(Q2)-1);
            printf("\n");
            getch();
            break;

        case  0:
            exit(0);
            break;
        default:
            break;
    }
   }
   
    return 0;
}


/* 基于队列的医院挂号系统模拟 */

//每个结点的数据描述
typedef struct{
    char pName[20]; //病人姓名
    char docName[20]; //就诊医生姓名
    char depto[20]; //病人挂的科室的编号
    int seq;        //病人就医的编号
}PER;

//顺序链表的数据描述
typedef struct {
    int data[10];  //顺序队列存放病人
    int front;     //头指针
    int rear;      //尾指针
    int queueSize; //队列的容量

}SquPer;

int menu(){
    int n;
    while (1)
    {
        printf("欢迎使用基于队列的医院挂号模拟系统");
        printf("1.挂号  2.专家1叫号\n ");
        printf("3.专家2叫号  4.显示\n");
        printf(" 0.退出系统");
        printf("请选择1/2/3/4/0 \n");
        scanf("%d",&n);
        if (n>0 && n<4)return n;
        else{
            printf("功能编号输入有误，请重新选择，按任意键继续\n");
            getch();
        }
    }
    
}