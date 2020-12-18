#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
  顺序栈的问题
  顺序栈也是一种结构体类型，用C语言描述为：
  第一种描述：
   #define MAX 100
   typedef struct stack{
     SElemType data[MAX]; //data是一维数组
     int top;             // 表示栈顶的位置
     int stackSize;       //栈的容量
   }SqStack;
  
  第二种描述：
  typedef struct stack{
    SElemType *data; //data是一个指针变量，存放一片连续空间的首地址
    int top;         //栈顶指针
    int stackSize;   //栈的容量
  }Sqstack;
 */
typedef struct stack{
    int *data; //data是一个指针变量，存放一片连续空间的首地址 SElemType *data;
    int top;         //栈顶指针
    int stackSize;   //栈的容量
  }Sqstack;

//1.初始化顺序栈
int initSqstack(Sqstack *Ls,int max){
  Ls->data=(int *)malloc(max*sizeof(int));
  if (Ls->data==NULL)
  {
    printf("申请空间失败"); exit(0);
  }
  Ls->top=-1;
  Ls->stackSize=max;
  return 1;
} 
//2.栈是否为空只要判断s.top 是否等于 -1 即可。
int sqStackEmpty(Sqstack s){
  if (s.top==-1){return 1;}
   return 0;
} 
//3、获取栈顶元素
int getStackTop(Sqstack s,char *e){
  if (s.top==-1){return -1;}
  *e=s.data[s.top];
  return 1;
}
//4.求栈的长度
int getStackLength(Sqstack s){
  return s.top+1;
}

//5.进栈操作
int push(Sqstack *s,char e){
  if (s->top+1==s->stackSize){return 0;//栈满，无法入栈
  }
  s->top++;
  s->data[s->top]=e;
  return 1;
}

//6.出栈操作
int pop(Sqstack *s,char *e){
  if (s->top==-1){return 0;}
  *e=s->data[s->top];
  s->top--;
  return 1;
}

//7.遍历栈
int traverStack(Sqstack s){
  if (s.top==-1){return 0;}
  for (int i = s.top; i > 0; i--)
  {
    printf("%d\n",s.data[i]);
  }
  return 1;
}
//8、创建栈
void createSqstack(Sqstack *s,int max){
  //初始化顺序栈
  initSqstack(s,max);
  //2.将数据存入到栈中去
  char ch;char x;
 do
 {
  printf("请输入第一个栈的元素");
  scanf("%c",&x);
  push(s,x);
  printf("是否继续插入");
  ch=getchar();
 } while (ch=='y');
}
