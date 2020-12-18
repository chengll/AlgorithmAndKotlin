#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*

  一、树相关知识点
    1.树的结点:包含一个数据元素及若干指向其子树的分支
    2.结点的度:结点拥有的子树数
    3.根结点：无直接前驱
    4.叶子结点：度为零的结点，无后继
    5.分支结点：度不为零，除了根结点，分支节点也称为内部结点
    6.树的度：树中各节点度的最大值，比如A的度为1 B的度为2  C的3 ，则树的度为3
    7.孩子：结点的子树的根称为该结点的孩子，相应的该结点称为孩子的双亲。
    8.兄弟：同一双亲的孩子之间互为兄弟。
    9.祖先：结点的祖先是从根到该结点所经过所经分支上所有的结点。
   10.以某一结点为根的子树中的任意结点都称为该结点的子孙。
   11.树的深度（高度）：树中结点的最大层次

二、树的表示
    1、结点连线的表示：上方结点是下方结点的前驱，下方结点是上方结点的后继
    2、二元数组表示法：T=(D,R)  D={C,G,I,J}//存放树中所有的结点
                               R={<C,G>,<G,I>,<G,J>} //存放结点之间的关系
    3.集合图形表示法：每棵树对应一个圆形，圆内包含根节点和子树，
    4.凹入表示法：

三、树的抽象数据类型的描述：
ADT{
    数据对象：具有相同数据类型的数据元素的集合
    数据关系：具有一对多的层次关系；
}
四、二叉树
  1.二叉树的概念：
    二叉树或为空树，或是由一个根节点加上两棵分别称为左子树和右子树的，互不交叉的二叉树；
  2.特点：每个节点至多只有2棵子树，子树有左右之分，其次顺序不能任意颠倒
  3.满二叉树：二叉树中每一层的结点数都达到最大，所有的叶子结点均在最后一层，
  4.完全二叉树：1>除了最后一层，其余各层都是满的的；
               2>最后一层或者是满的，或者是右边缺少连续的若干结点。即叶子结点只能出现在
                最后一层或次上一层，
  5.理想平衡树：在一颗二叉树中， 若除了最后一层外，其余层都是满的，则称此树为理想平衡二叉树
              满二叉树和完全二叉树是理想二叉树，但理想平衡树不一定是完全二叉树。
    结论：二叉树是一种重要的 树形结构，但是二叉树不是树的特例。

五、二叉树性质
  1.在二叉树的第i层上至多有2的（i-1）次方个结点（i>=1）。
  推广：   m叉树的第i层至多有m的（i-1)次方格结点

  2.   一颗深度为k的二叉树中，最多有2的k次方 -1 个结点。
  3.对于一棵非空的二叉树，如果叶子结点为n0,度为2的结点数为n2，则
        n0=n2+1;
  4.具有n个结点的完全二叉树的深度为k的（log2）n+1；
  推广：对于n个结点的m叉树的最小深度为(logm)(n(m-1))+1
  5.对于一个有n个结点的完全二叉树（其深度为log2(n)+1）的结点按层序编号，（从上到下，从左到右）
    则对任意结点i，（1<=i <=n）;
    1>如果i=1,则 i 为根结点，如果i>1,则其双亲是结点【i/2]
    2>如果2i>n,则结点 i 为叶子结点，否则其左孩子结点是2i
    3>如果2i+1>n,则结点i无右孩子，否则其右孩子结点是2i+1，
    证明5性质：对于任意一颗完全二叉树，对编号为i 的结点，假设它所在的层为k
     1>>如果k层是最后一层，结点i为叶子结点。
     2>>如果k层不是最后一层，根据性质3，则 2的（k-1）次方< = i  且 i<=2的k次方 -1,
        在k层结点 i 的左侧有 （i- 2的 (k-1）次方个结点，每个结点都是度为2的结点；
        第k层的最后一个结点的编号为2的k次方-1，所以对于结点i，如果存在左孩子，左孩子的编号
        为2（i-2的（k-1)次方）+2的 k 次方 - 1 +1=2i；
        如果存在右孩子，则一定存在左孩子，所以右孩子的编号为 2i+1;

        当2i>n时，编号为2i的结点不存在，说明双亲结点i没有左孩子也没有右孩子，所以编号为 i 的
        结点一定是叶子结点，当2i<=n时，说明编号为2i的结点存在，是编号为 i左孩子；

        当2i+1>n时，编号为2i+1的结点不存在，说明双亲结点i没有右孩子；
        当2i+1<n时，说明编号为2i+1的结点存在，是编号为i的右孩子。

