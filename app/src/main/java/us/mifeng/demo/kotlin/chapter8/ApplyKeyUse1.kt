package us.mifeng.demo.kotlin.chapter8

import java.lang.StringBuilder

fun main() {
    println(StringBuilder().apply sb@{
        listOf(1,2,4).apply {
            this@sb.append(this.toString())
        }
    })
}
/*
* result:
*   [1, 2, 4]
* */