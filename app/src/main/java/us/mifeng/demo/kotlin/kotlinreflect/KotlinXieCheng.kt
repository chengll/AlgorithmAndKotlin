package us.mifeng.demo.kotlin.kotlinreflect

import kotlinx.coroutines.*
import okhttp3.Dispatcher

/*

import java.lang.IllegalStateException
import kotlin.coroutines.*

*/
/*
* kotlin中的协程
*
* *//*

interface Generator<T>{
    operator  fun iterator():Iterator<T>;
}

class GeneratorImp<T>(private val block:suspend  GeneratorScope<T>.(T) ->Unit,private val parameter:T ):Generator<T>{
    override fun iterator(): Iterator<T> {

    }

}

//要求yield只在方法内部可以使用，因此需要定义一个receiver,要使用internal关键字

abstract class GeneratorScope<T> internal constructor(){
    protected  abstract val paramter:T;
    abstract suspend fun yield(value:T)

}
//定义一些状态密封类，来表示协程执行的状态
sealed class State{
    class NotReady(val continuation:Continuation<Unit>):State()
    class Ready<T>(val continuation: Continuation<Unit>, val nextValue:T ):State()
    object Done:State()
}

//些iterator的实现类
class GeneratorIterator<T> (private val block:suspend GeneratorScope<T>.(T)->Unit, val parameter: T, override val paramter: T):Iterator<T>,GeneratorScope<T>(),Continuation<Any?>{
    override val context: CoroutineContext=EmptyCoroutineContext;
    private val state:State
    //初始化协程
    init {
        val coroutineBlock:suspend GeneratorScope<T>.()->Unit={block(parameter)}
        val start=coroutineBlock.createCoroutine(this,this)
        state=State.NotReady(start)
    }


    private fun  resume(){
        when(val currentState=state){
            is State.NotReady->currentState.continuation.resumeWith(Unit)
        }
    }

    override fun hasNext(): Boolean {
        resume()
        return state!=State.Done;

    }

    override fun next(): T {
        return when(val currentState=state){
            is State.NotReady ->{
                resume()
                return next();
            }

            is State.Ready<*>->{
                (currentState as State.Ready<T> ).nextValue;
            }

        }

    }

    override suspend fun yield(value: T) = suspendCoroutine <Unit>{
        continuation->
        when(state){
            is State.NotReady->
                State.Ready(continuation,value)
            is State.Ready<*> ->throw  IllegalStateException ("can not yiela a value while ")
                State.Done-> throw IllegalStateException("can not yield a valye while")

        }
    }

    override fun resumeWith(result: Result<Any?>) {

    }

}

fun <T> generator(block:suspend GeneratorScope<T>.(T)->Unit):(T)->Generator<T>{
    return{
        parameter:T->
        GeneratorImp(block,parameter)
    }
}

*/
//注意协程在引入时需要在app的build。gradle下配置相关的依赖
fun main() = runBlocking { // this: CoroutineScope
  launch { // launch new coroutine in the scope of runBlocking
    delay(1000L)
    println("World!")
  }
  println("Hello,")
}
