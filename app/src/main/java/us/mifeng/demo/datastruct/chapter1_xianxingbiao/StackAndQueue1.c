//
// Created by honeyLL on 2/6/21.
//

#include<stdio.h>
#include<stdlin.h>
/*
 栈是一种数据插入和删除受限的线性表；
 栈的操作顺序是后进先出；
 栈是在表尾进行插入，删除的操作的线性表，表尾称为top,表头称为栈底 即base
 栈的逻辑结构也是一对一的，
 栈的存储结构也有顺序栈和链栈两种哦方式
 栈的运算规则是 后进先出的规则（LIFO）
 一组数据a1,a2...an 固定栈顶为an，栈底为a1,进出栈都是在栈顶进行的

 顺序栈：利用一组地址连续的存储单元依次存放从栈底到栈顶的元素，栈顶指针为top(an端) ，栈底为a1端。
 空栈的条件为 top==base=0；
 栈满的条件 ：top-base =stackSize; 注意这里top 和base 必须是同一个栈的指针
 顺序栈容易溢出：
 上溢：是指栈已经满了，又要压入栈元素（是一种错误）
 下溢：栈已经空了，还要弹出元素 （不认为是一种错误）
 初始化栈：构造一个空的栈
 顺序栈的C语言描述：
 #define MAX_SIZE 18
 typedef struct {
  SElemType  *base; //栈底指针
  SElemType  *top;  //栈顶指针
  int statckSize;   //栈可用的最大容量
 }SqStack
*/

 #define MAX_SIZE 18
 typedef struct {
  SElemType  *base; //栈底指针
  SElemType  *top;  //栈顶指针
  int statckSize;   //栈可用的最大容量
 }SqStack

 //1.初始化栈：
 Status Init(SqStack &s){
  S. base=(SElemType *) malloc(MAX_SIZE * sizeOf(SElemType));
  if(!S.base) OVERRFLOW; //分配失败
  S.top=S.base; //栈顶指针等于栈底指针
  S.stackSize=MAX_SIZE;
 }
 //2,出栈操作
 Status pop(SqStack &s,SElemType &e){
   if(SqStackIsEmpty(s)){  //或者是s.base==s.top
    return ERROR;
   }
   e=*--s.top;
   return OK;
 }

 //3.求表长
 int  stackLength(SqStack s){
 return s.top-s.base;
 }

 //4.清空栈
Status  clearStack(SqStack s){
if(s.base) s.top=s.base;
return OK;
}
//销毁栈
Status destroyStack(SqStack &s){
    if(s.base){
      delete s.base;
      s.base=s.top=NUll;
    }
    return OK;
}
//6.入栈
Status push(SqStack &s,ElemType e){
  if(s.top-s.base==s.stackSize){
   return ERROR;
  }
  *s.top ++=e; //等价与 *s.top =e   s.top++;
  return OK;
}


/********************栈的链式存储***********************/
//链栈的C语言描述
 typedef struct StackNode{
   SElemType data;
   struct StackNode * next;
 }StackNode,*LinkStack;
 使用的时候为 LinkStack s;

 //1。链栈的初始化：
 Status initLinkStack(LinkStack &s){
   s=NUll;
   return OK;
 }

 //2.链栈为空的算法
 Status isEmptyLinkStack(LinkStack s){
 if(s==NUll)  return OK;
 return ERROR;
 }
 //3.链栈的入栈操作
 Status push(LinkStack &s,SElemType e){
 LinkStack p;
 p=(LinkStack) malloc(sizeOf(StackNode));
 p->data=e;
 p->next=s;
 p=s;
 return OK;
 }
 //4.链栈的出栈操作
 Status poo(LinkStack &s ,SEleType &e){
   if(s==NUll) return ERROR;
   e=s->data;
   p=s;
   s=s->next;
   free(p);
   return OK;
 }
 //3.栈与递归
 /*
  递归：若一个对象部分包含自己，或者自己给自己定义，则称该对象为递归，
  若一个过程直接或者间接的调用自己，则称为递归调用
  嵌套调用，最后调用的方法的结果最先返回，符合栈的数据结构操作
  具体调用回溯的过程请查看 drawable/curearit.jpg
  递归的优点：结构清晰，程序容易读懂；
  缺点：每次调用都要生成工作记录，保存状态信息，入栈，返回时要出栈，回复状态信息，时间开销大

 */

 /****************队列的基本知识点 ********************/

 /*

 队列是一种先进先出得数据结构（FIFo），只能在队尾插入，在队头删除（即：头删除尾插入）的线性表
 表尾为an端，而表头为 a0端，它是一种先进先出的操作结构，即操作受限的线性表
 队列也有顺序存储结构和链式存储结构两种；
 顺序存储使用的是用一组一维数组来存储
 每一个数据结构都包含，数据对象，数据关系和基本操作三大块

 队列的抽象的基本数据类型：
 #define MAXSIZE 100;  //最大队列长度
 typedef struct {
    QElemType *base ;//指向数组的首元素，相当与a[0];
     int front;  //队头元素
    int rear;  //队尾元素
 }SqQueue;

 解决假溢出问题：将队空间设置成一个循环链表，即分配给该队列的元素可以进行循环使用，
 当rear 为maxSize 时，若队列的开头端空着，则可从头开始空着的空间，循环使用该空间，
 同理front 也是一样的。
 即：base[0]接在base【MaxSize-1】的后面，若rear +1=M,则令rear =0,利用 模运算 %
 插入元素在队列的尾部，所以插入元素的位置为：Q.base[Q.rear]=x;
 Q.rear=(Q.rear +1) %MAXSIZE;

 删除元素：删除元素时在队头操作，因此是头指针后移， x=Q.base[Q.front];
    Q.front=(Q.front +1) % MAXSIZE;

队列真溢出：若front=0；rear =MAXSIZE时，再入队是真溢出；
队列假溢出：当front！=0，（队列中还有空间）但是rear =MAXSIZE了，再次入队，则为假溢出；

 循环队列的队空和队满都是：front ==rear  ,解决方案有3种，分别是：
 1.另外设一个标志以区别队空，队满；
 2.另设一个变量，记录元素个数；
 3。少用一个元素空间（这种最常用）；队满的条件为：(rear +1) %MAXSIZE=front;
 */

