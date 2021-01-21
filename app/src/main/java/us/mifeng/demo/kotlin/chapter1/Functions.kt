package us.mifeng.demo.kotlin.chapter1

fun main(args: Array<String>) {
    println(max(2, 6));
}

//比较两个数的大小
fun max(a: Int, b: Int): Int {
    return if (a > b) a else b;
}