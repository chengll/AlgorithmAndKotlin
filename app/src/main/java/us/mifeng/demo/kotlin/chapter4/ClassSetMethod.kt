package us.mifeng.demo.kotlin.chapter4

class MyUsers(val name:String){
    var address:String="unspecific"
    set(value:String){
        println("""
            Address was changed for $name:"$field"->"$value"
        """.trimIndent())
        field=value
    }

}

fun main() {
    val user= MyUsers("haha")
    user.address="Elsenheimerstrasse 47,80687 Menucheng"
}
/*
* result:
* Address was changed for haha:"unspecific"->"Elsenheimerstrasse 47,80687 Menucheng"
*
* */