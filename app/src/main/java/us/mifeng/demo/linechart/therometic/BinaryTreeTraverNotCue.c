#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
二叉树的性质：
  1.在二叉树的第 i 层 上至多有2的（i-1）个结点，
    1.1  在第 i 层上至少有 1 个结点。
  2.深度为k的二叉树至多有2的k次方 减 1 个结点 （k>=1）;
	2.1 深度为 k的二叉树至少有 k个结点
 3.对于任何一个二叉树T,如果其叶子树为 n0，度为2的节点数为n2,则n0=n2+1;

    (3.1)叶子结点总数(n0)=度为2的数 (n2) + 1
    (3.2)总结点数（n）=总的分支数 + 1；
	(3.3)总结点数(n)=2*度为2的结点 (2*n2)+ 度为1的结点的数(n1) +度为0的结点 (n0)

	总的分支数= 总结点数 -1；
	总的分支数= 2倍的度为2的树 + n1


 一棵深度为k且有2的（k次方）-1 个结点的二叉树称为满二叉树
   （1）满二叉树的特点： 每一层上的结点数都是最大结点数（每层叶子结点都是 （2的(k-1)次方）个结点）；
   （2）叶子结点全部在最底层

   完全二叉树：
   		满二叉树是完全二叉树，

  4.具有n个结点的完全二叉树的深度为log2n（向下取整，取小的数目）+1：
  5.如果对一棵有n个结点的完全二叉树（深度为 log2n【向下取整】+1）
 */

 //二叉树中序遍历 非递归算法
void inOrderTraver(BTree T){
    BTree Stack[100],p=T;
    int top=-1;
    do
    {
        while (p!=NULL)
        {
            Stack[++top]=p;
            p=p->lChid;
        }
        p=Stack[top--];
        visit(p);
        p=p->rChild
        
    }while (! (p==NULL && top==-1));
    
}

/* 
二叉树前序遍历 非递归算法
 */
void PreOrderTraver(BTree T)}{
    BTree Stack[20],p=T;
    int top=-1;
    do
    {
       while (p!=NULL)
       {
           visit(p);
           Stack[++top]=p;
           p=p->lChild;
       }
       p=Stack[top--];
       p=p->rChild;
       
    } while (! (p==NULL && top==-1));
    

}