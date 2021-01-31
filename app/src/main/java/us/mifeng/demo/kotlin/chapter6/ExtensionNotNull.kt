package us.mifeng.demo.kotlin.chapter6

fun verifyInput(input:String?){
    if(input.isNullOrBlank()){
        println("please fill in the required fields");
    }
}

fun main() {
    verifyInput("")
    verifyInput(null);
}
/*
*  result:
*       please fill in the required fields
        please fill in the required fields
* */