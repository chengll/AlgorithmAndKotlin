package us.mifeng.demo.kotlin

fun main() {
 fool();
}

fun fool(){
    listOf<Int>(1,2,3,4,5).forEach {
        if (it==3)return ;
        println(it);
    }
    println("this point is unreachable ");
}

