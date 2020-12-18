#include <stdio.h>
//普通变量交换位置 错误
void swap(int a, int b)
{
    int temp; //临时变量
    temp = a;
    a = b;
    b = temp;
}
//使用指针来交换两个变量的值
void changeTwo(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    int a = 66, b = 99;
    //1.普通变量 并不能交换两个变量的值
    swap(a, b);
    //printf("a = %d, b = %d\n", a, b);
    //2.采用指针变量才可以交换
    changeTwo(&a, &b);
    //printf("a = %d, b = %d\n", a, b);

    /*
运行结果：
a = 66, b = 99
从结果可以看出，a、b 的值并没有发生改变，交换失败。这是因为 swap()
函数内部的 a、b 和 main() 函数内部的 a、b 是不同的变量，占用不同
的内存，它们除了名字一样，没有其他任何关系，swap() 交换的是它内部
a、b 的值，不会影响它外部（main() 内部） a、b 的值。
因此要使用指针变量后就可以解决这个问题
 */

//结构体定义和赋值
struct
{
    char *name;
    int num;
    int age;
    char group;
    float score;
}stu1 ={ "Tom", 12, 18, 'A', 136.5 },*pstu=&stu1;
//1.结构体指针的使用
printf("%s的学号是%d ,年龄是%d,在 %c组，今年的成绩是%f\n",(*pstu).name,(*pstu).num,
(*pstu).age,(*pstu).group,(*pstu).score);
//2.结构体指针使用
printf("%s的学号是%d ,年龄是%d,在 %c组，今年的成绩是%f\n",pstu->name,pstu->num,
pstu->age,pstu->group,pstu->score);
//3.结构体数组
struct stu{
    char *name;  //姓名
    int num;  //学号
    int age;  //年龄
    char group;  //所在小组
    float score;  //成绩
}stus[]= {
    {"Zhou ping", 5, 18, 'C', 145.0},
    {"Zhang ping", 4, 19, 'A', 130.5},
    {"Liu fang", 1, 18, 'A', 148.5},
    {"Cheng ling", 2, 17, 'F', 139.0},
    {"Wang ming", 3, 17, 'B', 144.5}
},*p;
printf("姓名\t 学号\t 年龄\t 分组\t 成绩\t\n");
int len=sizeof(stus)/sizeof(struct stu);
for (p = stus; p < stus+len; p++)
{
    printf("%s\t%d\t %d\t%c\t%f\t\n",p->name,p->num,p->age,p->group,p->score);
}

//结构体作为函数的参数形式
printf("*******************************************");
/* (1) struct{ int x; int y; }test1;  相当于定义了结构体 test1，
     test1.x 和 test1.y 可以在语句里用了。
(2) struct test {int x; int y; }test1; 定义了结构体 test1，
     test1.x 和 test1.y 可以在语句里用了。
与 1 比，省写 了 test
(3)
typedef struct test
{int x; int y;
}text1,text2;
typedef是取别名的意思
相当于把struct test 这种结构体取别名 叫 test1 或叫 test2 */


 return 0;
}
/* int average(struct stu *p3,int len){
 int i,num_140=0;
 float average=0.0,sum=0.0;
 for (int i = 0; i < len; i++)
 {
     sum=sum+*(p3+i)->score;
 }

} */