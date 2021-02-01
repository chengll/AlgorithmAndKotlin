package us.mifeng.demo.kotlin.chapter8

import java.lang.StringBuilder

fun String.filter(predicate:(Char) ->Boolean):String{
    val sb=StringBuilder();
    for (index in 0 until length){
        val element=get(index);
        if(predicate(element)){
            sb.append(element);
        }
    }
    return sb.toString();
}
fun processTheAnswer(f:(Int)->Int){
    println(42);
}
fun main() {
    println("abc4".filter { it in 'a'..'z' })
    processTheAnswer({4});
}
/*
* result:
*       abc
*       42
* */