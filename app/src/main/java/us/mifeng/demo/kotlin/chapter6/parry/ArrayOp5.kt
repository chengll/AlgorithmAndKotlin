package us.mifeng.demo.kotlin.chapter6.parry

fun main(args: Array<String>) {
    val arrayArgs: Collection<Int> = arrayListOf(1, 5, 7, 9);
    arrayArgs.forEachIndexed { index, element ->
        println("Argument $index is: ${element}")
    }
}
/*
* result:
*
*       Argument 0 is: 1
        Argument 1 is: 5
        Argument 2 is: 7
        Argument 3 is: 9
* */