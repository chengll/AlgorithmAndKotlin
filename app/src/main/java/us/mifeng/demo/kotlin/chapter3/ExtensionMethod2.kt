package us.mifeng.demo.kotlin.chapter3

open class View{
    open fun click()= print("View is click");
}

class Button:View(){
    override fun click() = println("button is clicked")
}

fun main() {
    val view:View=Button();
   view.click();
}
/*
* result:
*  button is clicked
* */