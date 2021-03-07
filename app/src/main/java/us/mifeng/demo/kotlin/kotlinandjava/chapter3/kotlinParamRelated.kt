package us.mifeng.demo.kotlin.kotlinandjava.chapter3

/**
 * kotlin中关于方法重载
 * kotlin中传入参数允许使用默认值，
 * */
fun main() {
    printInfo();
    printInfo("honeyll");
    printUserInfo("xixi");
}


fun printInfo(name: String = "honey"): String? {
    println("$name");
    return name;
}

fun printUserInfo(name:String)=println("$name");
/**
 * result:
 *      honey
        honeyll
 * */

