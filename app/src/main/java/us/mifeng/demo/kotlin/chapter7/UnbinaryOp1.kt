package us.mifeng.demo.kotlin.chapter7

operator  fun Point.unaryMinus():Point{
    return Point(-x,-y);
}
fun main() {
 val p1=Point(10,20);
    print(-p1)
}

/*
* result:
* Point(x=-10, y=-20)
*
* */