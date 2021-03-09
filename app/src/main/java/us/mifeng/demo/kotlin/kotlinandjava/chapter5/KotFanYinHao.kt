package us.mifeng.demo.kotlin.kotlinandjava.chapter5

import java.io.File

/**
 * 反引号的神奇特性， ` `
 * 反引号，：键盘左上角与波浪线一起的符号
 * 在kotlin 中，可以使用反引号解决关键字冲突问题，
 * 如果kotlin中定义的方法不想被java访问到，就可以使用反引号的形式
 *
 * */

fun `1234`(){
    println("test1");
}

//别名
public typealias A = File
fun main() {
 `1234`();
    val a=null;
    val b=null;
    a == b  //等价于java的 a.equals(b)
    a=== b  //等价于java的 a于b是否是同一对象
   val newFile:File=A(""); //调用别名，表示A与 File 是同一个东西


}