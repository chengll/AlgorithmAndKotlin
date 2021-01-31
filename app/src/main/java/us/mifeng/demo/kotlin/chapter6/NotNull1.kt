package us.mifeng.demo.kotlin.chapter6

fun ignoreNulls(s:String?){
    val sNotNull:String=s!!;
    println(sNotNull.length)
}

fun main() {
    ignoreNulls(null)
    ignoreNulls("hh")
}

/*
*  result:
*   Exception in thread "main" java.lang.NullPointerException
*
* */