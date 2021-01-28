package us.mifeng.demo.kotlin.kotlinreflect

import kotlinx.coroutines.CoroutineStart
import kotlinx.coroutines.async
import kotlinx.coroutines.runBlocking
import kotlin.system.measureTimeMillis

fun main() = runBlocking {
    val time = measureTimeMillis {
        val one = async(start = CoroutineStart.LAZY) { doSomeThingUsefulOne() }
        val two = async(start = CoroutineStart.LAZY) { doSomeThingUsefulTwo() }
        one.start();
        two.start();
        println("The answer is ${one.await()} + ${two.await()}");
    }
    println("comple in ${time} ms");
}

/*
* result:
* The answer is 42
  complete in 1127 ms
*
* */