#include <stdio.h>
#include<stdlib.h>
/**
  顺序表（元素）的特点：
   1、地址连续
   2、依次存放
   3、随机存取
   4、类型相同的元素
   5、顺序存储方式采用的是数组，用一维数组表示顺序表
   6、线性表的长度可变（可以删除，插入操作）
   7、数组长度不可动态定义--> 用一变量表示顺序表的长度属性

   二、顺序表的结构描述
     #define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
     typedef struct{
       ElemType elem[LIST_INIT_SIZE];
       int length ;//当前表的长度
     }SqList;

    三、多项式的顺序存储结构类型定义
   例1、表达式为： Pn(x)=P1x^e^1 +P2x^e^2+...+Pmx^e^m，
    抽取出来的线性表 P=((p1,e1),(p2,e2)...(pm,em))

    //顺序存储的C 语言结构描述为：
    #define MAXSIZE 1000  多项式可能达到的最大长度
    typedef struct{   //多项式非零项的定义
     float p;         //系数
     int e;           //指数
    }Polynomial;

    typedef struct{
     Polynomial *elem;  //存储基地址
     int length;        //多项式中当前项的个数
    }SqList;            //多项式的顺序存储结构类型为SqList类型

 例2、使用线性表的顺序结构存放一组书籍

    typedef struct {
     char no[10] ；存放书籍的编号
     char name[20];存放书名
     float price[]; 存放价格
    }Book；

     #define MAXSIZE 100
     typedef struct{
       Book *elem; //存放书籍的首地址
       int length; //线性表当前存放的大小
     }SqList;

     线性表的链式存储结构：线性表中的元素（结点）在存储器中的位置是任意的，即逻辑上相邻的数据元素在物理位置上不一定相邻。
     每个结点是由 指针 和 数据域 构成。
     单链表：只有一个指针域；
     双链表：是有两个指针域
     循环链表：元素的首元素和尾元素连接在一起构成环，循环链表有循环单链表和循环双链表构成。

   顺序表的链式存储：链式存储是指用一组链表将一组数串起来，形成一组链，逻辑上相邻的两个元素不定物理位置也相邻
   指针 ：int a=5 的意义就是在计算机内部开辟一片整型的存储空间来 命名为a,将5放入到这片存储空间中去，这时候
   便于查找5这个值，可以定义一个指针指向这片地址，由于内存中存放的数据的类型为整型，因此定义指针时也要定义为整型，
   即 int * p ,它也相当于在内存中开辟了一片整型的空间，但是它里面存的值不是a 的值 ，而是a 在计算机中存储的地址
   即 p = &a ;表示取 a 的地址。

   单链表存储结构：由数据域 和指针域 两部分构成，因此是一个结构体类型
   typedef struct Lnode{  //声明结点的类型和指向该结点的指针
    ElemType data;      //结点的数据域
    struct Lnode *next; //结点的指针域
   }Lnode, *LinkList;  //LinkList 为指向结构体Lnode 类型的指针变量

   注意：这里指针是指向下个元素的地址，它的类型是和本结点的类型是一致的，因为本结点的类型为struct 类型，因此
        定义指针的类型也为struct Lnode,由于是指针类型，所以为struct Lnode *的类型。


   如果要声明一个结点 可以使用Lnode *l的形式，使用数据为 l.data的形式， l.next
   同时也可以声明一个结点为 LinkList l,则调用属性时直接是l->data,和 l->next的形式

   通常使用 LinkList L 来定义链表
   通常使用 Lnode *p  来定义结点指针 p

   eg:使用单链表存储学生信息，分别有学号，姓名 和成绩单属性
   typedef struct Student{
     char num[8] ;// 学号 数据域
     char name[20]; //姓名 数据域
     flaot score;  //成绩 数据域
     struct Student *next; //指针域指向下个学生信息地址
   }Lnode ,*LinkList;

   接着我们就可以使用LinkList L 来定义链表， 然后将学生信息一一串起来

   上面的这种定义方式破坏了链表存储结构为 数据域 +指针域的规则，因此我们可以将数据域抽取出来
   typedef Student{
    char num[8],
    char name[20];
    flolat score;
   }ElemType;

   有了数据域就可以定义链表的结构体
   typedef struct Lnode{
    ElemType data;  //数据域
    struct Lnode * next; //指针域
   }Lnode, *LinkList;



*/

