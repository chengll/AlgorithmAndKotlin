package us.mifeng.demo.kotlin.chapter9

fun main() {
    val letters=('a'..'z').toList();
    println(letters.slice<Char>(0..2));
    println(letters.slice(10..13))
}
/*
* result:
*       [a, b, c]
        [k, l, m, n]
* */