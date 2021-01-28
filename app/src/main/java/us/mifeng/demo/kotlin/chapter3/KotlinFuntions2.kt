package us.mifeng.demo.kotlin.chapter3

//通过对集合类Collection中增加扩展方法来实现KotlinFuntions1.kt中的功能
fun <T> Collection<T>.joinToString(separator:String=",",prefix:String="", postfix:String=""):String{
 val result=StringBuffer(prefix);
    for ( (index,element) in this.withIndex()){
        if (index>0) result.append(separator);
        result.append(element)
    }
    result.append(postfix);
    return result.toString();
}

fun main() {
    val list= listOf(1,2,4);
    println(list.joinToString(separator = ";",prefix = "(",postfix = ")"));
}
/*
*  result: (1;2;4)
* */