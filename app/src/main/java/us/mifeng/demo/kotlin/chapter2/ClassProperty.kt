package us.mifeng.demo.kotlin.chapter2

class Person(val name:String,var isMarried:Boolean)

fun main() {
    val person=Person("Honey",true);
    println("输出用户的名字为 ${person.name}  ，该用户是否已经结婚:${person.isMarried}")
}
//result: 输出用户的名字为 Honey  ，该用户是否已经结婚:true
