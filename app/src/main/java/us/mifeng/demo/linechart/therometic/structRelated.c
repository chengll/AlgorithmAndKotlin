#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* C语言中的结构体：
 一、声明结构体类型的一般格式：
   1. struct 机构体名称{
        {成员列表}；
    }
   注意: 结构体中的成员类型也可以是另外一个结构体类型
   eg:
   struct Date{//声明struct Date结构体
    int month;
    int day;
    };
    struct Student{  //声明struct Student结构体
        int num;
        char name[20];
        char sex;
        struct Date birthday; //成员birthday是struct Date类型
        char address[30];
    };
    .在声明完结构体以后就要定义该结构体类型的变量,注意在定义变量时
    一定要带上struct
    struct Student s1,s2;

    同时我们也可以将声明和定义结构体类型变量的操作一步完成
   2.在声明结构体的同时初始化结构体变量
    struct 结构体名{
        {成员列表}
    }变量名列表；
    eg:
    struct Student{
        int num;
        char name[20];
        char sex;
        struct Date birthday;
    }s1,s2;  //这就创建了两个struct Student类型的变量 s1和s2

  3.不指定类型名而直接声明结构体类型变量
   struct{
       成员列表；
   }变量名列表；

  注意在使用时不要把结构体类型和结构体变量搞混淆，因为在编译的过程中，
  只对结构体变量分配内存，不会对结构体类型分配存储空间de。

  注意：1.同类的结构体是可以进行赋值的
 */
/*
  eg1.输入两个学生的学号，姓名和成绩，输出成绩较高的学生的学号，姓名和成绩
   struct Student{
        int num;
        char name[20];
        float score;
    }s1,s2;
    printf("请输入第一个学生的信息");
    scanf("%d%s%f",&s1.num,s1.name,&s1.score);
    printf("请输入第二个学生的信息");
    scanf("%d%s%f",&s2.num,s2.name,&s2.score);
    printf("print the higher score");
    if (s1.score>s2.score)
    {
       printf("%d,%s,%f",s1.num,s1.name,s1.score);
    }else if (s1.score<s2.score)
    {
        printf("%d,%s,%f",s2.num,s2.name,s2.score);
    }

    运行结果：
        请输入第一个学生的信息1 yy 32
        请输入第二个学生的信息2 hh 67
        print the higher score2,hh,67.000000

二、结构体数组：
    1.一个结构体中存放一组关联的数据（学号，姓名和成绩），如果有
    10个学生的数据需要参与运算，显然就该使用结构体数组，
    结构体数组与之前数组的不同处在于，每个数组元素都是一个结构体
    类型的数据，它们都分别包括成员项（学号 姓名 和成绩）

    eg:1、有3个候选人，每个选民只能投票选一人，要求编一个选票的程序，
          先后输入选票人的姓名，最后输出各人的得票结果：
     分析： 显然需要定义一个数组，每个成员都有姓名和票数两个成员

    2.定义结构体的形式：
    struct 结构体名 {成员列表} 数组名[数组长度]
    比如 1）先声明一个结构体类型(如struct Person),然后用此类型定义结构体
    数组，结构体类型  数组名[数组长度]
    eg:struct Person leader[3]; //leader就是结构体数组
      2）对结构体数组初始化的形式在定义数组的后面加上。={初始值列表}
    比如：struct Person leader[3]={"Li",0,"zhang",0,"ss",0};

    eg2.有n个学生信息（包括姓名，学号，成绩 ），要求按照成绩的高低顺序输出学生的信息
        分析：说白了就是按照学生成绩的从大到小排列。
        struct Student{
        int num;
        char name[20];
        float score;
        int k=0,n=5;
        struct Student temp;
            struct Student stu[5]={10,"sdsd",78, 11,
            "sdsd",98.5,12,"sdsd",99,13,"sdsd",112,
            14,"sdsd",100 };
        for (int i = 0; i < n-1; i++)
        {k=i;
            for (int j = i+1; j < n; j++)
            if (stu[j].score>stu[k].score)
                k=j;
            temp=stu[k]; stu[k]=stu[i];stu[i]=temp;
        }
        //打印排序后的结构
            for ( int i = 0; i < n; i++)
            {
                printf("%d,%s,%f",stu[i].num,stu[i].name,stu[i].score);
            }
        };
        struct Student stu[5]={ 10,"zhangsan",78,
                            11,"lisi",98.5,
                            12,"wangwu",99,
                            13,"aidou",112,
                            14,"hney",100
                            };


    运行结果：13,sdsd,112.000000
             14,sdsd,100.000000
             12,sdsd,99.000000
             11,sdsd,98.500000
             10,sdsd,78.000000


 三、结构体指针
    所谓结构体指针就是指向结构体的指针，一个结构体变量的起始地址就是这个结构体变量的指针
    一个结构体变量的起始地址就是这个结构体变量的指针；如果把一个结构体变量的首地址存放在
    一个指针变量中，那么这个指针变量就指向该结构体的变量

    1.指向结构体指针如何使用结构体中的成员
        struct Student *p1;
        struct Student stu2;;
        p1=&stu2;
        stu2.num=121;
        strcmp(stu2.name,"哈哈哈");
        //stu2.name="zhangsan"; (这种不行啊  好惨)
        stu2.score=100;
        printf("%d,%s,%f",(*p1).num,(*p1).name,(*p1).score);

    2.指向结构体数组的指针
        eg:有3个学生的信息，放在结构体中，要求输出全部学生的信息
        struct Student stu[5]={ 10,"zhangsan",78,
                            11,"lisi",98.5,
                            12,"wangwu",99,
                            13,"aidou",112,
                            14,"hney",100
                            };
      //3.指向结构体数组的指针
        struct Student *p2;
        p2=stu;
        for (p2=stu; p2<stu+5; p2++)
        {
            printf("%d,%s,%f\n",p2->num,p2->name,p2->score);
        }
    运行结果：
        10,zhangsan,78.000000
        11,lisi,98.500000
        12,wangwu,99.000000
        13,aidou,112.000000
        14,hney,100.000000

 */


