package us.mifeng.demo.kotlin.chapter6

fun <T> copyElement(source: Collection<T>, target: MutableCollection<T>) {
    for (item in source) {
        target.add(item)
    }
}

fun main() {
    val source1: Collection<Int> = arrayListOf (3, 5, 7)
    val target :MutableCollection <Int> = arrayListOf(1);
    println(target)
    copyElement(source1,target);
    println(target)
}
/*
* result:
*   [1]
*
*   [1, 3, 5, 7]

* */