package us.mifeng.demo.kotlin.chapter5.commonfunction

import us.mifeng.demo.kotlin.chapter5.PersonalInfo

fun main() {
    val person= listOf(PersonalInfo("sgsg",23),
            PersonalInfo("eee",31),
            PersonalInfo("caroe",31));
    println(person.groupBy{ it.age; })

}
/*
 * result:
 *  {23=[PersonalInfo(name=sgsg, age=23)],
 *  31=[PersonalInfo(name=eee, age=31),
 * PersonalInfo(name=caroe, age=31)]}
 * */