package us.mifeng.demo.kotlin.kotlinandjava.kotjiegou

/**
 * kotlin 解构： 在kotlin中允许直接将一个类去拆解，然后分别赋值，以下面的例子来看
 * */
class JieGouUser(val age: Int, val name: String) {
    /**
     * 注意这里的component关键字是固定的，解构一个参数就用component1（），
     * 如果解构两个参数就用component2（），再来一个就用component3()，然后调用在main
     * 方法中的    val(age,name)=user; 这一块，直接将一个对象赋值给一个模块
     *
     * */
    operator fun component1() = age;
    operator fun component2() = name;
}

/**
 * 该类是JieGouUser类中多加一个字段nickName的类，
 * 此时我只需在该类中多加一个operator fun component3()=nickName即可，
 * 然后在main方法中测试它解构
 * */
class JieGouUser2(val uerAge: Int, val userName: String, val nickName: String?) {
    operator fun component1() = uerAge;
    operator fun component2() = userName;
    operator fun component3() = nickName;
}

fun main() {
    val user = JieGouUser(1, "honey");
    val (age, name) = user;
    println(age);
    println(name);
    println("********************")
    val user2= JieGouUser2(2, "test", "");
    val(userAge,userName,nickName)=user2;

    println(user2.uerAge);
    println(user2.userName);
    println(user2.nickName);

    println("********************")
    val user3= JieGouUser2(22, "test", "阿狗");
    val(nickAge,userWithName,withNick)=user3;
    println("测试一组nickName不为空 的结构，且val()中的字段也不能同名相比user2")
    println(user3.uerAge);
    println(user3.userName);
    println(user3.nickName);

}

/**
 * result:
 *
          1
         honey
         ********************
          2
         test
        ********************
        测试一组nickName不为空 的结构，且val()中的字段也不能同名相比user2
        22
        test
        阿狗
 *
 * */