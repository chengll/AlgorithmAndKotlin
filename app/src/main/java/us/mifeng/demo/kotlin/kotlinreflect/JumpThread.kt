package us.mifeng.demo.kotlin.kotlinreflect

import kotlinx.coroutines.newSingleThreadContext
import kotlinx.coroutines.runBlocking
import kotlinx.coroutines.withContext

fun main(){
    newSingleThreadContext("Ctx1").use { ctx1->
        newSingleThreadContext("Ctx2").use { ctx2->
            runBlocking(ctx1) {
                println("Started in Ctx1");
                withContext(ctx2){
                    println("work in Ctx2");
                }
                println("Back to Ctx1");
            }
        }
    }
}
/*
* result:
*   Started in Ctx1
    work in Ctx2
    Back to Ctx1
* */