package us.mifeng.demo.kotlin.kotlinandjava.kotjiegou

import us.mifeng.demo.javareflect.User

/**
 *
 * kotlin作用域函数大致有以下几种
 *  let{}
 *  run {}
 *  with{}
 *  apply{}
 *  also{}
 *  类似于结合的操作函数map,filter ,reduce等，但是集合的操作函数只作用于集合 ，
 *  但是以上的这些作用域函数作用于任何函数
 *
 * */
fun main() {
    val user = User("honeyll", 12, 18);
    /**
     * 注意run 和let 都会返回闭包的结果，区别是let 有闭包参数，而run没有闭包参数
     * let 的参数是谁调用了let ,这个参数就是谁，比如user 调用了let,所以let 的第一个参数就是user
     * */
    val resultLet = user.let { user: User -> "let::${user.javaClass}" }
    //注意：kotlin 中lambda的特性,如果只有一个参数时，可以省略参数，用it来指代它，因此上面的let可以等价为
    var resultLetAn = user.let { "let::${it.javaClass}" }
    println(resultLetAn)
    println(resultLet);
    //由于run 是没有参数的，因此调用对象是this
    val resultRun = user.run { "run::${this.javaClass}" }
    println(resultRun);

    println("*****also{} 和 apply{}******")
    /**
     * 注意：also和apply都不返回闭包执行的结果，区别在于also 有闭包参数， apply 没有闭包参数
     *     由于这两个作用域函数不返回结果，因此可以一直链式调用到某个具体的属性，
     *     also{}与 apply{}类似于 let于run的使用
     *     请看案例
     *     user.also {user:User->
            println("also::${user.javaClass}");
            }
        这种也可以简化为以下的方式：有一个参数省略的形式
     * */
    user.also {
        println("also::${it.javaClass}");
    }.apply {
        println("apply:${this.javaClass}")
    }.name="honeyLl";

    println("********takeIf{} 与takeUnless{}********")
    println("takeIf的闭包返回一个判断结果，为false 时，takeIf结果返回一个空，如果为true，则返回一个执行表达式的值，" +
            "因此在做takeIf调用时，我们总是加一个非空（？）的判断,根据返回值做响应的结果，但是 takeUnless它与takeif相反，即如果" +
            "takeUnless的闭包结果返回false,则返回闭包执行的结果，如果它的闭包结果为ture，返回空，请看以下案例")

    user.takeIf { it.name.length>0 }?.also { println("姓名为：${it.name}") }?:println("返回的结果是空的")
    user.takeUnless { it.name.length>0 }?.also { println("返回的姓名结果是空的") }?:println("姓名为：${user.name}")

    println("*********repeat**********")
    repeat(3){
        println(user.getName());
        println(it);
    }

    println("**********with是一种特殊的作用域函数************")
    /**
     * with比较特殊，不是以扩展方法的形式存在的，而是一个顶级函数，但是以上的作用域函数都是通过扩展函数来实现，
     * with 去操作一个对象，之后对该对象的操作，是一个闭包，lambda，通过调用receive的一个函数的调用
     * */
    with(user){
        this.name="new good";
    }
    //以上相当于 user.apply { this.name="new good" }  其他的常用操作符，请查看drawable/kotcommonop.jpg


}
/**
 * result:
 *      let::class us.mifeng.demo.javareflect.User
        let::class us.mifeng.demo.javareflect.User
        run::class us.mifeng.demo.javareflect.User

         *****also{} 和 apply{}******
        also::class us.mifeng.demo.javareflect.User
        apply:class us.mifeng.demo.javareflect.User

         ********takeIf{} 与takeUnless{}********
        takeIf的闭包返回一个判断结果，为false 时，takeIf结果返回一个空，
        如果为true，则返回一个执行表达式的值，因此在做takeIf调用时，我们总是加一个非空（？）的判断,
        根据返回值做响应的结果，但是 takeUnless它与takeif相反，即如果takeUnless的闭包结果返回false,
        则返回闭包执行的结果，如果它的闭包结果为ture，返回空，请看以下案例
        姓名为：honeyLl
        姓名为：honeyLl

         *********repeat**********
        honeyLl
        0
        honeyLl
        1
        honeyLl
        2


 * */