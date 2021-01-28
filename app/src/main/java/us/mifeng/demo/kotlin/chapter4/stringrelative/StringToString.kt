package us.mifeng.demo.kotlin.chapter4.stringrelative

class Client(val name:String,val postCode:Int){
    override fun toString()="Client(name=$name,postCode=$postCode)"
}

fun main() {
    val client = Client("Alice", 232);
    println(client.toString());
}

/*
*  result:
* Client(name=Alice,postCode=232)
* */
