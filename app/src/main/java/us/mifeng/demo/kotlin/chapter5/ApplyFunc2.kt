package us.mifeng.demo.kotlin.chapter5

fun alphbeta2()= buildString {
    for(letter in 'A'..'Z'){
        append(letter);
    }
    append("\n Now I know the alphabet!")
}

fun main() {
    println(alphabet2())

}
/*
* result:
*       ABCDEFGHIJKLMNOPQRSTUVWXYZ
        now  I know  the alphabet!
* */