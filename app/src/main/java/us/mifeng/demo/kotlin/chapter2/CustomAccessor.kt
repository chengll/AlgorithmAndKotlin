package us.mifeng.demo.kotlin.chapter2

import kotlin.random.Random

//判断该矩形是不是正方形
class Rectangle(val height:Int,val width:Int){
    val isSquare:Boolean
    get() {
        return height==width;
    }
}
//通过随机数来控制矩形是否是正方形
fun createRectangle():Rectangle{
    val random= java.util.Random();
    return Rectangle(random.nextInt(),random.nextInt());
}
fun main() {
    val rectangle=Rectangle(41,43);
    println(rectangle.isSquare);
    val rectangle2=Rectangle(41,41);
    println(rectangle2.isSquare);
   println("通过随机数创建矩形："+ createRectangle().isSquare)
}

/*
* result：
*   false
    true
    通过随机数创建矩形：false
*
* */