package us.mifeng.demo.kotlin.chapter3.userInfobject
interface Clicked {
    fun click();
    fun showOff() = println("I'm clickable")
}
interface Focusable {
    fun setFocus(b: Boolean) = println(" I ${if (b) "got" else "lost"}focus.");
    fun showOff() = println("I'm focusable ")
}

class Buttons : Clicked, Focusable {
    override fun click() {
        println("I was clickable");
    }

    override fun showOff() {
        super<Clicked>.showOff()
        super<Focusable>.showOff()
    }
}

fun main() {
 val button=Buttons();
    button.showOff();
    button.setFocus(true);
    button.click();
}

/*
 result:
           I'm clickable
          I'm focusable
         I gotfocus.
        I was clickable
* */