package us.mifeng.demo.kotlin.chapter10

import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking

fun main() {
    GlobalScope.launch {
        delay(1000L);
        println("world");
    }
    println("Hello");
    runBlocking {
        delay(2000L);
    }
}

/*
*  result:
*
* Hello
  world
* */