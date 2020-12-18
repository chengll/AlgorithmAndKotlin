#include <stdio.h>
#include <stdlib.h>
/* 
 一、线索二叉树：
    1.直接指向前驱结点和直接指向后继结点的指针被称为线索；
    2、加了线索的二叉树叫做线程二叉树；
    3、可以利用某结点空的左指针域来存放直接前驱，用某结点空的右指针域来存放直接后继；
    4、对于那些非空的指针域，则任然存放它的左孩子和右孩子；
    5、线索二叉树也分为 先序线索二叉树，中序线索二叉树和后序线索二叉树
二、设立标志位ltag和rtag：
    ltag: 0:表示该节点有有左孩子结点，它的线索就是他的左孩子；
          1：表示该结点左子树是空的的，存放的就是线索 p->lchild,指向直接前驱结点的指针
    rtag: 0:表示该结点有右孩子结点，它的线索就是它的右孩子
          1：表示该结点右子树是空的的，存放的就是线索 p->rChild,指向直接直接后继驱结点的指针

三、结点二叉树结点的结构为：
        lchild--->ltag-->data -->rtag--->rchild;
        为了将二叉树所有空的指针域都利用上，并方便遍历操作何时结束，在存储线索二叉树的时增设
        一个头结点，头结点的结构和别的结点是一样的，只不过数据是空的，初始化时，使其左指针域
        指向二叉树的根结点，右指针域指向自己。 线索化完成以后，让头结点的右指针域指向某遍历下
        的最后一个结点。而原来二叉树在某序遍历下的第一个结点的前驱线索和最后一个结点的后继线索
        都指向该头结点。
四、建立一棵中序遍历二叉树：
        建立线索二叉树或者二叉树线索化，其实就是遍历二叉树，在遍历的过程中。将访问结点的操作改为
        检查当前结点的左右指针域是否为空的操作，如果为空，将他们设置为指向直接前驱或者直接后驱的
        线索。；为了实现这个，假设pre始终指向刚刚访问过的结点，若指针p指向当前结点，则pre指向它的前驱


 */
//线索二叉树结构
typedef char ElemType;
typedef struct BiThrNode
{
    ElemType data;
    int ltag;
    struct BiThrNode *lchild;
    int rtag;
    struct BiThrNode *rchild;
} BiThrNodeType, *BiThTree;

//建立中序线索二叉树  左跟右
void inThreading(BiThTree p, BiThTree pre)
{
    if (p)
    {
        inThreading(p->lchild, pre);
        if (!p->lchild)
        { //左指针域是空的
            p->ltag = 1;
            p->lchild = pre;
        }
        else
        { //左指针域不空
            p->ltag = 0;
        }
        if (!pre->rchild)
        {
            pre->rtag = 1;
            pre->rchild = p;
        }
        else
        {
            pre->rtag = 0;
            pre->rchild = p;
        }
        inThreading(p->rchild, pre);
    }
}

//2.建立中序带头结点的线索二叉树  左跟右
int inOrderCul(BiThTree head, BiThTree T)
{
    if (!(head = (BiThTree)malloc(sizeof(BiThrNodeType))))
    {
        return -1;
    }
    head->ltag = 0;
    head->rtag = 1;
    head->rchild = head;
    BiThTree pre;
    if (!T)
    {
        head->lchild = head;
    }
    else
    {
        head->lchild = T;
        pre = head;
        inThreading(T, &pre);
        pre->rchild = head;
        pre->rtag = 1;
        head->rchild = pre;
    }
    return 1;
}

//中序线索化二叉树找直接后继
BiThTree inOrderPostNode(BiThTree p)
{
    BiThTree post = p->rchild;
    if (p->rtag != 1)
    {
        while (post->rtag == 0)
        {
            post = post->lchild;
        }
        return (post);
    }
}

//在中序线索二叉树上进行中序遍历
void ThrInOrder(BiThTree head)
{
    BiThTree p = head->lchild;
    while (p->ltag == 0)
    { //如果有左孩子，则继续遍历，找最左侧
        p = p->lchild;
    }
    while (p != head)
    {
        printf("%c", p->data);
        p = inOrderPostNode(head);
    }
}

//在中序线索二叉树上寻找结点p的先序的后继结点，head为线索树的头结点
BiThTree IprePostNode(BiThTree head,BiThTree  p){
    BiThTree post;
    if (p->ltag==0){//如果p结点有左孩子
        post=p->lchild;
    }else{
        post=p; //如果p结点没有左孩子，post和p同时指向一个结点
        while (post->rtag==1 && post->rchild!=head)
        {
            post=post->rchild;
        }
        post=post->rchild;
    }
    return (post);
}
//在中序线索二叉树上进行前序遍历
void ThpreIoOrder(BiThTree head){
    BiThTree p=head->lchild;
}