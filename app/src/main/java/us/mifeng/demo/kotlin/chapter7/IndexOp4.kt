package us.mifeng.demo.kotlin.chapter7

fun main() {
    val n=9;
    println(0..(n+1))
    (0..n).forEach{
        println(it);
    }
}
/*
* result:
*       0..10
*
        0
        1
        2
        3
        4
        5
        6
        7
        8
        9

* */