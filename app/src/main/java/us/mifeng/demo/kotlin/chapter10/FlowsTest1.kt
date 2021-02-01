package us.mifeng.demo.kotlin.chapter10

import kotlinx.coroutines.*
import kotlinx.coroutines.flow.*

fun simpleFlow(): Flow<Int> = flow {
    for (i in 1..3) {
        delay(100);
        emit(i);
    }
}
fun main()= runBlocking <Unit>{
    launch {
        for (k in 1.. 3){
            println("I'm not blocking  $k")
            delay(100);
        }
    }

    simpleFlow().collect{
        value->
        println(value);
    }
}
/*
*  result:
*   I'm not blocking  1
    1
    I'm not blocking  2
    2
    I'm not blocking  3
    3

*
* */