struct Student{
    int num;
    char name[20];
    float score;
};

int main(int argc, char const *argv[])
{  //2.使用指针指向单个结构体
    struct Student *p1;
    struct Student stu2;;
    p1=&stu2;
    stu2.num=121;
    strcmp(stu2.name,"哈哈哈");
    //stu2.name="zhangsan"; (这种不行啊  好惨)
    stu2.score=100;
  //  printf("%d,%s,%f",(*p1).num,(*p1).name,(*p1).score);

//1.结构体的简单使用
    int k=0,n=5;
struct Student temp;
    struct Student stu[5]={ 10,"zhangsan",78,
                            11,"lisi",98.5,
                            12,"wangwu",99,
                            13,"aidou",112,
                            14,"hney",100
                            };
 //3.指向结构体数组的指针
   struct Student *p2;
   p2=stu;
   for (p2=stu; p2<stu+5; p2++)
   {
       printf("%d,%s,%f\n",p2->num,p2->name,p2->score);
   }

   //插入3的部分
   for (int i = 0; i < n-1; i++)
   {k=i;
    for (int j = i+1; j < n; j++)
    if (stu[j].score>stu[k].score)

        k=j;

    temp=stu[k]; stu[k]=stu[i];stu[i]=temp;
   }
   //打印排序后的结构
    for ( int i = 0; i < n; i++)
    {
        //printf("%d,%s,%f",stu[i].num,stu[i].name,stu[i].score);
    }
    return 0;
}

