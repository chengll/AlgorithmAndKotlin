package us.mifeng.demo.kotlin.chapter3

fun main() {
    println("12.345-6.A".split("\\.|-".toRegex()));
    println("12.345-6.A".split(".","-"))
}
/*
* result:
*  1.[12, 345, 6, A]
* 2.[12, 345, 6, A]
* */