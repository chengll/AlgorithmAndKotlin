#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* 
已知二叉树是采用的是广义表形式作为输入，请写一个算法，建立该二叉树的二叉链表的存储结构
说明：
关于使用广义表存储二叉树的说明
（1）约定表中的一个字母代表一个结点的数据信息
（2）根结点作为由子树构成表的名字放在最前面
（3）每个结点的左子树和右子树之间用逗号隔开，若只有右子树而无左子树，则逗号不能省略；
（4）在整个广义表在未表加一个特殊字符（如@）作为结束的标志

  具体请查看图 ：广义表转二叉存储结构图 (guangyibiaotoerchalink.png)
  已知序列为：
  A(B(D),C(F(,E),G))@
 */

/* 
 算法核心思想：
   1.从左到右依次取元素，如果娶到的是字母，则建立一个新的结点，
     若该结点是根结点，则将该结点的地址送T;
     若该结点不是根结点，则将该结点作为左孩子（若标志为1）或者右孩子（若标志为2）
     链接到期双亲的结点上（双亲的地址在栈顶）；
  2.若取到的元素是左括弧'('，则表示一个新的子表的开始，将其标志设置为1，同时将前面那个结点
    的地址进栈，
  3.若取到的元素为右括号')', 则表明一个子表结束，做出栈操作
  4.若取到的元素是逗号，则表明以左孩子为根的子树处理完成，接着应该处理以右孩子为根的子树，
    将标志为2；
    如此处理处理广义表中每一个元素，直到 取到结束符号@为止；

 */
typedef struct{
    BTree *data;
    int maxSize;
}Stack;

typedef struct BTNode{
    char data;
    struct BTNode* lChild;
    struct BTNode* rChild;
}BTNode,*BTree;
#define NodeNum 100
BTree createTable(){
   BTree T,Stack[NodeNum],p;
   int flag=-1,top=-1; 
   char ch;
   while (1)
   {
       scanf("%c",&ch);
       switch (ch)
       {
       case '@':
          return NULL;
           break;
      case '(':
         Stack[++top]=p;
         flag=1;
         break;
      case ')':
         top--;
         flag=2;
       break;
       default: 
        p=(BTree*)malloc(sizeOf(BTNode));
        p->data=ch;
        p->lChild=p->rChild=NULL;
        if (!T)
        {
           T=p;
        }else if (flag==1)
        {
            Stack[top]->lChild=p;
        }else{
            Stack[top]->rChild;
        }
           break;
       }
   }
   
}