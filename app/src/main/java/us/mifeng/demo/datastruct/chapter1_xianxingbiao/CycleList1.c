//
// Created by honeyLL on 2/6/21.
//循环链表
/*
 循环链表是一种头尾相接的表（表中最后一个结点的指针域指向头结点，整个链表形成一个环）
 优点：从表中任何一点出发都能找到表中其他结点
 单链表为空的条件：p!=Null 或者p->next !=Null
 单循环链表为空的条件；p!=L 或者 p->next !=L

 单循环链表 使用的是 ： 带尾指针的循环链表，因为使用带尾指针循环链表不管是找第一个结点（R->next->next）
 直接获取，时间复杂度为 o(1);然而尾指针直接是 R ,时间复杂度也为1，如果使用带头指针的但链表找最后一个结点
 的时间复杂度则为 o(n);
*/

/*
二。带尾指针的两个链表的合并操作

*/
LinkList  connect(LinkList Ta,LinkList Tb){
 LinkList p=Ta->next; //使用指针p 记住Ta 链表的头结点
 Ta->next=Tb->next->nextx; //Tb表头连接Ta的表尾
 free(Tb->next);           //释放Tb的头结点
 Tb->next=p;                //修改指针 Tb的表头连接Ta的表尾
return Tb;
}

/**
双向链表：
单向循环链表找后继结点只需要 o(1),但是找前驱困难，时间复杂度为o(n).因此引入了双向链表这一说法，
双向链表：在但链表的每个结点中再增加一个指向前驱的指针，这样就形成了有两个方向不同的链，称为双向链表。
/

//双向链表的结构
typedef struct DuLNode{
    ElemType data;
    struct DuLNode  *prior,*next;
}DuLNode,*DuLinkList;

双向循环链表为空的条件：L->next=L->prior=L;
  p->prior->next  =p =p->next->prior
  双向循环链表在插入和删除时，则需同时修改两个方向上的指针，两者的操作时间复杂度为 o(n)

//双向链表的插入算法  已知当前的结点为p,在p结点之前插入一个元素，具体示意图请查看doublelistinsert.jpg
*/
typedef struct DuLNode{
    ElemType data;
    struct DuLNode  *prior,*next;
}DuLNode,*DuLinkList;
 //1.在带头结点的双向循环链表中的第i 个位置插入元素e
 void  douListinsert(DuLinkList &L,int i,ElemType e){
    DuLinkList p,s;
    if(!(p=getElem(L,i))) return ERROR;
    s=(DuLinkList) malloc(sizeOf(LDNode));
    s->data=e;
    //插入操作，请查看drawable 下的doubleListInsert.jpg
    s->prior=p->prior;
    p->prior->next=s;
    s->next=p;
    p->prior=s;
    return OK;
 }

 //2.双向链表的删除操作， 在一个双向链表中将当前结点p所指的结点删除 ,并通过e来返回
 /*核心语句: p->prior->next=p->next;
            p->next->prior=p->prior;*/

void DuListDeletee(DuLinkList &L,int i,ElemType  &e){
    DuLinkList p;
    if(!(p=getElemP(L,i))) return ERROR;
    e=p->data;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    free(p);
    return OK;
}

//删除操作的时间复杂度为o(n)
/*随机存取是指我们可以通过下标取出任意一个元素 这是顺序表所特有的属性，
 链式存储的优点：结点空间可以动态的申请和释放；数
                据元素的逻辑次序靠结点的指针来指示，
                插入和删除不需要移动元素；
 链式存储的缺点：每个结点的指针域需要额外占用一定的存储空间，当每个结点的数据域所占字节不多时，
                指针域所占存储空间比重明显增加；
                链式存储是非随机存取，对任一结点的操作都得从头指针开始。依次查找，这增加了算法的复杂度

顺序表和链表的比较，请查看 图 drawable/seqandlinkcom.jpg 做了详细对比
*/

//3。有序表的合并，已知2个有序的线性表为非递减，现要求将其合并后的链表仍然是有序表
//通过顺序表来实现两个有序线性表的合并

void mergeList_sq(SqList  LA,SqList LB, SqList &Lc){
    /*
     定义了5个指针分别是 pa,pb ,pc, pa_last,pb_last;
     其中；
     pc

    */
    SqList pa, pb,pc,pa_last,pb_last;
    pa=LA.elem;                 //pa指向LA的第一个元素
    pb=LB.elem;                 //     pb指向LB的第一个元素；

    LC.length=LA.length +LB.length;  //新表长度为两个表之和
    LC.elem=new ElemType[LC.length]; //指向新表的第一个元素
    pc=LC.elem;                     //pc指向新合并的LC的第一个元素
    pa_last=LA.elem + LA.length -1; //pa_last指向LA最后一个元素；
    pb_last=LB.elem +LB.length-1;  //pb_last指向LB最后一个元素

    //选取两个表中小的元素插入到新的表中去
    while(pa <= pa_last && pb <= pb_last){
        if(*pa < *pb){
          *pc ++=*pa ++;
         }else{
           *pc++= *pb ++;
         }
    }

    while(pa <pa_last) *pc ++= *pa ++; //将LA 中剩余的元素加入到LC中
    while(pb <pb_last) *pc ++= *pb ++; //将LB 中剩余的元素加入到LC中
}
//算法的时间复杂度为（LA.length +LB.length）
//空间复杂度为（LA.length +LB.length）

//4。通过链式存储的方式实现两个非递减有序表的合并操作，注意是带头结点的单链表

void mergeList_link(LinkList &La,LinkList &Lb,LinkList &Lc){
    LinkList pa,pb,pc;
    pa=La->next;
    pb=Lb->next;
    pc=Lc=La;
    while(pa && pb){
     if(pa->data <pb->data ){
        pc->next=pa;
        pc=pa;
        pa=pa->next;

     }else{
       pc->next=pb;
       pc=pb;
       pb=pb->next;
     }
    }
    pa->next?pa:pb ;
    free(Lb);
}
//算法的时间复杂度为 o(min(La.length,Lb.length))
//空间复杂度 o(1) 不需要额外的空间

//5。算法5  使用链式存储实现稀疏多项式的求和问题 具体多项式请查看drawable / duoxaingshi.jpg 图
 //1. 定义多项式的结构描述
 typedef  struct PNode{
  float ceof ; //多项式的系数
  int expn;     //相应系数对应的指数
  struct PNode *next; //指针域
 }pNode, *Polynomial;

 //创建多项式的算法
 void createPolyn(Polynomial &p,int n){
    p=(Polynomial) malloc(sizeOf(PNode));
    p->next=NUll;
    Polynomial s,q,pre;
    for(int i=0;i<n;i++){
     s=(Polynomial) malloc(sizeOf(PNode));
      scanf("%f",&s->ceof);
      scanf("%d",&s->expn);
      pre=p;
      q=p->next;
      while(q && q->expn <s->expn){
        pre=q;
        q=q->next;
      }

      s->next=q;
      pre->next=s;
    }
  }

  /*到这里多项式的链表已经创建好，接着就是做多项式的运算问题，依次循环判断每个结点中指数的大小，
  将指数小的结点放入到新链表的首元结点，然后依次比较每个结点的指数，如果指数相同，则进行系数的
  求和运算，并将运算后的数存入新的链表中，如果运算后系数之和为 0 ，则直接不存入新的链表中。
  */

