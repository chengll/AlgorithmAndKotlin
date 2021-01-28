package us.mifeng.demo.kotlin.chapter3.userInfobject

//内部类和外部类
class Outer{
    inner class Inner{
        fun getOuterRefrence():Outer=this@Outer;
    }
}