六、二叉树的抽象数据类型
  二叉树的抽象数据类型的描述：
  ADT BiTree{
    数据对象：由一个根结点和两棵互不相交的左右子树构成
    数据关系：结点具有相同数据类型及层次关系；
    基本操作:
    InitBiTree(&T)....
  }
 (一).二叉树的基本操作：
     1.初始化:InitBiTree(&T),构造一棵空的二叉树
     2.销毁操作：DestroyBiTree(&T);在二叉树存在的前提下做改该操作
     3.插入操作：InsertL(&T,x,parent)，前提：二叉树已经存在，将数据域为x的
               结点插入到二叉树中，作为结点parent的左孩子。如果结点parent原来有
               左孩子，则将结点 parent原来的左孩子作为结点x的左孩子，如果插入成功，
               则得到一棵新的二叉树；
     4.删除操作：DeleteL(&T,parent),前提是二叉树已经存在，操作，在二叉树中删除结点为
               parent的左子树，如果删除成功，则得到一颗新的二叉树。
     5.查询操作：Search(T,x,&p):前提是二叉树存在；操作：在二叉树中查找数据元素为x的元素，
                如果找到了，通过指针返回该结点的地址，二叉树不变
     6.前序遍历：PerOrder(T) 前提是二叉树已经存在，操作 根结点，左子树 右子树的顺序遍历
     7.中序遍历：InOrder(T)  前提是二叉树已经存在，操作 左子树,根结点， 右子树的顺序遍历
     8.后序遍历：PostOrder(T)  前提是二叉树已经存在，操作 左子树, 右子树, 根结点，的顺序遍历
     9.层次遍历：LeaverOrder(T) 前提是二叉树已经存在，层序遍历二叉树。

 (二)、顺序存储结构  ：就是使用一组存储单元连续的单元存放二叉树中的结点。存放顺序一般是
                  从上到下，从左到右的顺序存储。
                顺序存储一般适应于完全二叉树，如果不是完全二叉树，则要假装将二叉树补为完全二叉树，
                这种存储明显是浪费空间，比如最坏的情况，是一颗二叉树之后单右子树，一棵深度为k的右
                单枝树，只有k个结点，但是要申请 2的k次方 -1 个存储单元，
      顺序存储的数据结构形式描述：
      #define MAXNODE 100
      typedef ElementType SqBiTree[MAXNODE +1]
      SqBiTree  bt；
      则bt定义了含有MAXMODE+1个ElmenType类型元素的一维数组，可以存储儿二叉树，
      结论：顺序存储适用用完全二叉树，方便查找双亲和孩子

(三)、二叉链表的存储结构
      链表中每个结点由三个域组成，除了数据外，还有两个指针，分别用来存放该结点的左孩子和右孩子结点
      的存储地址，结点的存储结构如下：
      lchild--->data--->rchild，分别为左孩子 数据域和右孩子结点，当左右孩子不存在时，相应的指针域为空，

      1.链式存储二叉树的 性质：
      在含有n个结点的二叉链表中有 n+1个空指针；
       证明：因为每个结点有2个指针域。所以n个结点有 2n个指针域，又因为除了根节点之外，还有（n-1)个结点
            必须创建双亲和左右孩子关系，需要占用 n-1 个指针域，还剩下的指针域为 2n-(n-1)=n+1个空指针域

      2.二叉链表的类型定义：
          typedef struct BiTree{
            DataType data;   //存放结点的数据和其类型
            struct BiTree * lchild； //存放左子树根结点的地址
            struct BiTree * rchild ；//存放右子树根节点的地址
          }BiTNode,*BiTree;
        其中 BiTNode为二叉链表的结点类型，BiTree为指向二叉链表结点的类型

        注意：二叉链表便于访问孩子结点，但是不便于操作双亲结点，

      3.三叉链表：为了便于访问双亲结点，引入三叉链表，三叉链表的每个结点有4个域，分别是
          parent(双亲结点指针)--（lchild）左孩子指针--data(结点数据域)--rchild（右孩子指针)
         注意：其中的parent域为指向该结点双亲结点的指针，这种存储结构既便于孩子结点的查找，也
         便于双亲结点的查找，但是增加了空间的成本。

      4. 三叉链表的数据结构定义形式：
         typedef struct TriTNode{
           DataType data;
          struct TriTNode * parent;
          struct TriTNode * lChild;
          struct TriTNode * rChild;
         }TriTNode, *TriTree;
        TriTNode为三叉链表结点，TriTree 为指向三叉链表结点的指针，

    前序遍历：A(根) BDCEF  (根左右)
    中序遍历：BD A(根) ECF (左根右)
    后序遍历：DBEFCA(根)   (左右根)
    以下的遍历以该二叉树为例
 */
