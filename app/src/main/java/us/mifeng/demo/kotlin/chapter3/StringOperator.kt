package us.mifeng.demo.kotlin.chapter3

fun parsePath(path:String){
    val directory=path.substringBeforeLast("/");
    val fullName=path.substringAfterLast("/");
    val fileName=fullName.substringBeforeLast(".");
    val extension=fullName.substringAfterLast(".");
    println("Dir:$directory,name: $fileName,ext:$extension");
}

fun main() {
    parsePath("/Users/yole/kotlin-book/chapter.doc");
}
/*
  result:
    Dir:/Users/yole/kotlin-book,
    name: chapter,
    ext:doc
* */