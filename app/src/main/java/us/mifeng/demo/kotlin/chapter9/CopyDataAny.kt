package us.mifeng.demo.kotlin.chapter9

fun <T:R,R> copyData(source:MutableList<T>,destination:MutableList<T>){
    for (item in source){
        destination.add(item);
    }
}

fun  printFirst(list:List<String>){
    if(list.isNotEmpty()){
        println(list.first())
    }
}
fun main() {
    val list= mutableListOf<Any>(1,2,3);
    val anyItems= mutableListOf<Any>();
    copyData(list,anyItems);
    println(anyItems);
    //3

    printFirst(listOf("Seven","Dimitory"))

}
/*
*  result:
*       [1, 2, 3]
*       Seven
*
* */