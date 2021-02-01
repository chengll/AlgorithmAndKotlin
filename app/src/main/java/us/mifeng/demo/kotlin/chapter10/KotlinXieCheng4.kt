package us.mifeng.demo.kotlin.chapter10

import kotlinx.coroutines.*

fun main() = runBlocking {
    GlobalScope.launch {
        repeat(1000){
            i->
            println("I'm sleeping $i...")
            delay(500L);
        }
        doWorld();
    }
    delay(3000L);
    coroutineScope {
        launch {
            delay(300L);
            println("Task from nested launch");
        }

        delay(100L);
        println("Task from coroutine scope")
    }

    println("Coroutine scope is over");
}

suspend fun doWorld(){
    delay(1000L);
    println("World")
}