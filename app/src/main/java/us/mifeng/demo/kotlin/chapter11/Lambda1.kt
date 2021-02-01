package us.mifeng.demo.kotlin.chapter11

fun buildString(buildAction:(StringBuilder) ->Unit):String{
    val sb=StringBuilder();
    buildAction(sb);
    return sb.toString()
}
fun main() {
    val s= buildString {
        it.append("Hello ")
        it.append("World")
    }
    println(s);

}
/*
* result:  Hello World
* */