package us.mifeng.demo.kotlin.chapter10

import kotlin.reflect.full.declaredFunctions

class UserDTO
interface Api{
    fun getUsers():List<UserDTO>
}

abstract class SuperType<T>{
    val typeParameter by lazy{
        this::class.supertypes.first().arguments.first().type!!
    }
    val typeParameterJava  by lazy{
        //this.javaClass.genericSuperclass.safeAs<ParameterizedType>()!!.actualTypeArguments.first()
    }
}

class SubType: SuperType<String>()

data class Person(val id:Int,val name:String,val group: Group)
data class Group(val id:Int,val name:String,val location:String)

fun main() {
    Api::class.declaredFunctions.first{it.name=="getUsers"}.returnType.arguments
            .forEach { println(it); }
    var person= Person(0, "honey", Group(0, "kotlin", "china"));
}

