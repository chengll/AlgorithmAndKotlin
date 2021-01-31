package us.mifeng.demo.kotlin.chapter6.parry

fun main(args:Array<String>) {
    val letters =Array<String>(26){
        i->('a'+i).toString()
    }
    println(letters.joinToString(""))
}
/*
* result:
*       abcdefghijklmnopqrstuvwxyz
* */