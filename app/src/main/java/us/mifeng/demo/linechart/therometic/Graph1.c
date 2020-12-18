#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
一、图的存储：
包括顶点信息，边(弧)的信息 ，顶点数 和 边（弧）数目
顶点的存储：顶点集动态变化的几率十分小，所以采用数组来存储
顶点关系存储：
   1.邻接矩阵表示法： 矩阵中第i行 第j列的元素反应图中第 i 个顶点到第 j 个
   顶点之间是否有弧，若存在，用1表示，若不存在，用0表示，如果弧或者边上有
   权（附加的信息），用权值表示存在，反之人为给定一个数，表示不存在
   总之就是一个n*n的方阵的形式。
   eg: 如果有5个结点就是，5*5（5行5列的二维数组）,主要用来存储无向图，
   如果两个点点直接有边就是 1，如果没有就是0，数据结构总之是二维数组

   2.邻接表的表示法(主要存储无向图)：将每一顶点邻接点位置串接 成一个单向链表，
   称为邻接表，对于有向图/网图说，该邻接表反映的是顶点的出边表。
   总之邻接表是有向图，因此是数据结构是链表
   如果两个顶点之间有方向的可以到达，则是用权值表示，如果不能到达则用无穷表示；
   如果是自己到自己 用0表示。

   3.邻接矩阵的特点：
     1》存储的特点是顺序存储结构 
     2》二维数组arcs中的元素值描述了边的邻接关系以及边上是否有权的
     3》无向图和无向网是邻接矩阵是对称矩阵，有向图和有向网的邻接矩阵不一定是对称矩阵
     4》对于边(弧)个数比较少的稀疏图，其邻接矩阵也是稀疏，有较多的0，用二维数组存储
        邻接矩阵的空间利用率比较低

三、邻接矩阵上合适的操作：
    1）计算顶点的度：
        1》无向图中第i个顶点的度为二维数组 arcs 的第i行第i列的非零元素个数
            或非（∞）元素的个数；
        2》有向图中第i个顶点的出度为arcs二维数组的第i行 非零元素的个数
            或者 非（∞）元素的个数
        3》有向图中第i个顶点的入度为arcs 二维数组的第i列非零元素个数或者
            非（∞）元素的个数。
      计算无向图顶点的度或有向图顶点的出度的程序段为：
        int  d[];
        for(int  i=0;i<G.vexNum;i++){
            d[i]=0;
            for(int j=0;j<G.vexNum;j++){
                if(G.arcs[i][j]!=0){
                    d[i]++;
                }
            }
        }
四、求一个顶点的所有邻接点：二维数组arcs的第i行的所有非零元素（不包括 ∞）均
    表示与第i个顶点有邻接关系。
     for(int i=0;i<G.vexNum;i++){
      for(int i=0;i<G.vexNum;i++){
         if(G.arcs[i][j]!=0) // 表示顶点 i 和顶点 j有邻接关系
       }
     }
五、 插入或者删除一条边（弧）：根据要插入或者删除边（弧）的位置，修改二维数组某个
     元素的值

六、图的邻接表表示：
    对图中每个顶点建立一个与该顶点有邻接关系的顶点单链表，用一个一维结构体数组存储
    顶点值和各顶点单链表的头指针，用整型变量存储图中的定点数和弧度数。
 */

/* 
用一个一维数组存储顶点信息，用邻接矩阵存储 顶点之间的邻接关系，用两个整形变量
存储图中的顶点数和变数
1.邻接矩阵的C语言数据描述：
 */
#define VUM 20           //图中最大的顶点数目
typedef char VertexType; //顶点的数据类型
typedef struct
{
    VertexType vexs[VUM]; //存储顶点的信息
    int arcs[VUM][VUM];   //存储顶点的关系
    int vexNum, arcNum;   //存储顶点数和弧(边)数目
} MGraph;

//2.网的邻接表的数结构
#define VUM 24
typedef char WeightType; //为边或者弧上权值的数据类型
typedef struct
{
    VertexType vexs[VUM];      //存储顶点信息
    WeightType arcs[VUM][VUM]; //存储顶点关系
    int vexNum, arcNum;        //存储顶点数，弧数目
} NetGraph;

/* //图的邻接矩阵生成算法 */
void create_graph(MGraph *G)
{
    int i, j, k;
    scanf("%d,%d", &G->vexNum, &G->arcNum);
    for (i = 0; i < G->vexNum; i++)
    {
        scanf("%d", &G->vexs[i]);
    }
    for (i = 0; i < G->vexNum; i++)
    {
        for (j = 0; j < G->vexNum; j++)
        {
            G->arcs[i][j] = 0;
        }
        for (k = 0; k < G->arcNum; k++)
        {
            scanf("%d,%d", &i, &j);
            G->arcs[i - 1][j - 1] = 1;
            G->arcs[j - 1][i - 1] = 1;
        }
    }
}

