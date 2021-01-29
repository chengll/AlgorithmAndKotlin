package us.mifeng.demo.kotlin.chapter5

fun printMsgWithPrefix(msg:Collection<String>,prefix:String){
    msg.forEach {
        println("$prefix $it")
    }
}

fun main() {
    val errors= listOf("403 Forbidden","404 not found")
    printMsgWithPrefix(errors,"ERROR");
}

/*
 result:
   ERROR 403 Forbidden
  ERROR 404 not found
* */