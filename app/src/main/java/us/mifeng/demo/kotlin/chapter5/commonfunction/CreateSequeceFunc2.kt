package us.mifeng.demo.kotlin.chapter5.commonfunction

import java.io.File

fun File.isInsideHiddenDirectory()= generateSequence(this) {it.parentFile  }.any{it.isHidden}
fun main() {
    val file=File("/Users/sktv/.HiddenDir/a.txt")
    println(file.isInsideHiddenDirectory());
}

/*
*  result: true
* */