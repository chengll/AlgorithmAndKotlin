//指针相关的知识
#include <stdio.h>
int add(int x ,int *p){
    x+=*p;
    *p=x;
    return x;
}
int main(int argc, char const *argv[])
{
   int a=2,b=3,c=0;
  c=add(a,&b);
  printf("c=%d  a=%d  b=%d",c,a,b);
    return 0;
}
/* 1.指针加减一个整数n，表示 使 该指针 所指向的位置向前或者向后移动 n 个元素，而且
     不同类型数据长度可能不同，让指向不同类型数组的指针所指的位置同样移动 n 个元素，
     指针值的改变可能是不同的，比如  int类型的数据长度是4个字节，而 short 类型的是2个字节，
     因此 short *p  ,p++;表示使p的值加 2 ，而int  *q;q++,则表示使 q的值加 4 ，
     在实际开发中，对于指针p,*(p+n),表示p当前所指元素后面的第n个元素。比如
     指针p指向了数组的首地址a
     p=a 或者 p=&a[0],则 *（p+n）就等价于 a[n];

     2.在对指针变量同时使用表示间接访问的 *  号之后的 ++  或者 --时，必须注意运算符的结合关系
     是否与我们的表达式保持一致，
       C语言规定，++  和 --都是 自右向左 进行结合的，因此 *p++ 等价于 *(p++); 表示指针变量作用于指针p,
       但是 (*p)++ 表示P首先与 * 结合，++作用于 变量p所指向的变量:
       eg：int a,b，arr[]={0,1,2,3,4,5},*p1=&arr[1], *p2=&arr[5];
       a=*(p1++); //表示只移动指针，不修改p1指针所指的变量的值 此时 p1指向了 arr[2],
       b=(*p2)++; //表示指针不动，修改p2指针所指向的元素的值  arr[5]+1=5+1=6;p2还指向arr[5]

    3.指针相减：只有指向同一数组中的指针元素之间才可以相减，指针相减所得到的的结果是一个
    int 类型的整数，表示两个指针所指向的元素的下标之差.
    eg: int * int_low,*int_high,a[16];
        double *d_low, *d_high,d[16];
        int_low=a;
        int_high=&a[8];
        d_low=d;
        d_high=&d[8];
        printf("int_high- int_low=%d\n, d_high-d_low=%d",int_high- int_low,d_high-d_low);
        运行的结果是 int_high- int_low=8,d_high-d_low=8

    4.指针的比较：常见的有两种，第一种是两个指针间的比较；第二种是指针与 0的比较
     比较两个指针是否相等，其实是看两个指针是否指向同一个元素。
     C语言的习惯，一般对无效的指针 赋值为 0，实际使用中通过 P==NULL来表示

    5.指针类型的强制类型的转换： 不同类型的指针互相赋值时 就需要强制类型转换  ，
      eg: int *ia,*ip,arr[3][6];
          short s,sa[16],*id;
          ip=(int *)sa; //sa指针强制转为 int 类型
          ia=(int *)arr;
          id=(short *)&n;
          ip=(int *)id;
          C语言中还有一种特殊的指针 *void,与一般指针不同的是 *void 类型的指针可以
          赋值给任意 类型变量的指针，具有*void 类型的指针变量可以接受任意类型的指针。
          比如申请空间的函数 malloc就是*void类型的函数
          1）如果int 类型的变量要申请空间  使用 int *p=malloc(sizeOf(int));
          2）比如double类型的指针id申请保存200个double类型数据存储空间
          double *id=malloc(200*sizeOf(double));

    6.指针与数组
        int  i,a[N],*p=a;
        for(int i=0;i<N;i++){
            a[i]=i*i;
        }
        其中，a[i]=i*i; 也可以表示为以下几种方式
         1)  *（a+i)=i* i； 2) *(p+i)=i*i;
         3)  p[i]= i*i; 三种都是正确的方式

    7.二维数组和指针关系
        double a_arr[32][64],b_arr[64][128],c_arr[16][128];
        double (*ap)[64],(*bp)[128],(*bp_2)[128];

        ap=a_arr;
        bp=b_arr;
        bp=&c_arr[5];
        bp_2=&c_arr[8];
    注意：bp既可以指向数组b_arr,也可以指向c_arr,因为两个数组元素以及列数
    与bp指针的相同，但是 指针ap只能指向a_arr其中的任意一行，不能指向b_arr
    和c_arr,因为这两个数组的列数与ap指针的列数不同。
    2》对于二维数组的操作:
          对于二维数组的操作既可以安数组的方式操作，也可以按指针的方式操作。
          eg:*ap=ap[0]=a_arr[0];
          (*ap)[3]=*(*ap+3)=ap[0][3]等价a_arr[0][3];
          *bp=&c_arr[5] 表示bp指针指向了 c_arr[]数组中下标为5的行，表示bp
          等价于从c_arr[5]开始的二维数组
          即：*bp=bp[0]等价于c_arr[5]
          (*bp)[3]= *(*bp+3)=bp[0][3]等价于c_arr[5][3];

    3》二维指针与一维指针类似，二维指针相加减一个整数n 就等于原来位置后面
      或前面的第n 行，

     比如上面赋值操作中，*(ap +3)或者 ap[3] 等价于a_arr[3], *(bp+6)或者bp[6]
     等价于c_arr[11];
     *((*bp+6)+8)或者 *（*(bp+6))[8]或者bp[6][8] 等价于 c_arr[11][8],
     ap++ 或者 ++ bp都使得 ap和bp指向后一行，ap-- 或者 --bp都使得ap和bp指向前一行。

    4》指向同一数组的二维指针相减时 结果是一个整数，表示两个指针所指内容 相差的行数。

    比如上面代码中 bp指向了c_arr[5],bp_2指向了c_arr[8], 所以 bp_2 -bp=3；二维数
    组的行相减也会得到相同的结果 &c_arr[18]-&c_arr[12]=6;

    *ap[3] 等价于 ap[3][0], 然而
    （*ap）[3]等价于ap[0][3]
    通过指针来定义 5*5矩阵加法的函数 arr_add
    void  arr_add( int t1[][5],int t2[][5],int s[][5]);函数原型，通过指针定义如下
    void arr_add(int (*t1)[5],int (*t2)[5],int (*s)[5]);

 8.多重指针：一般情况下，多重指针变量保存的是比其低一重的指针变量的地址
    比如 二重指针变量保存的是普通指针变量的地址，三重指针变量保存的是
    二重指针变量的地址，以此类推
    eg:int **ipp,*ip,*ip2,i,j;
       double ***dppp, **dpp,*dp,d,d_arr[8];
       ip=&i;
       ipp=&ip;
       dp=d_arr;
       dpp=&dp;
       dppp=&dpp;
9.一维指针数组：
(1)一维指针数组的定义，以int类型为主
    int *p_arr[N];
 (2)指针数组的初始化
    double d1[N],d2[2*N],d3[3*N],avg,sum;
    double  *dp_arr[]={d1,d2,d3,&avg,&sum,NULL};
    以上两句表示定义了包含6个元素的double类型的指针数组d_arr[],


 */