package us.mifeng.demo.kotlin.chapter10

import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking
import kotlinx.coroutines.withTimeout

var  acquired=0;
class Resource{
    init {
        acquired++;
    }
    fun close(){
        acquired--;
    }
}

fun main() {
    runBlocking {
        repeat(100_1000){
            launch {
                var resource= withTimeout(60){
                    delay(50);
                    Resource();
                }
                resource.close();

            }
        }
    }

    println(acquired);
    
}