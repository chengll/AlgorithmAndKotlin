package us.mifeng.demo.kotlin.chapter3.userInfobject

interface Clickable{
    fun click();
}
class Button :Clickable{
    override fun click() {
        println(" I'm clicked")
    }
}

fun main() {
    Button().click();
}
/* result:
   I'm clicked
* */