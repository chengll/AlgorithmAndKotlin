package us.mifeng.demo.kotlin.chapter6


fun foo(l:Long)=println(l)
fun main() {
    val x=1;
    //1
    println(x.toLong() in listOf(1L,2L,4L))
    //2.
    val b:Byte=1;
    val l=b+1L;
    foo(42);
    //3.
    println("42".toInt());


}
/*
* result:
*       1.true
*       2.  42
*       3.  42
*
*
* */