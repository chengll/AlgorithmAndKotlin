package us.mifeng.demo.kotlin.chapter7

class MyPersonal(val firstName:String,val lastName:String):Comparable<MyPersonal>{
    override fun compareTo(other: MyPersonal): Int {
        return compareValuesBy(this,other,MyPersonal::lastName,MyPersonal::firstName);
    }
}

fun main() {
    val p1=MyPersonal("Alice","Smith");
    val p2=MyPersonal("Bob","Json");
    println(p1 < p2)
    println("abc" <"bac");
}
/*
* result:
*   false
*   true
*
* */