package us.mifeng.demo.kotlin.chapter4.datakey

data class MyPerson(val name:String){
    object NameComparators:Comparator<MyPerson>{
        override fun compare(p0: MyPerson, p1: MyPerson): Int {
          return  p1.name.compareTo(p1.name)
        }
    }
}

fun main() {
    val persons= listOf<MyPerson>(MyPerson("honey"), MyPerson("xixi"))
    println(persons.sortedWith(MyPerson.NameComparators))
}
/*
* result:  [MyPerson(name=honey), MyPerson(name=xixi)]
* */