typedef struct BiTNode
{
  char data;
  struct BiTNode *lChild;
  struct BiTNode *rChild;
} BiTNode, *BitTree;
// 先序遍历二叉树的方法
void preOrder(BitTree T)
{
  if (T)
  {
    printf(T->data);
    preOrder(T->lChild);
    preOrder(T->rChild);
  }
}
// 中序遍历二叉树的方法
void inOrder(BitTree T)
{
  if (T)
  {
    inOrder(T->lChild);
    printf(T->data);
    inOrder(T->rChild);
  }
}
// 后序遍历二叉树的方法
void postOrder(BitTree T)
{
  if (T)
  {
    postOrder(T->lChild);
    postOrder(T->rChild);
    printf(T->data);
  }
}

//非递归形式的 二叉树的中序遍历算法

//栈的数据元素类型
typedef struct
{
  BitTree ptr; //指向根结点的指针
  int task;    //任务性质，1.表示遍历 2.表示访问
} ElemType;

//栈的类型定义
typedef struct
{
  ElemType data[20];
  int top;
} SqStack;

//1.非递归形式的 二叉树的 中序遍历  算法  遍历顺序是：根左右
void notRecursion(BitTree T)
{
  SqStack S;
  initStack(&S); //初始化一个栈
  ElemType e;    /* 定义结构体变量，包括2个字段，
                      ptr：指向根结点的指针
                      task 布置任务的状态，1遍历结点； 0访问结点 */
  e.ptr = T;
  e.task = 1;
  BitTree p;
  if (T)
    push(&S, e); //如果树不是空的，则根结点进栈
  while (!SqStackEmpty(S))
  {
    Pop(S, e); //根结点出栈 ，此时栈中为空
    if (e.task == 0)
    {
      printf(e.ptr->data); //处理访问的任务
    }
    else
    {                    //e.task==1 ;表示处理遍历的任务
      p = e.ptr;         //让指针p指向树的根结点，记住根的位置
      e.ptr = p->rChild; //然后让指针e.ptr指向p所指的根结点的右孩子结点
      if (e.ptr)
        push(&S, e);     //如果右孩子结点不为空，将右孩子压入站
      e.ptr = p;         //此时，e.ptr再次指向根结点。
      e.task = 0;        //将根结点的 任务状态改为访问
      push(&S, e);       //让当前的根结点再次进栈
      e.ptr = p->lChild; //此时，再让e.ptr 指针指向 p当前结点所指的根点的左孩子结点
      e.task = 1;        //将左孩子结点的任务状态修改为 1 遍历状态
      if (e.ptr)
      {              //如果左孩子结点不为空，让其进栈 ：第一轮循环完成后 栈中的顺序是CAB
        push(&S, e); //总之左子树是最后面进栈的，这样中序遍历（出栈）时可以符合（左 根 右）的顺序
      }
    }
  }
}

//2.非递归二叉树 后序遍历的算法 （左右根）
/*
  因此第一步核心工作就是找树的最左侧的结点
  进栈时：第一次遇见的结点地址进栈，同时将标记L存入字符数组；
  修改标记位：
 */
void NrPostOrder(BitTree T)
{
  BitTree t;
  SqStack s;
  initStack(&s);
  char lrTag[30];
  t = preGoFarLeft(T, &s, lrTag); //找二叉树最左侧的结点
  while (t)
  {
    lrTag[s.top] = 'R';
    if (t->rChild)
    { //如果最左侧的结点的右结点不为空，找右结点最左侧的结点
      t = preGoFarLeft(t->rChild, &s, lrTag);
    }
    else
    { //如果最左侧的结点的右子树为空，則让左侧的结点出栈
      while (!sqStack(s) && lrTag[s.top] == 'R')
      {
        Pop(&s, &t);
        printf("%d", t->data);
      }
      if (!sqStackEmpty(s))
      {
        getStackTop(&s, &t);
      }
      else
      {
        t = NULL;
      }
    }
  }
}

