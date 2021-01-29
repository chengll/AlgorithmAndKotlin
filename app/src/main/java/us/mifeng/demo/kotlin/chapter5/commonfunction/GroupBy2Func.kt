package us.mifeng.demo.kotlin.chapter5.commonfunction

fun main() {
    val list= listOf("a","ab","b");
    println(list.groupBy (String::first))
}
/*
* result:
*  {a=[a, ab], b=[b]}
* */