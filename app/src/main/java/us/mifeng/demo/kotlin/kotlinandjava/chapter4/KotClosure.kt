package us.mifeng.demo.kotlin.kotlinandjava.chapter4

/**
 * kotlin 闭包
 * lambda 语法，比如java中：
Thead thread=new Thread(new Runnable(){
@overide
public void run(){
}
});
thread.start();
或者：
Thread thread=new Thread(()->{ System.out.println("java-lambda的写法")});
thread.start();
kotlin 中也支持这种lambda的形式

 *
 * */

fun main() {
    Thread({ println("这是kotlin 中lambda的写法"); }).start();
    //将只有一个参数的lambda提出来的形式
    Thread() {
        println("如果函数只有一个参数，且是一个lambda表达式时，则可以省略其小括号");
    }.start();
    echo.invoke("haha");
    echo("honey");

}

//闭包的声明
val echo = { name: String ->
    println("$name");
    println(name);
}
/**
 * result:
 *       这是kotlin 中lambda的写法
        如果函数只有一个参数，且是一个lambda表达式时，则可以省略其小括号
        haha
        haha
        honey
        honey
 * */