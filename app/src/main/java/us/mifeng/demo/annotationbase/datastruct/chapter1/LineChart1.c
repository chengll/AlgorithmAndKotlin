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

*/

