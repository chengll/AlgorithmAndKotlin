package us.mifeng.demo.kotlin.chapter3

fun main() {
    val string = listOf("first", "second", "three");
    println("输出集合中的最后一个元素" + string.last())
    val number = setOf(1, 3, 5);
    println("输出一组数中的最大值：" + number.max());
}

/*
result:
        输出集合中的最后一个元素three
        输出一组数中的最大值：5
* */