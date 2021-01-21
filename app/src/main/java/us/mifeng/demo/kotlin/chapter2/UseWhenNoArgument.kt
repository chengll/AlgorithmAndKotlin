package us.mifeng.demo.kotlin.chapter2

import java.lang.Exception

//使用when语句输出
fun mixOption(c1:Color,c2:Color)=when{
    (c1==Color.RED  && c2==Color.YELLOW) || (c1==Color.YELLOW && c2==Color.RED) ->Color.ORAGNE
    (c1==Color.YELLOW && c2==Color.BLUE) || (c1==Color.BLUE && c2==Color.YELLOW)->Color.GREEN
    else->throw Exception("Dirty color")

}
fun main() {
 println(mixOption(Color.YELLOW,Color.BLUE));
}

// result : GREEN