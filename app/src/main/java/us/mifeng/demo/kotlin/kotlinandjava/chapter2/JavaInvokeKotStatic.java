package us.mifeng.demo.kotlin.kotlinandjava.chapter2;
/**
 * java中调用kotlin 中静态的方法
 * kotlin 中通过object 中定义的方法
 * 且加了JvmStatic修饰的方法
 * */
public class JavaInvokeKotStatic {
/**
 * java中调用kotlin中静态的方法
 * 即 kotlin中通过object 声明且带有@JvmStatic 注解的方法
 * */
 public static void main(String[] args) {
     KotlinTest.sayMessage("java 调用kotlin的object 中声明的方法");
     KotlinTest.INSTANCE.printKotMsg(null);
     KotlinTest.printKotMsg("不用instance 的结果："+null);
 }
}
/**
 * result:
 *        来自kotlin 的静态方法的消息=java 调用kotlin的object 中声明的方法
 *        null
 *        不用instance 的结果：null
 * */