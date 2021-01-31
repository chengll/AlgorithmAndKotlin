package us.mifeng.demo.kotlin.chapter6

fun<T> printHashCode(t:T){
    println(t?.hashCode());
}

fun main() {
    printHashCode(null);
}

/*
    result:
*       null

* */