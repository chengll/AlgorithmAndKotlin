package us.mifeng.demo.kotlin.chapter6.parry

fun main(args:Array<String>) {
    val strings= listOf('a','b','c');
    println("%s,%s,%s".format(*strings.toTypedArray()));
}
/*
* result:
*        a,b,c
* */