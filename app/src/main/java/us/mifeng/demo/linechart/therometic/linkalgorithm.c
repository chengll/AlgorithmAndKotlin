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

//查找链表中位置为k的元素
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

//写算法实现键盘输入n个整数，建立一个不包含重复元素的顺序表
void buildList(int A[],int n){
	int flag=0,i,j;
	scanf("%d",&A[0]);
	while(i<n-1){
		scanf("%d",&A[i+1]);
		for ( j = 0; j < =i; ++j)
		{
			if (A[j]=A[i+1])
			{   flag=1;
				break;
			}
			if (flag!=1)
			{
				i++;
			}else{
				flag=0;
			}
		}
	}
}

//已知长度为n的非空线性表A的数据元素按值大小非递减排列。写一算法，实现将表中重复的元素删除
void deleteRepeateNum(int A[],int &n){
	int i=0,j;
	while(i<n){
		if (A[i]!=A[i++])
		{
			i++;
		}else{
			for (j = i; j < n; j++)
			{
				A[j-1]=A[j];
			}
			n--;
		}
	}
}


//删除非空链表中数据域相同的数据元素
void  delete(LinkList list){
	LinkList p,q,r;
	p=list-link;
	r=list;
	int flag;
	while(p!=NULL){
		q=list;
		while(p!=q){
			if (p->data==q->data)
			{
				r->link=p->link;
				flag=1;
				free(p);
				break;
			}else{
				q=q->link;
			}
		}

		if (flag)
		{
			r->link=p;
			flag=0;
		}else{
			r=p;
			p=p->link;
		}

	}

}

 //将非空链表中最小的那个数移动到链表的最前面
void moveMinToHead(LinkList list){
	LinkList p=list->link，s;
	LinkList q=list;
	r=list;
    while(p!=NULL){
    	if (p->data <q->data)
    	{
    		s=r;
    		q=p;
    	}
    	r=p;
    	p=p->link;
    }
    if (q!=list)
    	{
    		s->link=q->link;
    		q->link=list;
    		list=q;
    	}
}

//写一算法将链表中数据最大的数据域最大的那个值移动到最后面
void moveMaxIntoLast(LinkList list){
	LinkList p,q,r,s;
	p=list->link;
	q=list;
	r=list;
	while(p!=NULL){
		if (p->data >q->data)
		{
			s=r;
			q=p;
		}
		r=p;
		p=p->link;
	}

	if (q!=r)
	{
		if (q==list)
		{
			list=q->link;
		}else{
			s->link=q->link;
		}
		r->link=q;
		q->link=NULL;
	}
}

/*写算法实现就地逆转一个线性表  (到这里了)  其实质是头插法 第一次r是空的，
 将12插入到 r 中，然后让r指向q,
 2.q指向下一个p的值，头插法将p当前的值插入，p->link=r; r=p;
 3.最后让list指向q 即可：list=q;
 */


void inverseLinear(LinkList list){
	LinkList p,q,r;
	p=list;
	while(p!=NULL){
		r=p;
		q=p;
		p=p->link;
		q->link=r;
	}
	list=q;
}

/*
 依次输入一组整形的数据，并以Ctr+z作为输入结束，请写一算法，该算法依次打印最后k个数据元素
 (设输入的元素个数超过K)
*/
 void printVerseData(int k){
 	LinkList list,p,r;
 	int i,a;
 	list=(LinkList)malloc(sizeOf(Dnode));
 	for (int i = 0; i < k; ++i)
 	{
 		p=(LinkList)malloc(sizeOf(Dnode));
 		r->link=p;
 		r=p;
 	}
 	p->link=list;
 	p=list;
 	while(scanf("%d",&a)>0){
 			p->data=a;
 			p=p->link;
 	}
 	r=p;
 	do{
 		if (p->data!=0)
 		{
 			printf(p->data);
 		}

 	}while(p!=r);

 }

 //设计一个算法，将数组A[0......n-1]中所有元素右移动 k个位置
 void circulateData(ElemType A[],int k,int n){
 	int i,j;
 	ElemType temp;
 	for ( i = 1; i <=k; ++i)
 	{
 		temp=A[n-1];
 		for (j= n-2; j >= 0; j--)
 		{
 			A[j+1]=A[j];
 		}
 		A[0]=temp;
 	}

 }

//通过栈来实现递归函数
 /*
   已经知道 递归函数为：f(m，n)={
   	  m+n+1;             当m*n=0时
   	 f(m-1，f(m,n-1))		当m*n !=0时

   }

 */

   以m=2,n=1为例实现递归的过程
   当m=2,n=1时候 m*n!=0 所以调用 1. f(2-1,f(2,0))
   	2.f（1,0）中m=1,n=0 所以m*n=0; 所以f(2,0)调用m+n+1 =3；
   	3.f（2,3）中m=1,n=3 所以m*n!=0,所以f(1,3)调用f(m-1,f(m,n-1)) 运行结果为 f(0,f（1,3-1）)=f(0,f(1,2))
   	   f(0,f（1,3-1）)=f(0,f(1,2))继续执行 f(0,f(1,f(1,1)))->f(0,f(0,f(0,f(1,0))))->f(0,f(0,f(0,2)))
   	   ->f(0,f(0,3))->f(0,4)=0+4+1=5；

   	通过栈来实现递归算法

   	int fun（int m,int n）{
    	int Stack[MaxSize],top=-1;
    	if (m*n!=0)
    	{
    		Stack[++top]=m-1;
    		n--;
    	}else{
    		n=n+m+1;
    		if (top>0)
    		{
    			Stack[top--]=m;
    			top--;
    		}
    	}while(top>=-1);
    	return n;
    }





