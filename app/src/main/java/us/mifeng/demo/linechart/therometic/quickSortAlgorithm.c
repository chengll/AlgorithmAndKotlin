#include <stdio.h>
#include<string.h>
#include<stdlib.h>
/*
快速排序：时间复杂度 o(n*log2n) 
快速排序是排序最快的一个
快速排序不适用于有序的序列，序列越是无序越容易排好
快速排序不是原地排序，，在平均情况下：需要（logn）的栈空间，最坏的情况下可达o(n)

快速排序划分数轴的策略
 1.排序的范围是low---high,新增一个空间temp来存放arr[0]的第一个值，
 2.然后在i=low;j=high; 当i<j时，
    while(i<j){
        while(i<j && a[high]>=temp的值的时候，让high往前移动，high--,)
        一直循环，直到a[j]!>=temp 或者i!<j的时候，
    }
    由于a[i]的值存放在temp中，所以不怕覆盖，将a[j]的值赋值给a[i];即可a[j]=a[i];
    然后接着第二次循环，此时a【i】的值就是a[j]换过来的值，再去循环判断
  3.  while(i<j && a[i]<temp){
        当换过来的值还比temp小的话，low++，low后移动，直到
        条件不成立，
    }
    此时将a[i]的值赋值给上次腾出来的a[j]的位置，即a[j]=a[i],
 4.然后继续最外层的循环，while(i<j){}循环，重复上述2-3步骤，直到条件不满足，则
    将temp的值赋值给a[i],即a[i]=temp；
5.开始下一轮划分，从第一次划分后，将数据划分为两部分，一部分是从low--i-1之间，这部分的数据
 都小于temp的值，而另外一部分 i+1 到  high之间的数据都大于等于temp，然后开始递归
     quickSort(arr[],low,i-1);
     quickSort(arr[],i+1,high);
 */
#define maxSize 20
typedef struct {
    int r[maxSize];
    int length;
    int maxSizeCapacity;
}SqList;
void quickSort(SqList L,int low,int high){
    L.r[0]=L.r[low];
    int pivotKey=L.r[low]; //表示数轴的数字
    while(low<high){
        while (low<high && L.r[high]>=pivotKey)
        {
           high--;
        }
        L.r[low]=L.r[high];
        while (low<high && L.r[low]<=pivotKey)
        {
            low++;
        }
        L.r[high]=L.r[low];
    }
    L.r[low]=L.r[0];
     quickSort(L,low,high-1);
     quickSort(L,low+1,high);
}