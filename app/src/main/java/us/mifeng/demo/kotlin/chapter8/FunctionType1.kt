package us.mifeng.demo.kotlin.chapter8

fun performRequest(url:String,callback:(code:Int,content:String) -> Unit){

}

fun main() {
    val url="http://kotl.in"
    performRequest(url){code, content -> {} }
    performRequest(url){code,page ->{}}
}