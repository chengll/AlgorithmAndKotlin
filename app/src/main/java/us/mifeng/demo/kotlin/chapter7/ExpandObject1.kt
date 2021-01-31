package us.mifeng.demo.kotlin.chapter7

class DataPerson {
    private val _attributes = hashMapOf<String, String>();
    fun setAttributes(attribute: String, value: String) {
        _attributes[attribute] = value;
    }

    val name: String
        get() = _attributes["name"]!!;
}

fun main() {
    val p=DataPerson();
    val data= mapOf("name" to "honey","company" to "JetBrains");
    for((attribute,value) in data){
        p.setAttributes(attribute,value);
    }
    println(p.name);
}
/*
*  result:honey
* */