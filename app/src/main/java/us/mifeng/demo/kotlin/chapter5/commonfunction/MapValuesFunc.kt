package us.mifeng.demo.kotlin.chapter5.commonfunction

fun main() {
    val numbers= mapOf(0 to "Zero",1 to "one" );
    print(numbers.mapValues{it.value.toUpperCase()})
}
/*
*  result:
*   {0=ZERO, 1=ONE}
* */