package us.mifeng.demo.kotlin.chapter5.commonfunction

import us.mifeng.demo.kotlin.chapter5.PersonalInfo

val canBe27={p:PersonalInfo ->p.age<27}
fun main() {
    val listPerson= listOf(PersonalInfo("wew",23), PersonalInfo("ewe",32))
    println(listPerson.find(canBe27))
}
/*
*  result:
*           PersonalInfo(name=wew, age=23)
* */