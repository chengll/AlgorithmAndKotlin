package us.mifeng.demo.kotlin.chapter6

fun strLenSafes(s:String?):Int=s?.length?:0
fun main() {
  println(strLenSafes("abs"))
    println(strLenSafes(null))
}
/*
*result:
*   3
    0
*
* */