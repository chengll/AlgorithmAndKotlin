package us.mifeng.demo.kotlin.chapter5.commonfunction

import us.mifeng.demo.kotlin.chapter5.PersonalInfo

val canBeInClub27={p:PersonalInfo ->p.age <=25}
fun main() {
    val people=listOf(PersonalInfo("hhh",32),PersonalInfo("hj",12));
    println(people.all(canBeInClub27))

    val listNum= listOf(1,2,4);
    println(listNum.all { it==3 });

    println(listNum.all { it !=3 });
}

/**
 * result:
 *   false
 *   false
     true
 * */