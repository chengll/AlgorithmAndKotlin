package us.mifeng.demo.kotlin.chapter4.stringrelative

class AndroidClient(val name:String,val postCode:Int){
    override fun equals(other: Any?): Boolean {
        if (other==null || other !is AndroidClient){
            return false;
        }
        return name==other.name &&postCode==other.postCode;
    }

    override fun toString()="AndroidClient(name=$name,postCode=$postCode)"
}

fun main() {
    val processed= hashSetOf(AndroidClient("honeyLl",123));
    println(processed.contains(AndroidClient("honeyLl",123)));
}
/*
* result:  false
* */