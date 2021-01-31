package us.mifeng.demo.kotlin.chapter7

import java.lang.IndexOutOfBoundsException

data class DataPoint(val x:Int,val y:Int)
operator fun DataPoint.get(index:Int):Int{
    return when(index){
        0 ->x
        1 ->y
        else -> throw IndexOutOfBoundsException("invalid coordinate $index")
    }

}

fun main() {
    val p=DataPoint(10,20);
    println(p[1]);
}
/*
*  result: 20
*
* */