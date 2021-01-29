package us.mifeng.demo.kotlin.chapter5

data class  PersonalInfo(val name:String,val age:Int);
fun main() {
    val createPerson=::PersonalInfo;
    val p=createPerson("honeyLL",18);
    println(p);
}
/*
*  result:
        PersonalInfo(name=honeyLL, age=18)
* */