//查找二叉树最左侧的子树
BitTree preGoFarLeft(BitTree T, SqStack *s, char lrTag[])
{
  if (!T)
  {
    return NULL;
  }
  while (T)
  {
    push(&s, T);
    lrTag[s->top] = 'L';
    if (T->lChild == NULL)
      break;
    T = T->lChild;
  }
  return T;
}

//3. 非递归前序遍历二叉树 （根 左 右）
void NrPreOrder(BitTree T)
{
  BitTree p;
  SqStack s;
  initStack(&s);
  p = T; //让指针p 指向 T 树的根结点
  while (p != NULL || !sqStackEmpty(s))
  {
    while (p != NULL)
    {
      printf(p->data); //打印根结点
      push(&s, p);     //让根结点进栈 因为先遍历左子树，后面还需要遍历右子树，因此还需要将根结点进栈
      p = p->lChild;   //此时p指针指向p所指树的左结点，如果左孩子为空时，跳出第一个while循环
    }
    if (sqStackEmpty(s))
    {
      break;
    } //跳出循环后，判断栈是否为空，如果为空，直接结束
    else
    {
      pop(&s, &p);   //如果栈不为空，则让当前的根结点出栈
      p = p->rChild; //让 p结点指向它的右孩子结点，然后在进行判断第一层while循环，将p结点切到根结点的右边子树
    }
  }
}

/* 4. 层次遍历二叉树，从根结点出发，从上到下，从左到右依次访问每一个结点。
      层次遍历的特点是双亲结点的访问次序先于其孩子结点，先访问的双亲结点，其
      孩子结点的访问顺序也先于其他双亲的孩子结点，
      这些结点的保存和被访问正好符合 “先进先出” 的顺序，因此采用队列的存储方式，
      使用队列存放要访问的结点的指针

      遍历结果：ABCDEF
 */

void layer(BitTree T)
{
  QLink Q;
  initQueue(&Q);
  if (T)
  {
    Enqueeu(&Q, T->data);
  }
  BitTree p = T;
  while (!QueueEmpty(Q))
  {
    p = Dequeue(&Q);
    printf(p->data);
    if (p->lChild)
    {
      Enqueeu(&Q, p->lChild);
    }

    if (p->rChild)
    {
      Enqueeu(&Q, p->rChild);
    }
  }
}

//队列的数据结构
typedef struct qNode
{
  int data;
  struct qNode *next;
} qNode, *QueueLink;

typedef struct
{
  QueueLink front;
  QueueLink rear;
} QLink;

//按照  先序遍历 二叉树的规模 创建二叉树的递归算法
void createTree(BitTree *T)
{
  char ch;
  scanf("%c", &ch);
  if (ch == '#')
  {
    return *T = NULL;
  }
  else
  {
    *T = (BitTree)malloc(sizeof(BiTNode));
    (*T)->data = ch;
    createTree((*T)->lChild);
    createTree((*T)->rChild);
  }
}
//按照  先序遍历 二叉树的规模 创建二叉树的 非递归 算法
void create_tree(BitTree *T)
{
  QLink Q;
  initQueue(&Q);
  *T = NULL;
  BitTree p, s;
  char father, ch;
  int lrflag; //
  scanf("%c,%c,%d", &father, &ch, &lrflag);
  while (ch != '#')
  {
    p = (BitTree)malloc(sizeof(BiTNode));
    p->data = ch;
    p->lChild = p->rChild = NULL;
    Enqueeu(&Q, p);
    if (father == '#')
    {
      *T = p; //创建根结点
    }
    else
    {
      s = getQueueHead(Q);
      while (s->data != father)
      {
        Dequeue(&Q);
        s = getQueueHead(Q);
      }
      if (lrflag == 0)
      {
        s->lChild = p;
      }
      else
      {
        s->rChild = p;
      }
    }
    scanf("%c,%c,%d", &father, &ch, &lrflag);
  }
}

