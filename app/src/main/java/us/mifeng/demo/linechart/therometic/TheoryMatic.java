package us.mifeng.demo.linechart.therometic;

import android.util.Log;

/**
 * 算法工具类
 */
public class TheoryMatic {
    /**
     * 确定元素item在长度为n顺序表的位置
     * @param arr:存放的数组
     * @param  item:需要查找的元素
     * */
    public static int locate(int arr[], int item) {
        int i;
        do {
            if (arr.length == 0) {
                return -1;//如果是空的
            }
            for (i = 0; i < arr.length; i++) {
                if (arr[i] == item) {
                    return i;
                }
            }
        } while (i < arr.length);
        return -1;
    }

    /** 在长度为n的线性表A的第i的位置上插入一个新的元素item
     * @param   a 数组存放数据
     * @param  item :需要插入的元素
     * @param  i:需要插入的位置
     * @param  n,线性表的长度
     * */
    public static int insertData(int a[], int item, int i, int n) {
        int j;
        if (i > n || i<0) {
            return -1;
        }
        for (j=a.length-2;j>=i-1;j--) {//j倒叙从第二个数据往前面捋动
            a[j + 1] = a[j];
        }

        a[i-1] = item;
        n++;
        printData(a);
        return 0;
    }

    /**删除长度为n的顺序表A中位置i上的元素
     * @param a 数组
     * @param index:指定删除的位置
     * @param  item:需要删除的元素
     * @param  n:线性表的长度
     * */
    public  static int deleteAtom(int a[],int index,int item,int n){
        int j;

        //for ()
     return 0;
    }

    //打印输出
    public static void printData(int a[]){
        for (int i=0;i<a.length;i++){
            Log.d("testLocate", "printData: ------输出数组是a["+i+"]"+a[i]+"\n");
        }
    }
}
