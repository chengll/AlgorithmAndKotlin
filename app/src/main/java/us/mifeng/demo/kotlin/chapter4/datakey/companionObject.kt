package us.mifeng.demo.kotlin.chapter4.datakey

class Acase{
    companion object{
        fun bar(){
            println("companion object called");
        }
    }
}

fun main() {
    Acase.bar();
}
/*
*result:
    companion object called

* */