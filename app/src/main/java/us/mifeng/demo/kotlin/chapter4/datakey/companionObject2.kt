package us.mifeng.demo.kotlin.chapter4.datakey


fun getFaceBookName(accountId:Int)="fb:$accountId";
class FaceUser private constructor(val name:String){
    companion object{
        fun newSubscribingUser(email:String)=FaceUser(email.substringBefore('@'));
        fun newFaceBookUser(accountId:Int)=FaceUser(getFaceBookName(accountId));
    }
}

fun main() {
    val subscribingUser=FaceUser.newSubscribingUser("Lingling@gmail.com");
    val faceBookUser=FaceUser.newFaceBookUser(4);
    println(subscribingUser.name);
}
/*
* result: Lingling
*
* */