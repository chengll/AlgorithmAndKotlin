package us.mifeng.demo.kotlin.chapter6

fun fail(message: String): Nothing {
    throw IllegalAccessException(message);
}

fun main() {
    fail("Error occour")
}
/*
* result:    Exception in thread "main" java.lang.IllegalAccessException: Error occour
*
* */