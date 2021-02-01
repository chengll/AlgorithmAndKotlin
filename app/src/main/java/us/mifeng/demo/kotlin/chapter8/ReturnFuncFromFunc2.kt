package us.mifeng.demo.kotlin.chapter8

data class Person(val firstName: String, val lastName: String, val phone: String?)
class ContactListFilters {
    var prefix: String = ""
    var onlyWithPhoneNumber: Boolean = false;
    fun getPredicte(): (Person) -> Boolean {
        val startWithPrefix = { p: Person ->
            p.firstName.startsWith(prefix) || p.lastName.startsWith(prefix);
        }
        if (!onlyWithPhoneNumber) {
            return startWithPrefix;
        }
        return { startWithPrefix(it) && it.phone != null }
    }
}

fun main() {
    val contacts= listOf(Person("Dmity","Smith","123-456"),
            Person("Stevent","Dejil",null))
    val contactFilter=ContactListFilters();
    with(contactFilter){
        prefix = "Dm"
        onlyWithPhoneNumber = true
    }
    println(contacts.filter(contactFilter.getPredicte()))
}
/*
* result:
*   [Person(firstName=Dmity, lastName=Smith, phone=123-456)]
*
* */