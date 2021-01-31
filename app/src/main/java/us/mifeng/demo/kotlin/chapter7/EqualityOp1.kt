package us.mifeng.demo.kotlin.chapter7

class MyPoint(val x:Int,val y:Int){
    override fun equals(obj: Any?): Boolean {
        if(obj==this) return true;
        if(obj !is MyPoint) return false;
        return obj.x==x && obj.y==y;
    }
}

fun main() {
    println(MyPoint(10,10)== MyPoint(10,10));
    println(MyPoint(10,20)!= MyPoint(5,2));
    println(MyPoint(1,2)==null)
}
/*result:
*
* */