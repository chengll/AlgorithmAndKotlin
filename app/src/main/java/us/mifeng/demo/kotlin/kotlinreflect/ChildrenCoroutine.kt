package us.mifeng.demo.kotlin.kotlinreflect

import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking

fun main() = runBlocking {
    val request=launch {
        GlobalScope.launch {
             println("job1 :I run in GlobalScope and execute independently");
            delay(1000L);
            println("job1 : I am not affected by cancellation of the request");

        }

        launch {
            delay(100);
            println("job2 :I am a child request coroutine");
            delay(1000)
            println("job2 : I will not execute this line if my parent request  is cancelled");
        }
    }

    delay(500);
    request.cancel();
    delay(1000)
    println("main:who has survived request cancellation?");

}
/*
*  result:
*  job1 :I run in GlobalScope and execute independently
    job2 :I am a child request coroutine
    job1 : I am not affected by cancellation of the request
    main:who has survived request cancellation?
*
* */