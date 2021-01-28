package us.mifeng.demo.kotlin.chapter3

//通过正则表达式来划分路径中的路径和文件名和
fun parseDirtory(path: String) {
    val regex = """(.+)/(.+)\.(.+)""".toRegex();
    val matchResult = regex.matchEntire(path);
    if (matchResult != null) {
        val (directory, fileName, extension) = matchResult.destructured;
        println("Dir:$directory,fileName:$fileName,ext:$extension");
    }
}

fun main() {
    parseDirtory("/Users/yole/kotlin-book/chapter.doc");
}