package us.mifeng.demo.kotlin.chapter2

import java.lang.IllegalArgumentException

interface Expr
class Num(val value:Int):Expr
class Sum(val left:Expr,val right:Expr):Expr

fun eval(e:Expr):Int{
    if (e is Num){
        val n=e as Num
        return n.value
    }
    if (e is Sum){
        return eval(e.left)+ eval(e.right);
    }
    throw IllegalArgumentException("unknown expression")
}

fun main() {
    println(eval(Sum((Sum(Num(1),Num(2))),Num(4))));
}