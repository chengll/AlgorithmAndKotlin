package us.mifeng.demo.kotlin.chapter5.commonfunction

fun main() {
    val  natureNumbers= generateSequence (0){it +1;}
    val number0To100=natureNumbers.takeWhile { it<=100; }
    println(number0To100.sum());
}
/*
*   result: 5050
* */