package us.mifeng.demo.kotlin.kotlinandjava.chapter1

/**
 * 注意让kotlin 的类实现java 接口，同方法名，int 和Integer会
 * 被kotlin 认为是同一个方法，因此我们可以看到AInterface中其实是
 * 声明了2个方法，但是kotin 只是重写一个类型为Int基本类型的方法
 *
 * 如果kotlin 想调用java的方法，就得使用反射的方式
 * */
class KotlinTest2:AInterface {
    override fun printNum(age: Int) {
       println("kotlin只能实现参数类型为基本类型的方法");
    }

    override fun systemNum(number: Int?) {
        println("kotlin会自动将java 的包装类改为基本类型 Integer改为 int?")
    }

}