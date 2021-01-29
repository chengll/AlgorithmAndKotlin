package us.mifeng.demo.kotlin.chapter5

data class UsesPerson(val name:String,val age:Int)

fun main() {
    val person= listOf(UsesPerson("honey",12), UsesPerson("ll",18));
    val names=person.joinToString(separator = " ",transform = {
        p:UsesPerson ->p.name;
    })
    println(names)
}
  /*
  result:
  honey ll
*/