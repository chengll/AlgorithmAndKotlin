package us.mifeng.demo.kotlin.chapter4

class LenthCounter{
    var counter:Int=0
    private set

    fun addWord(word:String){
        counter+=word.length;
    }
}

fun main() {
    val lenthCounter= LenthCounter();
    lenthCounter.addWord("Hi!");
    println(lenthCounter.counter);
}

/*
* result: 3
*
* */