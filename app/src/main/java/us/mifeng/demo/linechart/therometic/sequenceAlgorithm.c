#include<studio.h>
#include<stdlib.h>
#include<string.h>
/** 单循环链表中删除元素x**/
void deleteQ(LinkList &L,LinkList q){
	LinkList r=list;
	if(q==list){
	list=list->link;
	free(q);
	}else{
 		while(r->link!=q && r->link!=x){
 			r=r->link;
 			if (r->link!=null)
 			{
 				r->link=q->link;
 				free(q);
 			}else{
 				printf("%s\n","没有找到x位置" );
 			}
 		}

	}
}

//查找线性表中值为k的元素
LinkList getLink(LinkList L,int k){
	LinkList q=p=list;
	int i;
	while(p!=NULL && i!=k){
		p=p->link;
	}

	if (p==NULL)
		{
			printf("没有正确的k的位置")；
			break;
		}else{
			while(p!=NULL){
				p=p->link;
				q=q->link;
			}
		}
  return q;
}

//约瑟夫环游戏
/*
 约瑟夫环游戏：所有的人围绕着一个圈子转，人的总数为n,从第k个人开始报数，数到m的时候，将第m个元素删除，
 然后下一个人又从0开始报数，到m又将这个人删除

*/

void JOSEPHONE(int n ,int k,int m){
	LinkList list=NULL;
	LinkList p,r;
	p=q=list;
	//1.创建循环链表
	for (int i = 0; i < n; ++i)
	{
		p=(LinkList*)malloc(sizeOf(LNode));
		p->data=i;
		p->link=null;

	}
	if (list==NULL)
	{
		list=p;
	}else{
		r->link=p; //尾部插入法
	}
	p->link=list;
	//1到此处循环链表创建完成

 	/**2.寻找开始报数的位置  做完该操作以后，p所指的位置就是开始报数的位置**/
 	for (int i = 1; i < k-1; ++i)
 	{
 		r=p;
 		p=p->link;
 	}

 	/**3.做完以上的操作，p所指的位置就是开始报数的位置，从p所指的位置开始，然后间隔m个，将m-1个数进行删除
         接着写约瑟夫环的删除的算法
 	**/
         while(p->link!=p){
         	for (int i = 1; i < m-1; ++i)
         	{
         		r=p;
         		p=p->link;
         	}
         	//通过循环找到了那个要报数到m-1的那个人
         	r->link=p->link;
         	free(p);
         	printf("%s\n","第一次报数到m的人已经被删除，下一个人开始报数吧" );
         	p=r->link;

         }

}
typedef struct DNode{
	ElemType data;
	struct DNode* rLink,*lLink;
}DNode,*DLinkList;

/**双向循环链表中插入在x位置插入item**/
int insertData(DLinkList list,int x,ElemType item,int n){
  DLinkList p,q;
  q=list->rink;
  while(q!=list && q->data!=x){
  	q=q->next;
  }
  //如果从头找一遍没有找到则返回失败
  if (q==NULL)
  {
  	printf("%s\n","没有找到x位置哦" );
  	break;
  }else{
  	//如果执行到这里，则表示q所指的位置就是x的位置，则需要将新的结点插入到x之后
  	p=(DLinkList*) malloc(sizeOf(DNode));
  	p->data=item;
  	//开始插入
  	q->rink=lLink=p;
  	p->rink=q->rink;
  	q->rink=p;
  	p->rink=q;
  	//插入成功
  	return 1;
  }
  return -1；
}

/*双向循环链表的删除操作，将线性表中x位置的元素从双向链表中删除*/
int deleteElem(DLinkList list,ElemType x){
	DLinkList q;
	q=list->rink;
	while(q!=list && q->data!=x){
		q=q->rink;
	}
	if (q==list)
	{
		printf("%s\n","查找x位置失败，程序退出" );
		return -1;
	}else{
		//q所指的位置就是当前需要删除的位置
		q->lLink->rink=q->rink;
		q->rink->lLink=q->lLink;
		free(q);
		return 1;
	}
	return -1;
}