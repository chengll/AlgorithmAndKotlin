package us.mifeng.demo.kotlin.chapter4.stringrelative

class UserClient(val name:String,val postCode:Int)

fun main() {
    val user1=UserClient("honey",12)
    val user2=UserClient("lingling",3);
    println(user1==user2);
}
/*
* result:
        false
* */