package us.mifeng.demo.kotlin.kotlinandjava.chapter4

/**
 * kotlin的伴生对象 companion，类似java的static ,也可以通过它来写单例
 * */
class StringUtils{
    companion object{
        fun isEmpty(str:String):Boolean{
            return str==null;
        }
    }
}

fun main() {
    val empty = StringUtils.isEmpty("");
    print(empty);
}
//resullt: false