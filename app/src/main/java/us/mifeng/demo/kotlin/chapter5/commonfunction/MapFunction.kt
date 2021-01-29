package us.mifeng.demo.kotlin.chapter5.commonfunction

fun main() {
    val list= listOf(1,2,3,4);
    println(list.map { it * it })
}

/*
* result:
        [1, 4, 9, 16]
* */