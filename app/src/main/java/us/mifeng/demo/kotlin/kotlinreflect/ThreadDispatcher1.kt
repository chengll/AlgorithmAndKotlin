package us.mifeng.demo.kotlin.kotlinreflect

import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.newSingleThreadContext
import kotlinx.coroutines.runBlocking

fun main() = runBlocking <Unit>{
    launch {
        println("main   runBlocking :I'm working in thread  ${Thread.currentThread().name}");
    }

    launch (Dispatchers.Unconfined){
        println("unconfined  ${Thread.currentThread().name}")
    }

    launch (Dispatchers.Default){
        println("Default  ${Thread.currentThread().name}");
    }

    launch(newSingleThreadContext("MyOwnThread")) {
        println("newSingleThreadContext ${Thread.currentThread().name}");
    }
}

/* result:
        unconfined  main
        Default  DefaultDispatcher-worker-1
        newSingleThreadContext MyOwnThread
        main   runBlocking :I'm working in thread  main
*
*
* */