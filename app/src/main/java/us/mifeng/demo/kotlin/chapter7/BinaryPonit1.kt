package us.mifeng.demo.kotlin.chapter7

operator fun Point.times(scale: Double): Point {
    return Point((x * scale).toInt(), (y * scale).toInt());
}
fun main() {
    val p=Point(10,20);
    println(p *1.5);
}
/*
* result:
*       Point(x=15, y=30)
*
* */