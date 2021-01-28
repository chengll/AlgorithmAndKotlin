package us.mifeng.demo.kotlin.chapter3

val set= hashSetOf(1,7,35);
val list= listOf(1,5,43);
val map= hashMapOf( 1 to "one",7 to " seven",53 to "fifty-three")

fun main() {
    println(set.javaClass)
    println(list.javaClass);
    println(map.javaClass);
}
/*
* result:
*   class java.util.HashSet
    class java.util.Arrays$ArrayList
    class java.util.HashMap
* */