/*

四、用结构体变量和结构体变量的指针作函数参数
   将一个结构体变量的值传递给另一个函数的方法有3个：
   1）用结构体变量的成员作参数：比如使用stu[0].name或者stu[1].num做参数实参，
      将实参值传递给形参，用法和用普通变量做实参是一样的，属于“值传递",注意形参和
      实参的类型要一致 。
   2）用结构体变量做实参：采取的是值传递的方式，将结构体变量所占的内存单元的内容
      全部按顺序传递给形参，形参也必须是同类型结构体，这句不建议使用，开销太大
   3）用指向结构体变量（或者数组元素）的指针做实验，将结构体变量或者数组元素的地址、
      传给形参。
    eg:有n个结构体变量，内含学号，姓名和3门课程的成绩。要求输出平均成绩最高的学生的
    信息（包括姓名，学号和3门课程的信息），

        指针处理链表
一、.什么是链表？链表是一种常见的重要的数据结构。它是动态进行分配的一种，用数组存储数据
    元素时候需要固定数组的长度。如果存放的数据的大小不一样时，数组会出现越界之类的，但是
    链表没有这样的缺点，它根据需要动态开辟空间。
    注意：
    1）链表中各个元素在内存中的地址可以是不连续的。
        //1.创建链表并输出值
        struct SeniorStu{
            int num;
            float score;
            struct SeniorStu *next;
        };
        1>.定义三个结构体对象作为链表的结点；
        2>.head为链表的头指针；
        3>.p为指向链表的每个链接点的指针

     struct SeniorStu a,b,c,*head,*p3;
     a.num=101;a.score=99;
     b.num=111;b.score=100;
     c.num=120;c.score=99.9;
     head=&a;
     a.next=&b;
     b.next=&c;
     c.next=NULL;
     p3=head;
     do
    {
        printf("num: %d\n score: %f",p3->num,p3->score);
        p3=p3->next;
    } while (p3!=NULL);

二、建立动态链表
    所谓动态建立链表是指在程序的执行过程中 从无到有的建立一个链表的过程；
    即一个一个的开辟新的结点和输入个结点数据的过程，并建立相互之间先后链的关系
 */

struct Student{
    int num;
    char name[20];
    float score[3];
    float aver;
};
//1.创建链表并输出值
struct SeniorStu{
    int num;
    float score;
    struct SeniorStu *next;
};
int main(int argc, char const *argv[])
{ void input(struct Student stu[]);
  struct Student max(struct Student stu[]);
    void printInfo(struct Student stu);

    struct Student stu[5];
    struct Student *p;
    input(p);
    printInfo(max(p));

   /*  定义三个结构体对象作为链表的结点；
        head为链表的头指针；
        p为指向链表的每个链接点的指针
    */
    struct SeniorStu a,b,c,*head,*p3;
     a.num=101;a.score=99;
     b.num=111;b.score=100;
     c.num=120;c.score=99.9;
     head=&a;
     a.next=&b;
     b.next=&c;
     c.next=NULL;
     p3=head;
     do
    {
        printf("num: %d\n score: %f",p3->num,p3->score);
        p3=p3->next;
    } while (p3!=NULL);

    return 0;
}
//1.输入n个学生的信息
void input(struct Student stu[]){
    for (int i = 0; i < 5; i++)
    {
       //("请输入%d个学生信息\n",i);
       scanf("%d,%s,%f,%f,%f",&stu[i].num,stu[i].name,&stu[0].score,&stu[1].score,&stu[2].score);
       stu[i].aver=(stu[i].score[0] + stu[i].score[1]+ stu[i].score[2])/3.0;
    }

}
//2.找到平均成绩比较高的结构体
struct Student max(struct Student stu[]){
    int i,m=0;
    for ( i = 0; i < 5; i++)
    {
        if (stu[i].aver>stu[m].aver){ m=i;}

    }
    return stu[m];
}

//3.打印出平均分比较高的学生信息数据
void printInfo(struct Student stu){
   // printf("输出成绩高的学生的信息\n");
    //("学号: %d\n, 姓名：%s\n 三门课的成绩:%5.1f,%5.1f,%5.1f\n 平均成绩:%5.1f",
    stu.num,stu.name,stu.score[0],stu.score[1],stu.score[2],stu.aver);

}


