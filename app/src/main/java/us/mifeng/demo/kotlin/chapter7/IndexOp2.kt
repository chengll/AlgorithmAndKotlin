package us.mifeng.demo.kotlin.chapter7

import java.lang.IndexOutOfBoundsException

data class  MutablePoint(var x:Int,var y:Int)
operator fun MutablePoint.set(index:Int,value:Int){
    when(index){
        0 -> x==value
        1 -> y==value
        else ->throw IndexOutOfBoundsException("invalid coordinate index $index")
    }
}
fun main() {
    val p=MutablePoint(10,20);
    p[1]=42;

    println(p);
}
/*
result:
    MutablePoint(x=10, y=20)
* */