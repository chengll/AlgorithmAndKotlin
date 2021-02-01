package us.mifeng.demo.kotlin.chapter11

fun main() {
    val map= mutableMapOf( 1 to "one");
    map.apply{this[2]="two"  }
    with(map){this[3]="three"}
    println(map)
}