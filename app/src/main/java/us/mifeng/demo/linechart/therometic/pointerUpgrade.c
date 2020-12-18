#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
指针数组和多重指针：
一、指针数组：
 一个数组，若其元素均为指针类型数据，则称为指针数组；也就是说指针数组中的
 每一个元素都存放地址，相当于一个指针变量。

二、如何定义指针数组：
    类型名*  数组名[数组长度]  eg:int *p[4],不能是 int (*p)[4] (×)
    由于[]比*优先级高，因此p先和[4]结合，形成p[4]形式，显然是数组的形式，
    表示p数组有4个元素，然后再和后面的 * 号结合，“ * ”表示数组是指针类型，
    每个数组元素相当于一个指针变量，都可以指向一个整型的变量

三、指针数组的使用情况：
    指针数组比较适合用来指向若干个字符串，使字符串的处理更加灵活，
    eg:1.比如：将若干字符串按字母顺序（由小到大）输出

四、指向指针数据的指针
   在了解了指针数组之后，就需要了解指向指针数据的指针变量，简称指向指针的指针。

   指针数据指针的定义
   以上面例子中的char *name[5]为例，我们知道name是一个指针数组，也就是说name
   数组中的每个元素都是指针变量，其值都是地址，name 是一个数组，它的每一个元素
   都有相应的地址，其中name代表该指针数组的首元素的地址，name+i，表示name[i]
   的地址，name +i 就是指向指针型数据的指针。 还可以定义一个指针变量p,它指向
   指针型数据，p指针应该定义呢？

   char **p; p前面2个 *  号。因为 * 号运算符的结合顺序又右边向左，因此 **p
   相当于 *（*p），显然*p是指针变量的定义形式，如果没有最前面的 *号，即*p
   就指向了一个char类型的变量，对于 char **p 可以看做是 char * 和（*p）,其中
   *p是指针变量，前面char *表示p指向char *型数据，也就是说 p指向了一个字符型
   指针变量；如果引用 *p就得到p所指的char *的值，比如：
    char **p;
    p=name+2;
    printf("%d\n",p); //表示name[2]的地址
    printf("%s\n",*p); //表示name[2]的值  Greate Wall
  
   运行结果：6422000  
            Greate Wall

五、指向指针数据指针的应用:
    eg:1.定义一个指针数组name(name的每个元素都是存放的地址)，使name中
        的每个元素指向5个字符串；
        实现：定义一个指向指针数据指针p,使p先后指向name数组中的各个元素，
            输出这些元素所对应的字符串。
        char *name[]={"Follow me","BASIC","Greate Wall","FORTRAN","Computer design"};
            char **p;
            for (int i = 0; i < 5; i++)
            {
                p=name+i;
                printf("%s\n ",*p);
            }
    运行结果：
            Follow me
            BASIC
            Greate Wall
            FORTRAN
            Computer design
    eg:2,有一个指针数组， 其元素分别指向一个整形数组的元素，用指向指针数据的指针变量，
        输出整型数组各个元素的值；
        int a[]={1,3,5,7,9};
        int *num[5];//指针数组
        int ** intP;
        for (int  i = 0; i < 5; i++)
        {
        num[i]=&a[i];
        }
        intP=num;
        for (int inpI = 0; inpI < 5; inpI++,intP++)
        {
            printf("%d  ",**intP);
        }

    运行结果：
        1  3  5  7  9 
    上述也可以将for循环改为：
    int *name[5]={&a[0],&a[1],&a[2],&a[3],&a[4]}; 的形式

    注意：指向指针的数据指针也是一种间接寻址的过程，

 */

int main(int argc, char const *argv[])
{
    void sort(char *name[], int n);
    void print(char *name[],int n);
    int a[]={1,3,5,7,9};
    int *num[5];//指针数组
    int ** intP;
    for (int  i = 0; i < 5; i++)
    {
       num[i]=&a[i];
    }
    intP=num;
    for (int inpI = 0; inpI < 5; inpI++,intP++)
    {
        printf("%d  ",**intP);
    }
    

    
    //char *name[]={"Follow me","BASIC","Greate Wall","FORTRAN","Computer design"};
    int n=5;
    //三、若干字符串按首字母排序的算法
    //sort(name,n);
   // print(name,n);
   char *name[]={"Follow me","BASIC","Greate Wall","FORTRAN","Computer design"};
   char **p;
   for (int i = 0; i < 5; i++)
   {
       p=name+i;
       //printf("%s\n ",*p);
   }
   
    return 0;
}
//三、将若干字符串按字母顺序（由小到大）输出
void sort(char *name[], int n)
{
    void print(char *name[],int n);
    int i, j, k;
    char *temp;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
//  原数组：char *name[]={"Follow me","BASIC","Greate Wall","FORTRAN","Computer design"};
        for (j = i + 1; j < n; j++){
            if (strcmp(name[k], name[j]) > 0)
                k = j;
        }
        if (k != i)
        {
            temp = name[i];
            name[i] = name[k];
            name[k] = temp;
        }
      printf("i=%d,k=%d,j=%d,%s\n,",i,k,j,name[i]);
      print(name,n);
    }
}
//三、打印数据
void print(char *name[],int n){
    int i;
    for ( i= 0; i < n; i++)
    {
        printf("%s   ",name[i]);
    }
     printf("\n");
}