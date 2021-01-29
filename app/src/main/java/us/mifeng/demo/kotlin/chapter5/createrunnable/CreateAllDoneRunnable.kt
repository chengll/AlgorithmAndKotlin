package us.mifeng.demo.kotlin.chapter5.createrunnable

fun createAllDoneRunnable():Runnable{
    return Runnable { println("All done") }
}

fun main() {
    createAllDoneRunnable().run()
}
/**
 *  result:  All done"
 * */