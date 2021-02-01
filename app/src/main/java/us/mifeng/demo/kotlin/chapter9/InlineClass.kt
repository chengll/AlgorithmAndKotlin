package us.mifeng.demo.kotlin.chapter9

inline fun<reified T > isA(value:Any)=value is T

fun printContents(list:List<Any>){
    println("printContents "+list.joinToString())
}
fun main() {
    println(isA<String>("agsgs"));
    println(isA<Int>(1232));

    val items= listOf("one",2,"three");
    println(items.filterIsInstance<String>())

    printContents(listOf("abv","bdv"));
}
/*
*result:
*       true
        true
         [one, three]
         * printContents abv, bdv
* */