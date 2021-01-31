package us.mifeng.demo.kotlin.chapter7.mapoperator

import us.mifeng.demo.kotlin.chapter7.DataPerson

class PersonMap{
    private val _attributes = hashMapOf<String,String>();
    fun setAttribute(attributeName:String,value:String){
        _attributes[attributeName]=value;
    }
    val name :String by _attributes;
}

fun main() {
    val p=DataPerson();
    val data=mapOf("name" to "Lucy","company" to "Google")
    for((attributeName,value) in data){
        p.setAttributes(attributeName,value)
    }
    println(p.name);
}

/*
* result:
*       Lucy
* */