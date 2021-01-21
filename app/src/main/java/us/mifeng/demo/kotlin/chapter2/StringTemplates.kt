package us.mifeng.demo.kotlin.chapter2

//字符串模板输出变量的值
fun main(args:Array<String>) {
    //1.
    val name=if (args.size>0)args[0] else "kotlin"
    println(name);
    //2.
    if(args.size>0){
        println("hello, ${args[0]}");
    }
    //3
    println("Hello,${if (args.size>0) args[0] else "someone"}")
}
/*
result:
1. kotlin
2. 什么也没有，因为args.length!>0
3.Hello,someone
*/
