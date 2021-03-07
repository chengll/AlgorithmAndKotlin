package us.mifeng.demo.kotlin.kotlinandjava.kotjiegou

/**
 *Kotlin的解构通常是用于遍历一个map的遍历操作
 * */

fun main() {
    val map:Map<String,String> = mapOf<String,String>("one" to "blueSky","two" to "white cloud");
    //直接将一个map对象拆解为k,v的形式
    for ((k,v) in map){
        println("$k->$v");
    }
}
/**
 * result:
        one->blueSky
        two->white cloud
 * */