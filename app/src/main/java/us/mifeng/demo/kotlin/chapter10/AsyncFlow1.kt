package us.mifeng.demo.kotlin.chapter10

import kotlinx.coroutines.delay
import kotlinx.coroutines.runBlocking

/*fun main() {
 simple().forEach{
     value ->
     println(value);
 }
    //2.
    simple2().forEach {
        value->
        println(value)
    }
}*/

fun simple(): List<Int> =listOf(1,2,3);

fun simple2():Sequence<Int> = sequence {
    for (i in 1..3){
        Thread.sleep(100);
        yield(i);
    }
}

//注意上面的两个方法都是阻断了主线程的运行，因此为了避免这个，可以添加suspend,因此调用的地方也要相应的修改
suspend fun simple3() :List<Int> {

    delay(100);
    return listOf(1,2,3);
}

//3
fun main()= runBlocking <Unit>{
    simple3().forEach {
        value->
        println(value);
    }
}

/*
* 1. result:
* 1
  2
  3
  *
  * 2.result:
  * 1
    2
    3
    * 3.result;
    *   1
        2
        3


* */