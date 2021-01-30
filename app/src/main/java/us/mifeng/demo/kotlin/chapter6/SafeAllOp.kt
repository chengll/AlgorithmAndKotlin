package us.mifeng.demo.kotlin.chapter6

fun printAllCaps(s:String?){
    val allCaps:String?=s?.toUpperCase();
    println(allCaps);
}
fun main() {
    printAllCaps("abc");
    printAllCaps(null)
}
/*
* result:
*   ABC
    null
* */