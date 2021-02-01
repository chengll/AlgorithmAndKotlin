package us.mifeng.demo.kotlin.chapter9

fun printSum(c:Collection<*>){
    val intList= c as? List< Int> ?: throw IllegalAccessException("List is expected");
    println(intList.sum())
}

fun printSum2(c:Collection<Int>){
    if(c is  List<Int>){
        println(c.sum())
    }
}




fun main() {
    printSum(listOf(1,2,4,5))
    printSum2(listOf(1,2,4,5))
}
/*
* result:  12
*          12
*
* */