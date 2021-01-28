package us.mifeng.demo.kotlin.chapter3

open class View1{
    open fun click()=println("view clicked");
}

class TextView:View1(){
    override fun click() = print("TextView clicked");
}

//分别给View1和TextView两个类添加一个扩展方法
fun View1.showOff()=println("I'm a view");
fun TextView.showOff()=println("I'm a button")

fun main() {
    val view:View1=TextView();
    view.click();
    view.showOff();
}
/*
*result:
*   TextView clicked
*    I'm a view
* */