package us.mifeng.demo.kotlin.chapter10

import us.mifeng.demo.kotlin.chapter6.foo
import us.mifeng.demo.kotlin.chapter8.Persons
import kotlin.reflect.full.memberProperties

fun main() {
    val person=Persons("Alice",12);
    val kClass = person.javaClass.kotlin;
    //1.
    println(kClass.simpleName);
    kClass.memberProperties.forEach{
        //2.
        println(it.name)
    }
    //3.
    val kClass2=::foo;
    kClass2.call(43);

    //4.
    val memeoryProperty= person::age;
    println(memeoryProperty.get())
}
/*
*  result:
   1.Persons
   2.
        age  name
   3.
        43
   4.
        12

* */