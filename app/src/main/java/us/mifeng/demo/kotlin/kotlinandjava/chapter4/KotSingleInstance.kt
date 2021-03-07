package us.mifeng.demo.kotlin.kotlinandjava.chapter4

/**
 * kotlin的单例对象
 * 通过companion实现
 * */

class SingleInstance private constructor(){
    companion object{
        fun getInstance():SingleInstance{
            return Holder.instance;
        }
        private object  Holder{
            val instance=SingleInstance();
        }
    }
}