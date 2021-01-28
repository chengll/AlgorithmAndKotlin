package us.mifeng.demo.kotlin.chapter3

//给String类添加一个扩展方法
fun String.lastChar():Char=this.get(this.length-1);
fun main() {
    println("koltin".lastChar());

}
/*
* result: n
* */

