package us.mifeng.demo.kotlin.chapter6

fun strLenSafe(s:String?):Int=if(s!=null) s.length else 0;

fun main() {
 val x:String?=null;
    println(strLenSafe(x));
    println(strLenSafe("abs"));
}
/*
* result:
*   0
*   3
* */