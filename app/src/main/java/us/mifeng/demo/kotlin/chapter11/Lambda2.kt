package us.mifeng.demo.kotlin.chapter11

import java.lang.StringBuilder


fun buildString2(buildAction:StringBuilder.() ->Unit):String{
    val sb=StringBuilder();
    sb.buildAction()
    return sb.toString();
}

fun main() {
    val s = buildString2 {
        this.append("Hello, ")
        append("World!")
    }
    println(s)
}
/*
* result:
*  Hello, World!
*
* */