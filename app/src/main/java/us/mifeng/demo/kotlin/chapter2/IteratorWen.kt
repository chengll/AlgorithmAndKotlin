package us.mifeng.demo.kotlin.chapter2

fun recoginse(c: Char) = when (c) {
    in '0'..'9' -> "It's a digit"
    in 'a'..'z', in 'A'..'Z' -> "It's a letter"
    else -> "I don't know "
}

fun main(args: Array<String>) {
    println(recoginse('a'));
    println(recoginse('1'));
    println(recoginse('?'))
}
/*
*  result:
*    It's a letter
    It's a digit
    I don't know

* */