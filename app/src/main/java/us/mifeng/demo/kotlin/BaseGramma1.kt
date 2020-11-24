package us.mifeng.demo

import java.sql.DriverManager.println

fun main() {
 /*System.out.println("第一种种求和方式："+add(2,4));
 System.out.println("第二种求和方式"+add2(2,3));
 printSum(a = 2, b = 4);
 System.out.println("定义简单变量，并输出变量的值"+ defineVar());
 */

 fun printDouble(d:Double){ //打印double的值
  print(d);
 }

 val a:Double=21.0;
 //print(a);
 fun printFloat(a:Float){ //打印浮点类型
  //print(a);
 }
 val  b:Float=12f;
 //printFloat(b);

 fun printLong(a:Long){//"打印长整型"+
  println(a);
 }
 val c:Long=1232;
 //printLong(c);
/***************************************数组的基本语法**************************************/
 val asc=Array(5){
 i->(i*i ).toString();
}
 asc.forEach { println(it) };
}

fun add(a:Int,b:Int):Int{
 return a+b;
}
fun add2(a:Int,b:Int)=a+b;
fun add3(a:Int,b:Int):Unit{
 println("sum of $a and $b is ${a +b}");
}
fun printSum(a: Int, b: Int): Unit {
 print("sum of $a and $b is ${a + b}")
}

fun  defineVar(){ //定义变量
 val a:Int;
 a=2;
 val b:Int=2;
 println("a的值是 $a,  b的值是 $b");

}