package us.mifeng.demo.kotlin.chapter8
fun twoThree(operation:(Int,Int)->Int){
    val result=operation(2,3);
    println("result is $result")
}
fun main() {
    twoThree { a,b ->a + b}
    twoThree { a,b->a * b }
}
/*
*result:
*   result is 5
    result is 6
*
* */