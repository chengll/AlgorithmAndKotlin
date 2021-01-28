package us.mifeng.demo.kotlin.chapter5

fun main() {
    //1.
    val sum={x:Int,y:Int ->
    println("computating the sum of $x and $y")
        x+y
    }
    println(sum(1,7));
    //2.
    val sum2={x:Int,y:Int->x+y}
    println(sum2(1,52));

}
/*
* result:
     computating the sum of 1 and 7
        8
        53
* */