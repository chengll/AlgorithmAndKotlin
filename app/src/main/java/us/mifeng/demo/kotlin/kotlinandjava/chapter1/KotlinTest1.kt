package us.mifeng.demo.kotlin.kotlinandjava.chapter1

import us.mifeng.demo.kotlin.kotlinandjava.chapter1.AClass.formatstr

/**
 * kotlin中没有包装类 可以看到kotlin 只能调用java的基本类型的方法，即int，不能调用参数类型为Integer 的方法
 *
 * 注意：如果kotlin要调用java中的包装类，就得使用反射的方式
 *
 * String？ 可以为空的类型
 * String! 不为空的类型
 * */
fun main() {
    AClass.aClass.printNum(123);  // int
    KotlinTest2().printNum(1234)  //kotlin只能实现参数类型为基本类型的方法
    KotlinTest2().systemNum(0);//kotlin会自动将java 的包装类改为基本类型 Integer改为 int?
    invokeFun("");                // resuilt:null
}
fun invokeFun(str:String){
    val formatstr = formatstr(str);
    /**
     * println(formatstr.length);这句会报空指针异常，因为format 为null
     * 因此为了保证不报错，要使用空安全策略 即formatstr?.length 这种就不会报错
     * */
   println(formatstr?.length);
   // val fm2:String=formatstr(str); 这句会报错，因为是null导致的 为了保险期间 还是要使用空安全措施
    val fm3:String?=formatstr(str);

}
//result:
/**
 int
 kotlin只能实现参数类型为基本类型的方法
 kotlin会自动将java 的包装类改为基本类型 Integer改为 int?
*/

