package us.mifeng.demo.kotlin.chapter9

val<T> List<T>.penultimate :T
    get()=this[size-2];
fun main() {
    println(listOf(1,2,3,4).penultimate)
}

/*
* result:
*   3
* */
