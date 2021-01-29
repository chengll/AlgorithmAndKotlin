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



