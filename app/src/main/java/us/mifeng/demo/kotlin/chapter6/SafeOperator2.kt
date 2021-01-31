package us.mifeng.demo.kotlin.chapter6

class Employee(val name:String,val manager:Employee?)
fun managerName(employee:Employee):String?=employee.manager?.name

fun main() {
    val ceo=Employee("Da boss",null)
    val developer=Employee("Lingling",ceo)
    println(managerName(ceo))
    println(managerName(developer))

}
/*
*  result:
*       null
        Da boss
*
* */