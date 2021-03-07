package us.mifeng.demo.kotlin.kotlinandjava.kotjiegou

/**
 * kotlin中的循环
 * */
fun main() {
    println("****第一种循环******")
     for(i in 1..4){
         println(i);
     }
    println("****第二种循环******")
    for (i in 1 until  4){
        println(i);
    }
    println("******第三种循环******");
    for (i in 6 downTo 1){
        println(i);
    }
    println("******第四种循环******");
    for (i in 1..6 step 2){
        println(i);
    }
    println("******第五种循环******");
    repeat(4){
        println(it);
    }
}

 /**
  * result:
          ****第一种循环******
         1
         2
         3
         4
          ****第二种循环******
         1
         2
         3
          ******第三种循环******
         6
         5
         4
         3
         2
         1
          ******第四种循环******
         1
         3
         5
          ******第五种循环******
         0
         1
         2
         3

  * */