package us.mifeng.demo.kotlin.chapter5

fun salute()=println("I am saluting");
fun main() {
    println("打印salute(）的引用：");
    run (::salute)
}
/*
*  result:
*       打印salute(）的引用：
        I am saluting
* */