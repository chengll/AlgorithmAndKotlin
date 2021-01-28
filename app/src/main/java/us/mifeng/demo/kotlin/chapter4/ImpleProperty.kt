package us.mifeng.demo.kotlin.chapter4

fun getFackBookName(accountId:Int)="fb:$accountId"
interface  MyUser{
    val nickName:String;
}
class PrivateUser(override val nickName:String): MyUser

class SubscribingUser(val email:String): MyUser {
    override val nickName: String
        get() = email.substringBefore('@')

}

class FaceBookUser(val accountId:Int): MyUser {
    override val nickName= getFackBookName(accountId);
}

fun main() {
    println(PrivateUser("test@kotlin.com").nickName);
    println(SubscribingUser("test@kotlin.com").nickName)
}
/*
*  result:
*   test@kotlin.com
    test
*
* */
