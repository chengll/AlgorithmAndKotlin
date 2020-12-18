/* 归并排序算法：
    二级归并：即将n1 和n2两个部分进行归并，注意 n1=mid-low+1 ,表示第一个归并的角标的范围，
    注意这部分的数据是有序的；同理n2=high-mid部分的数据也是有序的，
 */
void merge(int arr[],int low,int mid,int high){
    int n1=mid-low+1;  int n2=high-mid;   int i,j,k;
    int L[n1],R[n2];
    for ( i = 0; i < n1; i++)
    {
       L[i]=arr[low+i];//第一个片段，从low位置开始的，因此读取数据的时候就是low+i
    }
    for ( j = 0; i < n2; j++)
    {
       R[j]=arr[mid+1+j]; //第二个片段，从mid位置开始的，因此读取数据的时候就是mid+1+j
    }
    i=0;j=0;k=low;
    while (i<n1 && j<n2)
    {
       if (L[i]<R[j])
       {
           arr[k]=L[i++];
       }else{
           arr[k]=R[j++];
       }
       k++;
    }
    while (i<n1)  //归并后如果剩余了n1，则把n1剩余的部分合并到序列中去
    {
       arr[k++]=L[i++];
    }
    while (j<n2)//归并后如果剩余了n2，则把n2剩余的部分合并到序列中去
    {
       arr[k++]=R[j++];
    }
  }

  void  mergeSort(int arr[],int low,int high){
      if (low<high)
      {
          int mid=(low+high)/2;
          mergeSort(arr,low,high);
          mergeSort(arr,mid+1,high);
          merge(arr,low,mid-1);
     }
