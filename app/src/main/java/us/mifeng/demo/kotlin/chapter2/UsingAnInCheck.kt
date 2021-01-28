package us.mifeng.demo.kotlin.chapter2

fun isLetter(c:Char)=c in 'a'..'z' || c in 'A'..'Z'
fun isNotDigit(c:Char)=c in '0'..'9';
fun main() {
    println(isLetter('q'));
    println(isNotDigit('q'))
}
/*
* result:
*   true
    false
* */