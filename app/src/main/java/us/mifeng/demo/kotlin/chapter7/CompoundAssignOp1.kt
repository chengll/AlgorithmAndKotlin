package us.mifeng.demo.kotlin.chapter7

fun main() {
    val numbers=ArrayList<Int>();
    numbers+=42;
    println(numbers[0]);

    val list = arrayListOf(1,2);
    list+=3;
    val newList=list + listOf(4,5);
    println(list);
    println(newList);
}
/*
*result: 42
*       [1, 2, 3]
        [1, 2, 3, 4, 5]
*
* */