/**
  通过 先序遍历  和 中序遍历来还原二叉树
  1.pre[]:是先序遍历的序列  2.info[]:是中序遍历的序列
  3.n是序列字符个数  4.ps是先序遍历的第一个字符的位置，初始值为0；
  5.is:中序遍历第一个字符的位置，初始值为0
 */
void creatBiT_pre_inf(BitTree *T, char pre[], char info[], int ps, int is, int n)
{
  int k;
  if (n == 0)
  {
    *T = NULL;
  }
  else
  {
    *T = (BitTree)malloc(sizeof(BiTNode));
    if (!*T)
    {
      exit(0);
    }
    else
    {
      //在先序中查找根结点
      k = searchRoot(info, pre[ps]); //如果k=-1,没有找到，否则根结点在中序中
      if (k == -1)
      {
        *T = NULL;
      }
      else
      {
        if (!(*T = (BitTree)malloc(sizeof(BiTNode))))
        {
          exit(0);
        }
        (*T)->data = pre[ps];
        if (k == is)
        {
          (*T)->lChild = NULL;
        }else{
          creatBiT_pre_inf(&(*T)->lChild,pre,info,ps+1,is,k-is);//创建左子树
        }

        if(k=is+n-1){
          (*T)->rChild=NULL;
        }else{
          creatBiT_pre_inf(&(*T)->rChild,pre,info,ps+1+(k-is),k+1,n-(k-is)-1);//创建右边子树
        }
      }
    }
  }
}

/*
  关于二维指针问题：int a[][4]
  1)如果数组a是二维数组的首元素的地址，那么首元素不是简单的一个整形数据了，而是一个一维数组
  每行都是一个由4个整型元素所组成的一维数组，(a[0][0], a[0][1], a[0][2], a[0][3])同样
  其他每行的格式也是类似这种 为 a[i][j]格式，如果第一行的元素的首地址是2000时，此时第二行
  数组元素的首地址就是 2000+ 4(每个整形的占有内存单元) *4(列元素)=2016开始排列，但是每个列
  元素之间还是相差一个整形元素所占有的内存单元的数，比如 a[0][0]的地址是2000，那么a[0][1]
  的地址就是 2000+4=2004 ，同理依次类推;
  2)如果a是一个二维数组，那么a[0]表示的是二维数组中0行0列的地址，即a[0]= &a[0][0],
    同理 a[1]=&a[1][0]，代表的是1行0列的地址；同理 a[i]=&a[i][0]表示i行 0列元素的地址
  3)上面 小2)都是从行的维度上去考虑问题，如果我们想从列的角度来考虑问题，把 “某行某列”的
    元素的地址表示出来，我们要怎么表示呢？比如我要获取 0行 1列，0行 2列 ，等一直到 0行i列
    那么a[0]+1 就表示0行1列的元素的地址 即：a[0]+1=&a[0][1],
    同理a[0]+2=&a[0][2] 即：a[0]+2表示0行2列的地址
    依次类推 a[0]+i=&a[0][i] 即：a[0]+i表示0行i列的地址
    总之a[i]是一个一维指针，存放的是每行中每列的地址
  4）注意；a[0]= *（a+0）= &a[0][0],等价,指的是0行0列的地址，
    a[1]=*(a+1)=&a[1][0]，指的是 1行0列的地址
    *（a+0）+1 =&a[0][1] =a[0]+1;代表0行1列的地址
    a[1]+2=*(a+1)+2 = &a[1][2] 代表1行2列元素的地址

  5) 在以上的基础上，则 *(a[0]+1)表示的是a[0][1]数组存放的值 比如a[0][1]=2;
   那么 *（a[0]+1)=*(*(a+0)+1)=2,同理
   *（*(a+i)+j）=*（a[i]+j）表示的是 i 行 j列元素的值
 */
/* 电脑 Ip4： 192.168.0.104
1.wifi:192.168.0.106
2.4G: 10.140.159.168
3.没网：:null
4.4G切wifi: 10.129.61.252--切换后--》192.168.0.103--》切回4G-->10.128.111.140
(10.128.111.140 )4G登录到一半切成wifi:对应的ip是：192.168.0.103--》
再切回4G-->10.139.86.7 --->kill processor再次4G进入对应的ip：10.139.86.7
5.wifi 切换 4G：192.168.0.106--切换后--》10.129.61.252
6.换一个热点对应的ip是：172.20.10.4
7.切换另外一个热点： 172.20.10.4--切一个热点-> */