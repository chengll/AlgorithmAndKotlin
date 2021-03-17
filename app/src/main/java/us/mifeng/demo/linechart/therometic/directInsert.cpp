/*
插入排序的思想：
1.定位插入排序---直接插入法
2.定位插入位置---二分插入法
3.缩小增量多遍插入排序---希尔排序法

 首先看直接插入排序：使用的是顺序查找的方法
 int arr[]是一组待排序的数字，elem为需要插入的元素 n为该数组中全部的数据的长度，
 具体实现思想是：将需要插入的数elem插入前面一个有序的数组中，比如当前的位置为i，
 这时候需要将目前的位置的数取出来，暂存在temp临时变量中，即temp=arr[i],然后在循环内部采用的是循环，
 令int j=i-1;
  for()
 */

//直接插入法  请查看drawable 中的directinsertimg.png 看执行过程
 void directInsert(int arr[],int n){
     int temp,j;
  for(int i=1;i<n;i++){
      temp=arr[i];
       j = i-1;
      for (j ;j>=0 && temp<arr[j]; j--) //升序排列，如果当前的temp值小于arr【j】的值，则要
      {
          arr[j++]=arr[j];
      }
      arr[j+1]=temp;
  }
}