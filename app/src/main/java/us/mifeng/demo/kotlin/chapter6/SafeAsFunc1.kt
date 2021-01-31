package us.mifeng.demo.kotlin.chapter6

class UserPersonInfo(val firstName:String,val lastName:String){
    override fun equals(other: Any?): Boolean {
        val person=other as? UserPersonInfo?:return false
        return person.firstName==firstName && person.lastName==lastName
    }

    override fun hashCode(): Int =firstName.hashCode() *37 +    lastName.hashCode()
}

fun main() {
    val person=UserPersonInfo("Dormitory","Jemover");
     val person2=UserPersonInfo("Dormitory","Jemover");
    println(person==person2)
    println(person.equals(person2))
    println(person.equals(42))
}

/*
*  result:
*   true
    true
    false
* */