/* 
 1.邻接表存储的是图的出度，而逆邻接表存储的是入度
 2.如果有向图或者有向网是带有权值的，则邻接表存储的是出度和权值，通过单链表的形式存储起来
   同理，逆邻接表的有向网状图也是一样的，存储的是图的入度和带权值
 3.图的邻接表的存储类型：
    1》图的邻接表的边结点类型：
     #define    MaxSize 10
     typedef struct ArcNode{
         int adjvex;  //弧所指向的顶点的位置
         struct ArcNode *nextArc;  指向下条弧的指针
         [weightType info] 权的相关信息，可有可无，根据题意来定
     }ArcNode; 边结点类型

     2》邻接表的表头结点的类型描述
     typedef struct VertexNode{
         TelemType vextet;
         ArcNode *firstArc;
     }VertexNode;

     3》图的邻接表类型
      typedef struct AlGraph{
          VertexNode adjList[MaxSize];
          int vexNum,arcNum;
      }ALGraph;
 */
#define MaxSize 10
//1).邻接表的边结点类型
typedef struct ArcNode{
    int adjvex;    //弧所指向的顶点的位置 比如  0,1,2,3之类
    struct ArcNode *nextArc; //弧所指向的下个顶点的位置
    WeightType info;         //权值相关，可有可无，根据题意来定
}ArcNode;
//2).邻接表的头结点类型
 typedef struct VertexNode{
         int vextet; //TelemType 顶点的数据类型,用具体的int代替
         ArcNode *firstArc;
     }VertexNode;
//3).图的邻接表类型 
typedef struct AlGraph{
   VertexNode adjList[MaxSize]; 
   int vexNum,arcNum;
}ALGraph;



/* 有向图的邻接表的生成算法 步骤：
1.输入图的顶点数和边数
2.输入顶点信息，初始化该顶点的边数
3.依次输入弧的信息并插入到链表中去，
  {输入弧所依附的弧尾和弧头相关的序号为i和j；
   生成的邻接点的序号为j的边表结点为s;
   将结点s插入到第i个边表的头部
  }
  以下是创建有向图的邻接表的算法
*/
void build_adjList(ALGraph *G){
    int i ,j,k;
    ArcNode *p;
    scanf("%d %d",&G->vexNum,&G->arcNum); //输入顶点数和边数
    for ( i = 0; i < G->vexNum; i++){  //创建表结点
        scanf("%d",&G->adjList[i].vextet);
        G->adjList[i].firstArc=NULL;
    }

    for ( k = 0; k < G->arcNum; k++)  //创建边
    {
        scanf("%d%d",&i,&j); //读入一对顶点序号，序号从1开始
        p=(ArcNode*)malloc(sizeof(ArcNode)); //生成结点
        p->adjvex=j-1;
        p->nextArc=G->adjList[i-1].firstArc;    
        G->adjList[i-1].firstArc=p;
    }
}
/* 
 一、 有向图的十字链表：
  1.有向图的十字链表便于求顶点的出度
  2.有向图的逆十字链表便于求顶点的入度；
  3.十字链表是将有向图的邻接表和逆邻接表结合在一起的一种链表，在实际应用中，求顶点的度非常方便
 二、十字链表：
    1.链表结点结构：
    边起点（tailvex）--边终点(headvex)--下一入边的指针(hlink)--下一出边指针(tlink)--弧的信息(info) 
    2.表头结点结构：
    顶点信息(data)--入边头指针(firstin)--出边头指针(firstout)

    理解： 1.Data(顶点值)---firstIn(指向这个顶点的第一个指针)--firstout(第一个从该顶点出去的边指针)
 2.start(当前边结点的起始点数据域 比如 A0--A1,start=0)---end(当前边终点的数据域，就存 1)
 --nextIn(下一个入边，承接的是firstIn的后继)--nextout(下一个出边，承接的是firstout的后继)

三、十字链表的C语言结构描述
   #define MAX_VER_NUM 100
  1.链表结点C结构：
    typedef struct ArcBox{
        int start,end;             //该弧的尾和头顶点的位置
        struct ArcBox* nextIn,*nextOut;  //分别指向下一个弧头相同和弧尾相同的弧的指针域
        InfoType *info;               //该弧相关信息的指针
    }ArcBox；

  2.表头结点类型：
    typedef struct VexNode{
        VerTextType data;           //顶点信息
        ArcBox *firstiin,*firstout; //分别指向该顶点的第一条入弧和第一条出弧
    }VexNode;

  3.十字链表类型：
   typedef struct {
       VexNode xList[MAX_VER_NUM];  //表头向量
       int vetexNum,arcNum;         //有向图的顶点数和弧数目
   }OLGraph;
 */