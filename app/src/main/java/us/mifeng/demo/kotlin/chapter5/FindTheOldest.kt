package us.mifeng.demo.kotlin.chapter5

data class People(val name: String, val age: Int)

fun findTheOldest(people: List<People>) {
    var maxAge = 0;
    var theOldest: People? = null;
    for (person in people) {
        if (person.age > maxAge) {
            maxAge = person.age;
            theOldest = person;
        }
    }
    println(theOldest)
}

fun main() {
    val people = listOf(People("Alice", 23), People("honey", 12));
    findTheOldest(people);
}
/*
* result:
* People(name=Alice, age=23)
* */