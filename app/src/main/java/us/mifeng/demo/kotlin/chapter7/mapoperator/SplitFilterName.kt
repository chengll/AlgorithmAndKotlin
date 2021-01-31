package us.mifeng.demo.kotlin.chapter7.mapoperator

data class NameComponnets(val name:String,val extension:String)
fun splitFileName(fullName:String):NameComponnets{
    val result=fullName.split('.',limit=2);
    return NameComponnets(result[0],result[1]);
}

fun splitFileName2(fullName:String):NameComponnets{
    val(name1,ext1)=fullName.split('.',limit = 2);
    return NameComponnets(name1,ext1);
}

fun main() {
  val (name,ext)= splitFileName("example.kt");
    println( "name = $name ,ext=$ext");
    val (name1,ext1)= splitFileName2("example.kt");
    println("name1 =$name1 ,ext1= $ext1");
}
/*
*result:
*           name = example ,ext=kt
            name1 =example ,ext1= kt
* */