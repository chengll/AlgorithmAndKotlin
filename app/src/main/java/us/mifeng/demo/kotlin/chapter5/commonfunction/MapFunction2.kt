package us.mifeng.demo.kotlin.chapter5.commonfunction

import us.mifeng.demo.kotlin.chapter4.datakey.MyPerson
import us.mifeng.demo.kotlin.chapter5.PersonalInfo

fun main() {
    val person= listOf<PersonalInfo>(PersonalInfo("haha",12), PersonalInfo("tete",19));
    println(person.map { it.name })
}
/*
*  result:
* [haha, tete]
* */