//1.初始化队列的：
Status initSqQue(SqQueue &Q){
  return Q.front==Q.rear=0;
}

//2.队列为空的算法
Status isQueueEmpty(SqQueue Q){
Q.base=(QElemType *)malloc(MAXSIZE *sizeOf(QElemType));  //数组中首元素的地址其实就是一个指针
if(!Q.base) return ERROR;
return Q.rear=Q.front=0;
}

//3。循环队列的入队的操作
Status enqueeu(SqQueeu &Q,QElemType  x){
    if( (Q.rear+1)  % MAXSIZE==  Q.front);return ERROR;
    Q.base[Q.rear]=x;
    Q.rear=(Q.rear +1) %MAXSIZE;
    return OK;
}

//4。循环队列出队的操作：
Status deQueue(Squeue &Q,QElemType  &e){
  if(Q.front==Q.rear) return ERROR;
  x=Q.base[Q.front];
  Q.front=(Q.front +1) %MAXSIZE ;
  return OK;
}

//5。获取循环队列的长度
int QueueLength(Squeeu Q){
  return ((Q.rear- Q.front +MAXSIZE) %MAXSIZE);
}

//6.取队头元素：
SElemType getHead(SqQueue Q){
    if(Q.front !=Q.rear)
    return Q.base[Q.front];
}

/***************************链式队列的基本实现 *********************************/

/*
若用户无法肯定队列的长度，则建议使用链队列

链队列中结点的C语言数据描述：
#define MAXQUEEUSIZE  100;  //最大队列长度
 typedef struct QNode{
   QElemType data;
   struct QNode *next;
 }QNode,*QueuePtr;

 //定义链队列的数据结构描述
 typedef struct {
   QueuePtr front; //队头指针
   QueuePtr  rear; //队尾指针
 }LinkQueue;

*/

//1.链队列的初始化
Status initLinkQueue(LinkQueue &Q){
  Q.front=Q.rear=(QueuePtr) malloc(sizeOf(QNode));  //头尾指针都指向的空间
  if(!Q.front)  return ERROR;
  Q.front->next=NUll;
  return Ok;
}
//2。链队列的销毁
Status destroyLinkQue(LinkQueeu &Q){
  while(Q.front){
   p=Q.front->next;
   free(Q.front);
   Q.front=p;
  }
    return Ok;
}

//3.链队的入队
Status EnQueue(LinkQueue &Q,QElemType e){
  p=(QueuePtr)malloc(sizeOf(QNode));
  if(!p) return ERROR;
  p->data=e;
  p->next=NUll;
  Q->rear->next=p;
  Q->rear=p;
  return OK;
}

//4.链队列的出队
Status deQueue(LinkQueue &Q,QElemType &e){
  if(Q.front==Q.rear)  return ERROR;
  p=Q.front->next;
  e=p->data;
  Q.front->next=p->next;
  if(Q.rear==p)  Q.rear=Q.front;
  free(p);
  return OK;
}

//5.求链队列的头结点元素

Status getLinkHead(LinkQueue Q,QElemType &e){
  if(Q.front ==Q.rear) return ERROR;
  e=Q.front->next->data;
  return OK;
}