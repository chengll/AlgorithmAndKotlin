package us.mifeng.demo.kotlin.chapter10

import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch

fun main() {
    GlobalScope.launch {
        delay(1000L);
        println("world");
    }
    println("Hello");
    Thread.sleep(2000L);
}

/*
*  result:
*   Hello
    world

    注意如果将Thread的休眠时间也修改为 1000L时只能打印Hello
*
* */