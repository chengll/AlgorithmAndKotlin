package us.mifeng.demo.kotlin.chapter6

import us.mifeng.demo.kotlin.chapter2.Person

fun yellSafe(person:Person){
    println((person.name?: "AnyOne").toUpperCase()+ "!!!")
}

fun showProgress(progress:Int){
    val percent=progress.coerceIn(0,100);
    println("we are  ${percent}% done");
}
fun main() {
    yellSafe(Person("",true))
    showProgress(146);
}

/*
* result:
*   !!!
*   we are  100% done
* */