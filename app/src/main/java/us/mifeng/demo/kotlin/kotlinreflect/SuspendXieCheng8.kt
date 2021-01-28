package us.mifeng.demo.kotlin.kotlinreflect

import kotlinx.coroutines.delay
import kotlinx.coroutines.runBlocking
import kotlin.system.measureTimeMillis

fun main()= runBlocking <Unit>{
    val time= measureTimeMillis {
        val one=doSomeThingUsefulOne()
        val two=doSomeThingUsefulTwo();
        println("The answer is ${one +two}");
    }
    println("complete in ${time} ms")
}

suspend fun doSomeThingUsefulOne():Int{
    delay(1000L);
    return 13;
}

suspend fun doSomeThingUsefulTwo():Int{
    delay(100L);
    return 29;
}

/*
* result:
*  The answer is 42
    complete in 1128 ms (这段时间是不确定的，随机的)
*
* */