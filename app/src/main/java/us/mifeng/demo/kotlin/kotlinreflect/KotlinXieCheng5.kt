package us.mifeng.demo.kotlin.kotlinreflect

import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking

fun main() = runBlocking {
    val job = launch {
        repeat(1000) { i ->
            println("job: I'm sleeping $i");
            delay(500L);
        }
    }

    delay(1300L);
    println("main: I'm tired of waiting");
    job.cancel();
    job.join();
    println("main: now i can  quit");
}

/*
*       job: I'm sleeping 0
        job: I'm sleeping 1
        job: I'm sleeping 2
        main: I'm tired of waiting
        main: now i can  quit
* */