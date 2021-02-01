package us.mifeng.demo.kotlin.chapter8

import java.io.BufferedReader
import java.io.FileReader

data class  Persons(val name:String,val age:Int)
val people= listOf(Persons("honey",12),Persons("child",31))


fun readFirstLineFromFile(path:String):String{
    BufferedReader(FileReader(path)).use { br->
        return br.readLine();
    }
}

fun lookForAlice(people:List<Persons>){
    for(person in people){
        if(person.name.equals("Alice")){
            println("Found");
            return;
        }
    }
    println("Alice is not found");
}

fun lookForAlice2(people:List<Persons>){
    people.forEach label@{
        if (it.name=="Alice"){
            println("Alice found");
            return@label;
        }
    }
}

fun lookForAlice3(person :List<Persons>){
    person.forEach{
        if(it.name=="Alice") {
            println("Alice is here")
            return@forEach
        }
    }
}

fun lookForAlice4(person:List<Persons>){
    person.forEach(fun(person){
        if(person.name=="Alice"){
            println("Alice is working now")
            return ;
        }
        println("${person.name}is not Alice")
    })
}

fun main() {
    println(people.filter { it.age >30 }
            .map (Persons::name))

    val people = listOf(Persons("Alice", 29), Persons("Bob", 31))
    println(lookForAlice(people));
    println(lookForAlice2(people));
    println(lookForAlice3(people));
    println(lookForAlice4(people));
}
/*
* result:
*       [child]
*
*       Found;
*
*       Alice found
*
*       Alice is here
*
*       Alice is working now
        Bobis not Alice
        kotlin.Unit
* */