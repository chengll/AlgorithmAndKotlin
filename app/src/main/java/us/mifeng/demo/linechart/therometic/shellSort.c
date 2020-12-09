#include<stdio.h>
#include<stdlib.h>
/*
  希尔排序：
  如果你想熟悉shell排序的过程，请查看我的drawable下面的图片，
  我仔细做了使用shell排序执行的过程哦

*/

void shellSort(int a[],int n){
 int temp; int gap,i,j;
 for(gap=n/2;gap>0;gap=gap/2){
  for(i=gap;i<n;i++){
   temp=a[i];
   for(j=i;j>=gap && a[j-gap]>temp;j-=gap){
     a[j]=a[j-gap];
   }
   a[j]=temp;
  }
 }
}