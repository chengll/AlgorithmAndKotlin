package us.mifeng.demo.kotlin.chapter5.withasyn

import java.lang.StringBuilder

fun alphabet():String{
    val stringBuilder=StringBuilder();
    return with(stringBuilder){
        for (letter in 'A'..'Z'){
            this.append(letter)
        }
        println("/now I know the alphabet");
        this.toString()
    }
}

fun main() {
    println(alphabet());
}

/*
        result: ABCDEFGHIJKLMNOPQRSTUVWXYZ
* */