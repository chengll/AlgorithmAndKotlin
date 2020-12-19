#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//顺序查找(顺序表一会和链表)
//1.线性表实现  继续挑选好的算法合并
int searchArray(int arr[], int key, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
//2.链表实现顺序查找
LNode *search(LNode *head, int key)
{
    LNode *p = head->next;
    while (p != NULL)
    {
        if (p->data == key)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }
    return NULL;
}

//折半查找算法---适用于严格有序的一组数
int bSearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
/* 分块查找
   特点是整个数组是无序的，但是某一块中的数是有一定的规律的，因此
    每次将每块中的最大值挑出来，然后给其设计一款结构体
    分块查找的有自己的数据结构，因此在查找时需要先建立索引，
    根据索引表来决定去哪块查找

eg:待排序数； 2 1 0   3 5 4   7 6 8   9 10 11  15 18 20
数组中序号    0 1 2   3 4 5   6 7 8   9 10 11  12 13 14
每个块中的maxKey: 2    5        8       11      20
 */
typedef struct
{
    int maxkey;
    int low, high;
} inedexElem;
inedexElem index[5]; //该数组用来存放每一个分组中的key的个数
int keys[15];        //存放所有的keys的序号总数
int blockSearch(int key, int a[])
{
    int i = 1, j;
    while (i <= 3 && key > index[i].maxkey) //确定在那个块中查找
        i++;
    if (i > 3)
    {
        return 0;
    } //大于分的块数，则返回0
    j = index[i].low;
    while (j <= index[i].high && a[j] != key) //在确定的块内查找
        j++;
    if (j > index[i].high)
    {
        j = 0;
        return j;
    }
}

typedef struct
{
    int data;
    BTNode *right;
    BTNode *left;

} BTNode;

/*
 二叉排序树
 */
BTNode *bstSearch(BTNode *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        else if (key > p->data)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    return NULL;
}

//二叉树排序的递归
BTNode *btSearchRecusion(BTNode *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        else if (key < p->data)
        {
            return btSearchRecusion(p->left, key);
        }
        else
        {
            return btSearchRecusion(p->right, key);
        }
    }
}

/* 二叉排序树的插入操作的算法
   同时也是一个创建树的过程 其特点是：树的结构通常不是一次生成的，而是在查找过程中，当树中不存在关键字等于
   给定值的结点时再进行插入。新插入的结点一定是一个新添加的叶子结点，并且是查找不成功时
   查找路径上访问的最后一个结点的左孩子或右孩子结点。二叉排序树的平均情况分析：在一般情况下，设p(n,i)为它的的
   左子树的结点个数为i时的平均查找长度，如图结点的个数为n=6，i=3;
   平均查找长度为：o(logn)
 */
int insertBT(BTNode *&p, int key)
{
    if (p == NULL) //如果是空树
    {
        p = (BTNode *)malloc(sizeof(BTNode));
        p->left = p->right = NULL;
        p->data = key;
        return 1;
    }
    else
    {
        if (key == p->data)
        {
            return 1;
        }
        else if (key < p->data)
        {
            return insertBT(p->left, key);
        }
        else
        {
            return insertBT(p->right, key);
        }
    }
    return 0;
}

/*
 二叉排序树的删除操作
 在二叉树中删除一个结点需要分情况：
 1.若*p的结点为叶子结点，即PL(左子树)和右子树（PR）都为空，由于删除结点不影响二叉树的结构，则直接删除即可。
 2.若*p结点只有左子树PL或者右子树PR,此时只要令PL和PR直接成为双亲结点*f的左子树(当p只有左子树的情况)或者
 让p成为双亲结点的右子树（当p只有右子树时）即可，此操作也不会破坏二叉排序树树的结构。
 3.若*P的左右子树均不为空，在删去 *p之后，为保持其元素之间的相对位置不变，
    可以按照中序遍历的保持有序进行调整，有两种做法， ***第一种**：令*p的左子树为*f的左/右子树（如果p是f的左子树，
    就将*p作为双亲f的左子树，如果*p是双亲f的右子树，就将p作为*f的右子树），*s为*p左子树最右下的结点，而
    *p的右子树为*s的右子树；
    ****第二种：****
    令*p的直接前驱（或直接后继）替代*p,然后再从二叉排序树中删除它的直接前驱
    （或者直接后继），即： 让*f的左子树（如果有的话）成为*p的左子树的最左下
    的结点（如果p有左子树的话），再让*f成为*p的左右结点的父结点。
    在二叉排序树删除节点的算法。
 */
int deleteNode(BTNode *fp, BTNode *p)
{
    BTNode q;
    if (p->right == NULL) //p的右子树为空，则只需链接左子树
    {
        fp->left = p->left;
        deleteNode(p);
        return 1;
    }
    else if (p->left == NULL) //p的左子树为空，则只需链接右子树
    {
        fp->right = p->right;
        deleteNode(p);
        return 1;
    }
    else
    { //p的左右子树均不为空
        q = p;
        fp->left = p - left;
        s = p->left; //转左
        while (s->right)
        {
            q = s;
            s = s->right;
        } //此时q是s的父结点
        s->right = p->right;
        deleteNode(p);
        return 1;
    }
    return -1;
}
struct BiTree
{
    int data;
    BiTree *lchild;
    BiTree *rchild;
};
#define Status bool
Status Delete(BiTree *); //必须先声明
//若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素，并返回TRUE；否则返回FALSE
bool DeleteBST(BiTree &TParent, BiTree &T, int key)
{
    if (!T) //不存在关键字等于key的数据元素
        return false;
    else
    {
        if (key == T->data.key) //找到关键字等于key的数据元素
            return Delete(TParent, T);
        else if (key < T->data.key)
            return DeleteBST(T, T->lchild, key);
        else
            return DeleteBST(T, T->rchild, key);
    }
    return true;
}
bool Delete(BiTree &fp, BiTree &p) //从二叉排序树中删除结点p，并重接它的左或右子树
{
    if (!p->rchild) //右子树空则只需重接它的左子树
    {
        fp->lchild = p->lchild;
        delete (p);
    }
    else if (!p->lchild) //左子树空只需重接它的右子树
    {
        fp->rchild = p->rchild;
        delete (p);
    }
    else //左右子树均不空
    {
        q = p;
        fp->lchild = p->lchild;
        s = p->lchild;    //转左
        while (s->rchild) //然后向右到尽头
        {
            q = s;
            s = s->rchild;
        }                      //此时q是s的父结点
        s->rchild = p->rchild; //将s的左子树作为q的右子树
        delete (p);
    }
    return true;
}