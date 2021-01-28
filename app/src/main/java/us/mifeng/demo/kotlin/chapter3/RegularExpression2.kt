package us.mifeng.demo.kotlin.chapter3

val kotlinLogo=""" | //
                   .| //
                   .|/ \""";
fun main() {
    println(kotlinLogo.trimMargin("."))
}
/*
* result:
*        | //
        | //
        |/ \
* */