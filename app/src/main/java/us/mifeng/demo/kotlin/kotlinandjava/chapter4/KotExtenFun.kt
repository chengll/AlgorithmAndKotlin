package us.mifeng.demo.kotlin.kotlinandjava.chapter4

/**
 * kotlin 扩展函数
 * 主要是一些第三方的sdk 或者不能直接访问的类，可以通过扩展函数给它新增一个方法
 * 扩展方法是静态的给一个类添加方法
 * 扩展函数的第一个参数 为该类的对象
 * */
open class Animal()
class Dog:Animal(){}
fun Animal.name()="animal";
fun Dog.name()="Dog"

//给Animal 增加一个扩展方法
fun Animal.printlnName(animal:Animal){
    println(animal.name());
}

fun main() {
    //注意：扩展方法不能被重写的，因为
  Dog().printlnName(Dog());
}
/**
 * result:
 *      animal
 * */