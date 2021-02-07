//
// Created by honeyLL on 2/6/21.
//

#include<stdio.h>
#include<stdlin.h>
/*
 栈是一种数据插入和删除受限的线性表；
 栈的操作顺序是后进先出；
 栈是在表尾进行插入，删除的操作的线性表，表尾称为top,表头称为栈底 即base
 栈的逻辑结构也是一对一的，
 栈的存储结构也有顺序栈和链栈两种哦方式
 栈的运算规则是 后进先出的规则（LIFO）
 一组数据a1,a2...an 固定栈顶为an，栈底为a1,进出栈都是在栈顶进行的

 顺序栈：利用一组地址连续的存储单元依次存放从栈底到栈顶的元素，栈顶指针为top(an端) ，栈底为a1端。
 空栈的条件为 top==base=0；
 栈满的条件 ：top-base =stackSize; 注意这里top 和base 必须是同一个栈的指针
 顺序栈容易溢出：
 上溢：是指栈已经满了，又要压入栈元素（是一种错误）
 下溢：栈已经空了，还要弹出元素 （不认为是一种错误）
 初始化栈：构造一个空的栈
 顺序栈的C语言描述：
 #define MAX_SIZE 18
 typedef struct {
  SElemType  *base; //栈底指针
  SElemType  *top;  //栈顶指针
  int statckSize;   //栈可用的最大容量
 }SqStack

 队列是一种先进先出得数据结构（FIFo），只能在对尾插入，在对头删除（即：头删除尾插入）

*/

 #define MAX_SIZE 18
 typedef struct {
  SElemType  *base; //栈底指针
  SElemType  *top;  //栈顶指针
  int statckSize;   //栈可用的最大容量
 }SqStack

 //初始化栈：
 Status Init(SqStack &s){
  S. base=(SElemType *) malloc(MAX_SIZE * sizeOf(SElemType));
  if(!S.base) OVERRFLOW; //分配失败
  S.top=S.base; //栈顶指针等于栈底指针
  S.stackSize=MAX_SIZE;
 }