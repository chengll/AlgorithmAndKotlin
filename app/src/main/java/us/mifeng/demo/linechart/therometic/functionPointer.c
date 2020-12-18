#include <stdio.h>
#include <stdlib.h>
/* 函数指针：
 一、函数指针
    如果在程序中定义一个函数，在编译时， 编译系统为函数代码分配一段存储空间，
    这段存储空间的起始地址（又称入口地址）称为这个函数的指针
    可以定义一个指向函数的指针，用来存放某一函数的起始地址，
    也就是该指针指向了该函数
    eg:int(*p)(int ,int) 
    定义p是 指向函数的一个指针，它可以指向函数的类型
    为整型且两个参数为整形的函数，
    p的类型用int (*)(int,int)表示

 二.用函数指针来调用函数
    想调用一个函数，既可以是使用函数名，也可以使用函数指针来调用，
    例如：比较两个数字的大小，并返回较大的一个数字 例如main函数中的测试

三、怎样定义和使用指向函数的指针变量
   1、定义指向函数的指针变量的一般格式为：
     类型名 （* 指针变量名）（参数列表）：
     eg:int （*p）(int,int);这里的类型名指的是函数的返回值的类型；
     即：如果返回值类型是 int,则要定义int(*指针名)(参数列表) 
     ,如果返回值类型是float，就是float(* 指针名)(参数列表)
     注意：
     定义指向函数的指针变量，并不意味着这个指针变量可以指向任何函数，
     而是只能指向在定义时指定类型的函数，例如  int (*p)(int,int)表
     示指针p只能指向函数返回值为整形且参数列表是两个整形参数的函数，
     因此在后期执行中，把哪一个函数（返回值是int,且参数列表是两个整形参数）
     的地址给了指针变量，该指针变量就指向了那个函数的入口地址。
 
     比如：1.定义了函数指针变量 p int (*p)(int,int) 
     同时有两个函数，分别是int sum(int a,int b) 和 int max(int a,int b)
     这两个函数满足函数指针p的要求，因此在调用时只需要将函数名赋值给函数指针
     p=max; 表示p指针指向了函数max的入口地址
     p=sum; 表示p指针指向了函数sum的入口地址

     总之，一个函数指针可以先后指向同类型的不同函数，比如 p可以指向max，也可以指向sum

     2. 对指向函数的指针不能进行算术运算，比如P++ ,p--和p+n都是无意义的

四、使用指向函数的指针做函数的参数
   指向函数的指针变量的一个重要用途就是把函数的地址作为参数传递到其他函数。
   这样就能够在被调用的函数中使用实参函数。它的原理可以描述为以下的：
   有一个函数，比如函数名为fun,它有两个形参x1和x2,定义x1和x为指向函数的
   指针变量，在调用fun函数时，实参为两个函数名称 f1和f2,给形参传递的是f1 
   和 f2函数的入口地址，这样就可以在fun函数中调用到f1和f2的函数了

   void fun(int (*x1)(int)，int (*x2)(int,int)){
      int a,b,i=3,j=5;
      a=(*x1)(i);   //调用f1函数，i为实参
      b=(*x2)(i,j); //调用f2函数，i,j是实参
   }

五：返回指针值的函数
   一个函数可以返回整型，实型，字符型等，也可以返回指针型的数据，即地址。
   例如： int * a(int x,int y);a是函数名，调用它以后得到一个int *型的指针，
    也是整型数据的地址。

    定义返回指针值的函数的形式：
    类型名 *函数名(参数列表)

    eg:1.有a个学生，每个学生有b门课程的成绩，要求在用户输入学号时，输出该学生的全部成绩。
        用指针函数来实现：
    分析：定义一个二维数组score用来存放学生的成绩。（假设学生数a为3 ，b为所修的课程4），
       定义一个查询学生成绩的函数search,它是返回指针的函数，形参是指向一维数组的指针变量
       和整型变量n,从主函数将数组名为score和要找的学生的学号k传递给形参，函数的返回值是
       &score[k][0](即存放的是学号为k的学生  序号为0的课程的数组元素的地址，然后在主函数
       中输出该生的全部成绩)

      //定义通过学号查找学生成绩的方法
      float *search(float (*p)[4],int k){
      float *pointer;
      pointer=*(p+k);
      return (pointer);
   }
   //此处模拟main方法的调用，以 3个学生 每人4门课程为例
   float score[][4]={{99,98,97,76},{99,98,97,76},{99,98,97,76}};
      float *scoreP;
      int i,k;
      scoreP=search(score,k);
      for ( i = 0; i < 4; i++)
      {
      printf("%5.2f",*(scoreP +i));
      }

eg:2.在例1的学生中，找出其中有不及格的课程的学生及其学生学号，用指针函数来实现：
 */
float  *findNotQuality(float (*p)[4]){
   float *pt=NULL;
   for (int i = 0; i < 4; i++){
     if (*(*p+i)<60){
        pt=*p;
     }
   }
   return (pt);
}
float *search(float (*p)[4],int k){
   float *pointer;
   pointer=*(p+k);
   return pointer;
}

int main(int argc, char const *argv[])
{
   int max(int a,int b);
   int sum(int a,int b);
   int min(int a,int b);
   void fun(int a,int b,int (*p)(int,int));
   int (*p)(int,int);
   float *search(float (*p)[4],int k);
   float  *findNotQuality(float (*p)[4]);

   // 3个学生 每人4门课程
   float score[][4]={{99,98,97,76},{99,98,97,76},{99,98,97,76}};
   float *scoreP;
   int i,k;
   scoreP=search(score,k);
   for ( i = 0; i < 4; i++)
   {
   //  printf("%5.2f",*(scoreP +i));
   }

   //查找有成绩不及格的学生的成绩，然后输出
   float *pUnqulify;
   for (int i = 0; i < 3; i++)
   {
     pUnqulify=findNotQuality(score+i);
     //调用查找成绩不合格的人，如果没有不合格的返回NULL，
     //如果有不合格的，则把指向二维数组的首地址score[i][0]返回来
     //因此判断有没有不合格的只需要判断pUnqulify与&score[i][0]的是否相等
     if (pUnqulify=*(score+i))
     { for (int k = 0; k < 4; k++)
     {
       printf("%f",*(pUnqulify+k));
     }
     } 
   }
   
   
    int a=3, b=4,c,d;
    //1.使用方法名调用
    c=max(a,b);
     // printf("c=%d\n",c);
    //2、使用指针函数调用
    p=max;
    a=7,b=3;
    d=(*p)(a,b);
    // printf("d=%d\n",d);
   p=sum;
   d=(*p)(a,b);
    //printf("d=%d",d);
    int opArray[3]={1,2,3};
    for (int i = 0; i < 3; i++)
    {
       switch (i)
       {
       case 0:
          fun(a,b,max);  //调用max
          break;
       case 1:
          fun(a,b,min);  //调用min
       case 2:
         fun(a,b,sum);   //调用sum
          break;
       default:
          break;
       }
    }
    
    return 0;
}

/* 定义函数指针的好处 ：
   eg:有两个整数a和b，由用户输入1，2和3，输入1就将a，b 
   中大的数字返回； 输入2，返回a,b中的小的数，
   输入3，求a,b的和
      
*/
void fun(int a,int b,int (*p)(int,int)){
   int resulut=(*p)(a,b);
  // printf("%d\n",resulut);
    
   
}
int max(int a,int b){
    if (a>b) 
    return a;
    else
     return b;
   
}
int sum(int a,int b){
   return a+b;
}
int min(int a,int b){
    if (a>b) 
    return b;
    else
     return a;
}
