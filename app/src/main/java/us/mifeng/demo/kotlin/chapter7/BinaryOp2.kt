package us.mifeng.demo.kotlin.chapter7

operator fun Char.times(count:Int):String{
    return toString().repeat(count);
}

fun main() {
    println('a' *3);
}
/*
* result:  aaa
* */