package us.mifeng.demo.kotlin.chapter2

//枚举类初始化颜色值，然后生成rgb三原色
enum class ColorList(val r:Int,val g:Int,val b:Int ){
    RED(255,0,0),ORANGE(255,165,0),
    YELLOW(255,255,0),GREEN(0,255,0),
    BLUE(0,255,0),INDIGO(70,0,130),
    VTOLET(238,140,234);
    fun rgb()=(r*256 +g)*256 +b;
}

fun main() {
    println(ColorList.BLUE.rgb())
}
//result: 65280