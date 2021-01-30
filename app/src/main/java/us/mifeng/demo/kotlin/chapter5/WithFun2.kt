package us.mifeng.demo.kotlin.chapter5

fun alphabet()=with(StringBuilder()){
    for(letter in 'A' .. 'Z'){
        append(letter);
    }
    append("\n now I know the alphabet");
    toString()
}

fun main() {
    println(alphabet())

}
/*
* result:
*   ABCDEFGHIJKLMNOPQRSTUVWXYZ
    now I know the alphabet
*
* */