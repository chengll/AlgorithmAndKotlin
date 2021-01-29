package us.mifeng.demo.kotlin.chapter5.commonfunction

import us.mifeng.demo.kotlin.chapter2.Person


fun main() {
    val list= listOf(1,2,5,8);
    println(list.filter { it % 2==0; })
    val personList = listOf<Person>(Person("test", false), Person("lingling", true))
    println(personList.filter { it.isMarried==true })
}
/**
 * result;
 *    [2,8]
 *    Person("lingling", true)
 *
 * */