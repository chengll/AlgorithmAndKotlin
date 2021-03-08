package us.mifeng.demo.kotlin.kotlinandjava.kotjiegou

/**
 * 集合操作  类似rxJava中的 一些特殊字 map ,filter,find 等
 *
 * map是将传入的一种类型转变为另外一种元素输出
 * reduce :合并操作
 *案例：通过kotlin实现将两个数组的元素组合成一个wifi的密码输出
 * */
fun main() {
    val a = arrayOf<String>("4", "0", "7", "i", "f", "w", "0", "9");
    val index = arrayOf<Int>(5, 3, 9, 4, 8, 3, 1, 9, 2, 1, 7);
    index
            .filter { it < a.size } //过滤长度比数组长度大的数
            .map { a[it] }
            .reduce { s, s1 -> //合并
                "$s$s1";
            }
            .also {     //响应订阅事件
                println("密码是：$it")
            }
    myOperator();
}

//kotlin中自定义的集合操作符，模拟map将输入的参数转化为另外一种类型输出，是通过inline内敛函数实现的,将传入的T改为E
inline fun <T,E> Iterable<T>.convert(actioin: (T)->E):MutableList<E>{
  val list:MutableList<E> = mutableListOf();
    for (item :T in this ){
        list.add(actioin(item));
    }
    return list;
}

fun myOperator(){
    val list:List<Int> =listOf(1,2,3,4,5);
    list.convert {
        it+1;
    }.forEach{
        println(it);
    }
}

/**
 * result:
 *          密码是：wifi0709
 *          2
            3
            4
            5
            6

 *
*
* */