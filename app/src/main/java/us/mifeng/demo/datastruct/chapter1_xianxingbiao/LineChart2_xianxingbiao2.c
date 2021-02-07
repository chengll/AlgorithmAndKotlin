//
// Created by honeyLL on 1/29/21.
//

/*
 带头结点的单链表的类型

*/

typedef struct LNode{
  ElementType data;
  struct LNode * next;
}LNode,*LinkList;

//2。初始化 未初始化时由于链表是空的，因此使用的是引用类型的变量

Status initLinkList L(LinkList &L){
 L=new LNode; //c++的语法
 //2。或者是C的语法表示
 L=(LinkList) malloc(sizeOf(LNode));
 L->next=NUll;
}

//3。判断链是否为空
 int isEmpty(LinkList L){
   if(L->next==NUll){
   return 0; //非空

   }else{
   return -1;//空
   }
 }

 //4。清空但链表  只是清空数据 将头结点的指针域设置为空，结点都被释放，只剩头结点和头指针


Status clearList(LinkList &L){
 LNode *p,*q;  //或者是LinkList p,q的形式
 p=L->next;
 while(p!=NuLL){
  q=p->next;
  delete p;
  p=q;
 }
  L->next=NULl;
  return OK;
}

//5。求但链表的表长  从首元结点开始，依次计数所有的结点
int getLenth(LinkList L){
LinkList p; //等价Lnode *p  指向结点的指针
p=L->next;
int i=0;
while(p!=NuLL){
  i++;
  p=p->next;
}

return i;
}

//6.带头结点的单链表  取单链表中的某个元素  链表不是随机存取的结构
int location(LinkList L,int i,ElemType &e){
  Lnode * p;
  p=L->next;
  int j=1;
  while(p!=Null && i!=j){
    j++;
    p=p->next;
  }
  if(!p && j>i) return ERROR; //第i个元素不存在
  e=p->data;
  return OK;
}

//7.按照值查找---根据指定的数据获取该数据所在的位置
LNode *locateElem(LinkList l,Elemtype e){
LNode * p=l->next; int j=1;

 while(p && p->data!=e){
 p=p->next;j++;
 }
 if(p) return j; //找到了该数据，则返回是第几个位置元素
 else  return 0;
 return p;
}

//8.插入操作----在链表L中的第i个位置插入元素 e
Status insert_data( LinkList &L,int i,ElemType e){
LinkList p;int j;
p=L->next;
while(p && j<i-1){
 j++;
 p=p->next;
}
 if(!p && j>i+1)
    return ERROR;
    s=(LinkList) malloc(sizeOf(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

//9.删除单链表第i个结点
Status listDelete(LinkList &L,int i,ElemType &e){
LinkList p=L,q; int j=0;
while(p->next && j<=i-1){
 p=p->next;
 j++;
}
if(!(p->next) && j>i-1) return ERROR;
    q=p->next;
    p->next=q->next;
    e=q->data;
    delete q;
    return Ok;
}

//10 头插法：每次将新生成的结点插入到头结点之后
void createList_Head(LinkList &L,int n){
 L=(LinkList) malloc(sizeOf(LNode));
 L->next=NUll;
 LinkList p; //或者是 LNode * p;
 for(int i=0;i<n;i++){
  p=(LinkList) malloc(sizeOf(LNode));
  scanf(p->data);
  //插入
  p->next=L->next;
  L->next=p;

 }
}

//11.尾插入法：每次将需要插入的元素插入到该链表的尾部

void CreateList_R(LinkList &L,int n){
 L=(LinkList) malloc(sizeOf(LNode));
 L->next=NUll;
 LinkList p,r;
 r=L->next;
 for(int i=0;i<n;i++){
  p=(LinkList) mallioc(sizeOf(LNode));
  p->next=NUll;
  scanf(p->data);
  //插入
  r->next=p;
  r=p;
 }
}




