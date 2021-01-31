package us.mifeng.demo.kotlin.chapter6

fun sendEmail(emial:String){
    println("sending email to $emial")
}

fun main() {
    var email:String?="lingling@qq.com"
    email?.let { sendEmail(it) }
    email=null;
    email?.let { sendEmail(it) }
}
/*
*  result:
*       sending email to lingling@qq.com
* */