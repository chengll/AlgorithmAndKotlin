package us.mifeng.demo.kotlin.kotlinandjava.chapter4

/**
 * kotlin 的代理
 * kotlin 的代理是通过by关键字来实现的 本质是将动态代理改为静态的方式，而java是通过反射的方式来实现的
 * 因此kotlin的动态代理比java的高效果
 *
 * */

interface Animals {
    fun bark();
}

class DogClass : Animals {
    override fun bark() {
        println("dog 的叫法是 wang");
    }
}

class Zoom(animals: Animals) :Animals by animals{
    override fun bark() {
        println("zoom");
    }
}

fun main() {
    Zoom(DogClass()).bark();
}
/**
 * result:
 *      zoom
 * */
