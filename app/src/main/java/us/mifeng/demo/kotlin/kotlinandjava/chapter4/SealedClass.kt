package us.mifeng.demo.kotlin.kotlinandjava.chapter4

import android.view.View

/**
 * kotlin-密封类
 * Sealed class 密闭类的最大的一个特点是更高级的一重枚举类型，可以扩展它的子类，并且
 * 它的子类也可以成为枚举的一个选项，
 * */

sealed class SuperCommand{
    object Up:SuperCommand();
    object DOWN:SuperCommand();
    object ENLARGE:SuperCommand();
    object ZOOMSCALE:SuperCommand();
    class PACE(var page:Int):SuperCommand()
}

fun exec(view : View,superCommand: SuperCommand)=when(superCommand){
    SuperCommand.Up->{
        println("正在模拟向上动画操作");
    }
    SuperCommand.DOWN->{
        println("正在模拟向下动画操作");
    }
    SuperCommand.ENLARGE->{
        println("正在模拟扩大的动画操作");
    }
    SuperCommand.ZOOMSCALE->{
        println("正在模拟缩小动画的操作");
    }
    is SuperCommand.PACE ->{
        println("我是密闭类扩展的子类");
    }
}