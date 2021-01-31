package us.mifeng.demo.kotlin.chapter7.mapoperator

import us.mifeng.demo.kotlin.chapter7.Point

fun printEnterprise(map:Map<String,String>){
    for((key,value) in map){
        println("$key --$value")
    }
}

fun main() {
    val map= mapOf("Oracle" to "Java","javaScipt" to "H5");
    printEnterprise(map);

    val p= Point(10,20)
    val(x,y)=p;
    //2.
    println("x= $x");
    println("y= $y");
}
//
/*
*  result:
*   Oracle --Java
    javaScipt --H5
    *
    *
    *2. x= 10
        y= 20
* */