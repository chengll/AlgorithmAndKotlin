/* **********************使用顺序线性表实现学生信息管理系统********************* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//1.自定义类型
typedef struct{
char xh[15];//学号
char xm[20];//姓名
char bj[15];//班级
float score1;//英语成绩
float score2;//数学成绩
float score3;//总成绩
}STD;

//2.定义线性表的数据模型
typedef struct{
    STD *data;
    int listSize;//总容量
    int length; //当前线性表中的数据
}SqList;

//3.各功能函数的申明
int createSqList(SqList *L,int MAXSIZE);//创建学生信息线性表
int insertSqList(SqList *L,int i,STD x);//向线性表插入数据
int deleteSqList(SqList *L,int i,STD *x);//这里是想干嘛
int updateSqList(SqList L,int i,STD x); //更新学生信息
int locationSqList(SqList L,char *xh);//按按学号查找
void findEnglishSqList(SqList L,float score1);//查找英语成绩为score1的学生
void findMathSqList(SqList L,float score1);//查找英语成绩为score1的学生
void findTotalSqList(SqList L,float score1);//查找英语成绩为score1的学生
void displaySqList(SqList L);//展示学生信息
int menu();

//4.主函数中调用
int main(int argc, char const *argv[])
{
    int n,maxSize;
    float fs;
    char xh;
    SqList L;STD s;
    while (1)
    {n=menu();
    switch (n)
    {
    case 1:printf("请输入需要创建新学生的人数\n");
        scanf("%d",&maxSize);
        createSqList(&L,maxSize);
        printf("请按任意键继续");
        getchar();
        break;
    case 2:printf("请输入插入学生的学号，姓名，班级，英语成绩，数学成绩，总成绩，用空格分开:\n");
        scanf("%s%s%s%f%f%f",s.xh,s.xm,s.bj,&s.score1,&s.score2,&s.score3);
        insertSqList(&L,&L.length+1,s);
        printf("请按任意键继续");
        getchar();
        break;
        case 3:printf("请输入需要删除的学生的学号:\n");
        scanf("%s",s.xh);
        n=locationSqList(L,s.xh);
        deleteSqList(&L,n,&s);
        printf("删除学生的数据为：%s%s%s%7.2f%7.2f%7.2f \n",s.xh,s.xm,s.bj,&s.score1,&s.score2,&s.score3);
        printf("请按任意键继续");
        getchar();
        case 4:printf("请输修改学生的学号，姓名，班级，英语成绩，数学成绩，总成绩，用空格分开:\n");
         scanf("%s%s%s%f%f%f",s.xh,s.xm,s.bj,&s.score1,&s.score2,&s.score3);
         n=locationSqList(L,s.xh);
         updateSqList(L,n,s);
         printf("请按任意键继续");
         getchar();
        break;
        case 5:printf("请输入需要查询学生的学号：\n");
        scanf("%s",xh);
        n=locationSqList(L,xh);
        if (n){
         printf("删除学生的数据为：%s%s%s%7.2f%7.2f%7.2f \n",L.data[n-1].xh,L.data[n-1].xm,L.data[n-1].bj,L.data[n-1].score1,L.data[n-1].score2,L.data[n-1].score3);
        }
         printf("请按任意键继续");
         getchar();
        break;
        case 6:printf("请输入需要查询的英语成绩的下限：\n");
        scanf("%f",&s.score1);
        printf("满分英语成绩>=7.2%f的新生如下：\n",fs);
        findEnglishSqList(L,fs);
         printf("请按任意键继续\n");
         getchar();
        break;
         case 7:printf("请输入需要查询的数学成绩的下限：\n");
        scanf("%f",&s.score1);
        printf("满分数学成绩>=7.2%f的新生如下：\n",fs);
        findMathSqList(L,fs);
         printf("请按任意键继续\n");
         getchar();
        break;
         case 8:printf("请输入需要查询的总成绩的下限：\n");
        scanf("%f",&s.score1);
        printf("满分总成绩>=7.2%f的新生如下：\n",fs);
        findTotalSqList(L,fs);
         printf("请按任意键继续\n");
         getchar();
        break;
        case 9:printf("新生成績如下:\n");
        displaySqList(L);
         printf("请按任意键继续\n");
         getchar();
        break;
        case 0:
        exit(0);
        break;
    default:
        break;
    }
    }

    return 0;
}



