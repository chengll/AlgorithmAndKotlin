package us.mifeng.demo.kotlin.kotlinandjava.chapter4

/**
 * kotlin的data的使用
 *数据类：是kotlin中一个非常特殊的类，可以自动的给一个类生成getter/setter ，
 toString()，hashCode(),equals(),copy等方法
 data类是一个final类，不能被继承，不能被重写
 * */

data class User(var id:Int,var name:String);
