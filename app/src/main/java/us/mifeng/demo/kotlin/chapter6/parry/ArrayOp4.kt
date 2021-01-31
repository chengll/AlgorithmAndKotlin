package us.mifeng.demo.kotlin.chapter6.parry


fun main(args:Array<String>) {
    val square=IntArray(5){
        i->(i+1) *(i+1);
    }
    println(square.joinToString())
}
/*
* result:   1, 4, 9, 16, 25
*
* */