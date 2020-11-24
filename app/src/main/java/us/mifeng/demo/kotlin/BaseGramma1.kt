package us.mifeng.demo.kotlin

import java.lang.Integer.parseInt
import java.sql.DriverManager.println

fun main() {
    /*System.out.println("第一种种求和方式："+add(2,4));
    System.out.println("第二种求和方式"+add2(2,3));
    printSum(a = 2, b = 4);
    System.out.println("定义简单变量，并输出变量的值"+ defineVar());
    */

    fun printDouble(d: Double) { //打印double的值
        print(d);
    }

    val a: Double = 21.0;
    //print(a);
    fun printFloat(a: Float) { //打印浮点类型
        //print(a);
    }

    val b: Float = 12f;
    //printFloat(b);

    fun printLong(a: Long) {//"打印长整型"+
        println(a);
    }

    val c: Long = 1232;
    //printLong(c);
    /***************************************数组的基本语法**************************************/
    val asc = Array(5) { i ->
        (i * i).toString();
    }
    asc.forEach { print(it) };

    /***************************************流程控制语句**************************************/
    fun getMax(a: Int, b: Int): Int {
        //第一种 注意这里max的类型是var类型，不能是val类型
        var max: Int = a;
        if (a < b) max = b;
        else
            max = a;
        return max;
    }
    //第二种
    val max = if (a > b) a else b;

    //when语句表达式----p普通流程

    fun whenSyntax(x: Int, s: String) {
        when (x) {
            1 -> println("x==1");
            2 -> println("x==2");
            3 -> println("x==3");
            4, 5 -> println(" x>=4 && x<=5");
            !in 10..20 -> println("该x的范围不属于10-20之间");
            parseInt(s) -> println("转化后的数位：" + x) //将String类型转化为int类型
            else -> {
                println("x  is an unknow data");
            }
        }
    }

    //通过when流程来实现boolean 的表达式的实现
    fun hasPrefix(x: Any) = when (x) {
        is String -> x.startsWith("prefix");
        else ->
            false;
    }

    fun isOdd(i:Int): Boolean {
        for ( i in 1.. 100){
            if (i %2 ==1){
                return true;
            }
        }
        return false;
    }

    fun whenExpression3(x:Int){
        when{
            isOdd(x) -> print("x is odd");
            else->print("x是奇数啦");
        }
    }

    /***************************************for循环语句**************************************/
    fun forSyntax(){
        for (i in 1..6){
            println(i);
        }
    }

    for (item:Int in 1..9){
        println(item);
    }





}



fun add(a: Int, b: Int): Int {
    return a + b;
}

fun add2(a: Int, b: Int) = a + b;
fun add3(a: Int, b: Int): Unit {
    println("sum of $a and $b is ${a + b}");
}

fun printSum(a: Int, b: Int): Unit {
    println("sum of $a and $b is ${a + b}")
}

fun defineVar() { //定义变量
    val a: Int;
    a = 2;
    val b: Int = 2;
    println("a的值是 $a,  b的值是 $b");

}