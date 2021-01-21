package us.mifeng.demo.kotlin.chapter2

import java.util.*

fun main(args:Array<String>){
    val binaryRes=TreeMap<Char,String>();
    for (c in 'A'..'F'){
        val binary=Integer.toBinaryString(c.toInt());
        binaryRes[c]=binary;
    }
    for ((letter,binary) in binaryRes){
        println("$letter= $binary");
    }
}

/*
* result:
    A= 1000001
    B= 1000010
    C= 1000011
    D= 1000100
    E= 1000101
    F= 1000110
* */