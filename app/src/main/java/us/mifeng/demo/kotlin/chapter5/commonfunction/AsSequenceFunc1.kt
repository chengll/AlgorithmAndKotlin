package us.mifeng.demo.kotlin.chapter5.commonfunction

fun main() {
    listOf(1,2,3,4).asSequence().map { println("map($it)");it *it }
            .filter { println("filter($it)");it % 2==0 }
            .toList()
}
/*
* result:
        map(1)
        filter(1)
        map(2)
        filter(4)
        map(3)
        filter(9)
        map(4)
        filter(16)
* */
