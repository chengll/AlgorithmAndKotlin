package us.mifeng.demo.kotlin.kotlinreflect

import kotlinx.coroutines.*

fun main() = runBlocking {
    val startTime=System.currentTimeMillis();
    val job=launch (Dispatchers.Default){
        var nextTime=startTime;
        var i=0;
        while (i<5){
            if (System.currentTimeMillis() >=nextTime){
                println("job: I'm sleeping ${i++}");
                nextTime+=500L;
            }
        }
    }

    delay(1300L);
    println("main: I'm tired of waiting");
    job.cancelAndJoin();
    println("now I'm quit ")
}

/*
*  result:
*   job: I'm sleeping 0
    job: I'm sleeping 1
    job: I'm sleeping 2
    main: I'm tired of waiting
    main: now i can  quit
*
* */