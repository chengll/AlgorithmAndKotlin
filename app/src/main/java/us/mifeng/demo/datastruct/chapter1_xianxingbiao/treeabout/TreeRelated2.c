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

