package us.mifeng.demo.kotlin.chapter5

import java.lang.StringBuilder

fun alphabet2() = StringBuilder().apply {
    for (letter in 'A'..'Z') {
      append(letter)
    }
    append("\n now  I know  the alphabet!")
}.toString()

fun main() {
    println(alphabet2())
}
/*
* result:
*           ABCDEFGHIJKLMNOPQRSTUVWXYZ
            now  I know  the alphabet!
* */

