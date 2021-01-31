package us.mifeng.demo.kotlin.chapter6

import java.io.BufferedReader
import java.io.StringReader

fun readNumber(reader:BufferedReader):List<Int?>{
    val result=ArrayList<Int?>();
    for(line in reader.lineSequence()){
        try {
            val number=line.toInt();
            result.add(number);
        } catch (e: Exception) {
            result.add(null)
        }

    }
    return result;
}

fun addValidateNumbers(numbers:List<Int?>){
    var sumOfValidNumber=0;
     var invalidNumber=0;
    var i:Int?=0;
    if(i in numbers){
        if(i!=null){
            sumOfValidNumber+=i;
        }else{
            invalidNumber++;
        }
    }
  println("sum of valid numbers: ${sumOfValidNumber}")
    println("invalid numners: $invalidNumber")
}

fun main() {
    var reader=BufferedReader(StringReader("1\nbc\n42"))
    val numbers= readNumber(reader);
    addValidateNumbers(numbers);
}
/*
* result:
*  sum of valid numbers: 0
    invalid numners: 0
* */