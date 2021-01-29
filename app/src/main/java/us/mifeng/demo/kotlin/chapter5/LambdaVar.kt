package us.mifeng.demo.kotlin.chapter5

fun printProblemCounts(response:Collection<String>){
    var clientError=0;
    var serverError=0;
    response.forEach {
        if (it.startsWith("4")){
            clientError ++;
        }else if (it.startsWith("5")){
            serverError++;
        }
    }
    println("$clientError client errors,$serverError server Error")
}
fun main() {
    val response= listOf("200 Ok","418 I'm not a teapot","505 Internal Server Error");
    printProblemCounts(response);
}
/*
*  result:
* 1 client errors,1 server Error
* */