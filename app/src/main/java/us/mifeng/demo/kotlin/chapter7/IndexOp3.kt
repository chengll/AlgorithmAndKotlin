package us.mifeng.demo.kotlin.chapter7

data class  Point3(val x:Int,val y:Int);
data class Rectangle(val upperPoint:Point3,val lowPonit:Point3)
operator fun Rectangle.contains(p:Point3):Boolean{
    return  p.x in upperPoint.x until lowPonit.x &&
            p.y in upperPoint.y until lowPonit.y
}
fun main() {
    val rect=Rectangle(Point3(10,20), Point3(20,20))
    println(Point3(20,30) in rect)
    println(Point3(5,5) in rect)

    val rect1= Rectangle(Point3(10, 20), Point3(50, 50))
    println(Point3(20, 30) in rect1)
}
/*
* result:
*   false
*   false
*   true
*
* */