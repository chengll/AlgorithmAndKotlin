//
// Created by  honeyLL on 2/23/21.
//

/*
通过先序遍历的序列创建二叉树
 二叉树的先序遍历序列为 根 左右的关系，对于空结点使用 # 代替
 已先序序列为 ABC ## DE #G ## F###
 具体实现请查看 drawable/createbintree.jpg
*/

typedef struct BitNode{
        TElemType data;
        struct  BitNode *lChild,*rChild;
        }BitNode,*BiTree;

Status createBinaryTree(BiTree &T){
  scanf("%c",&ch);
  if(ch=="#") T=NUll;
  else{
    if(!T==(BitNode*)malloc(sizeOf(BitNode))){
       exit(OVERFLOW); //申请空间失败
    }
     T->data=ch; //生成根结点
     createBinaryTree(T->lChild); //创建左子树
     createBinaryTree(T->rChild); //创建右子树
    }
    return OK;
  }

  //计算二叉树的深度
  int  Depth(BiTree T){
   if(T==null) return 0;
   else{
     m=Depth(T->lChild);
     n=Depth(T->rChild);
     return m>n?m+1:n+1;
   }
  }
//计算二叉树的结点数
int nodeCount(BiTree T){
 if(T==null) return 0;
 else
 return nodeCount(T->lChild) +nodeCount(T->rChild) +1;
}

//计算叶子结点
int leafCount(BiTree T){
 if(T==null) return 0;
 if(T->lChild==null && T->rChild==null) return 1;
 else{
   return leafCount(T->lChild) +leafCount(T->rChild);
 }

}

/*
线索二叉树：
 当使用二叉链表存储二叉树时，可以很方便的找到某个结点的左右孩子，
 但是一搬情况下很难直接找到该结点在某种遍历序列中的前驱和后继；
 1.再遍历一次二叉树--浪费时间
 2.再增加两个指针域存放前驱和后继--浪费空间
 3.使用线索二叉树
   因为在二叉链表中，如果有n个结点，则总共有2*n 个指针域，因为n 个结点中有 n-1个孩子，
   即只有n-1 个指针是用来存放结点的，其他的n+1个指针域都是空的，
 4.线索：如果某个结点的左孩子为空，则将空的左孩子的指针域指向其前驱结点，
        如果某结点的右孩子为空，则将其空的右孩子指针域指向其后继，这种改变就称为线索（Threaded Binary Tree）；

        为了区分二叉树的两个指针域到底存放的是左右孩子还是线索，需要定义两个标志位来区分，分别是ltag和 rtag;
        并且约定；ltag=0, lChild 则指向该节点的左孩子；
                 ltag=1,lChild则指向该节点的前驱；
                 rtag=0,rChild指的是它的右孩子；
                 rtag=1;rChild指向该结点的后继
线索二叉树的结点结构：
 typedef struct BiThrNode{
  ElemType  data;
  int ltag,rtag;
  struct BiThrNode * lChild,rChild;
 }BiThrNode,*BiThrTree;

 二叉树的线索化理解请查看图drawable/bithredtree.jpg


 树和森林：
*/
