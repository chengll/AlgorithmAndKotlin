package us.mifeng.demo.kotlin.kotlinandjava.chapter3

/**
 *kotlin中函数的嵌套，类似内部类的形式
 * 内部函数可以直接使用外部函数的成员，这种情况一般是递归的场景使用
 * 外部无法调用该内部函数
 * */
fun main() {
    function();
   // say(); 但是外部类无法使用say()方法
}

fun function() {
    var str = "hell0";
    fun say(count: Int = 5) {
        println(str); //内部类可以直接使用外部类的成员str
        if (count > 0) {
            say(count - 1);
        }
    }
    say();
}
/**
 * result:
 *          hell0
            hell0
            hell0
            hell0
            hell0
            hell0
 * */