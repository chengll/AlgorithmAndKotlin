package us.mifeng.demo.kotlin.kotlinandjava.chapter2

/**
 * kotlin中没有静态变量和静态方法
 *
 * 但是为了能够让kotlin 中方法也可以被java 使用
 * 第一点：在该方法上加上JvmStatic
 * 第二点：在kotlin中通过object 来实现
 * */
fun main() {
    KotlinTest.sayMessage("Hello");  //来自kotlin 的静态方法的消息=Hello
    val age=18;
    val name="张三";
   // println("我叫%d,我今年 %d",name,age);
}
object  KotlinTest{
    @JvmStatic
    fun sayMessage(msg:String){
        println("来自kotlin 的静态方法的消息="+msg);
    }
    @JvmStatic
    fun printKotMsg(msg:String?){
        println("$msg");
    }
}