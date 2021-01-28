package us.mifeng.demo.kotlin.kotlinreflect

import kotlinx.coroutines.*
import java.lang.ArithmeticException
import kotlin.system.measureTimeMillis

fun main() = runBlocking {
    val time = measureTimeMillis {
        val one = somethingUsefulOneAsync();
        val two = somethingUsefulTwoAsync();
        runBlocking {
            println("The answer is ${one.await() + two.await()}");
           // failedCocurrentSum();
        }
    }
    println("complete in $time ms")

}

fun somethingUsefulOneAsync() = GlobalScope.async {
    doSomeThingUsefulOne();
}

fun somethingUsefulTwoAsync() = GlobalScope.async {
    doSomeThingUsefulTwo();
}

suspend fun failedCocurrentSum(): Unit = coroutineScope {
    val one = async<Int> {
        try {
            delay(Long.MAX_VALUE);
            42
        }
          finally {
              println("First child was canceled");
        }

    }
    val two=async <Int>{
        println("The second child  throws an exception");
        throw  ArithmeticException();


    }


}