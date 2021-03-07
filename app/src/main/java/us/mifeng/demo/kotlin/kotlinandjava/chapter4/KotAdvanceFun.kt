package us.mifeng.demo.kotlin.kotlinandjava.chapter4

/**
 * kotlin中高阶函数 指的是方法中可以以函数作为参数的函数称为高阶函数
 *
 * kotlin的lambda是一个匿名的函数，可以使用inline 关键字修饰，这样当方法在编译时就会拆解方法为语句调用，
 * 进而减少不必要对象的创建（用内敛优化代码）
 * */

//声明高阶函数，lambda函数必须是最后一个参数
inline  fun onlyPrint(isDebug:Boolean,block:()->Unit){
    if (isDebug) block();
}

inline fun  <T>  onlyPrint(isDebug:Boolean,isTrue:Boolean,block: () -> T) {
if (isDebug) block();
}

 val runnable= Runnable {  println("Runnable::run"); }

fun main() {
    //1
    onlyPrint(true){
        println("哈哈 可以打印日志喽！")
    }
    //2.
    onlyPrint(true,true){
        println("hhh");
    }
    //3
    val function:()->Unit
    function=runnable::run
    onlyPrint(true,function);
}

/**
 *  result:
 *          1.哈哈 可以打印日志喽！
 *          2.hhh
 *          3.Runnable::run
 *
 * */