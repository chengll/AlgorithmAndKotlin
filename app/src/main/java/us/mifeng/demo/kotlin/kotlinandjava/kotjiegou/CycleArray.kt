package us.mifeng.demo.kotlin.kotlinandjava.kotjiegou

/**
 * 数组的循环输出元素
 * */
fun main() {
    val list= arrayListOf<String>("g","o","o","d");
    println("arrayList的第一种遍历")
    for(str in list){
        println(str);
    }
    println("arrayList的第2种遍历--结构的形式")
    for((index ,str) in list.withIndex()){
        println("第$index 个元素是 $str");
    }

}
/**
 * result:
 *      arrayList的第一种遍历
        g
        o
        o
        d
        arrayList的第2种遍历--结构的形式
        第0 个元素是 g
        第1 个元素是 o
        第2 个元素是 o
        第3 个元素是 d

 * */