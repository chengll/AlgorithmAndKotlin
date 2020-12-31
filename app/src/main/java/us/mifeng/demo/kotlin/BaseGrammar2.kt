package us.mifeng.demo.kotlin

import android.content.Context
import android.util.AttributeSet
import android.view.View
import java.lang.ArithmeticException
import java.lang.Exception
import java.util.Arrays.equals
import java.util.Objects.equals
import java.util.jar.Attributes

fun main() {
    //fool("sgs");
    //定义map
    val map= mapOf<String,String>("a" to "1","b" to "2");
    val map2= mutableMapOf<String,Any>("name" to "honey","age" to '1');

    val emails="";
    val mainEmails=emails.firstOrNull();
    emails?.let {
    }
    val myTurtle=Turtle();
    with(myTurtle){
        openDown();
        for (i in 1..4){
            openDown()
            forward(100);
            turnDegree(26.0f);
        }

    }
    val derivedClass= Derived("honey","lingling");
    //derivedClass.initArray();
    //derivedClass.initArrayList();
    val childSubClass=ChildSub();
    //println("childSubClass.propertyWithImplemention="+childSubClass.propertyWithImplemention);
   // println("打印childSubClass.pro"+childSubClass.pro);
    MyClass.printCompanion();


}
class MyClass{
    companion object{}
}
fun MyClass.Companion.printCompanion(){
    println("companion");
}
fun transform(color:String):Int{
    return when(color){
        "red"-> 0;
        "blue"-> 1;
        "green" -> 3
        else ->throw IllegalArgumentException("not fitable color");
    }
}

fun fool(color:String) {
    listOf<Int>(1, 2, 3, 4, 5).forEach {
        if (it == 3) return;
        println(it);
    }
    println("this point is unreachable ");

    val result=try {
        println(" there maybe appears exception");
    }catch (e:Exception){
        println("you need to catch this exception");
    }finally {
        println("there is no difference with java ");
    }


}

fun whenState(x: String) {
    when (x) {
        "string" -> print("hhh");
        "case"->{
            for (i in 1..10){
                println("this is  a series code");
            }
        }
        "1"->{
            for (i in 2..5){
                println("this is when clause case");
            }

        }

    }
}
 fun ifState(param:String):Int{
     val case2 = if (param=="3"){
        "three"
     }else if (param=="4"){
         "test";
     }else{
         1
         println("this is a default case ");
     }
     return  -1;
 }

fun arrayMinOnes(size:Int):IntArray{
    return IntArray(size).apply{fill(-1);}
    fun answer()=32;
}
fun answer():Int{
    return -1;
}

//call multiple class methods on an object instance(with)

class  Turtle{
    fun openDown(){};
    fun penUp(){};
    fun turnDegree(degress:Float){};
    fun forward(piexls:Int){};
}

class Person2{
 var children2:MutableList<Person2> = mutableListOf();
    constructor(father:Person2){
        father.children2.add(this);
    }
}
//定义一个类
class Person(val name:String){
    var children:MutableList<Person> = mutableListOf();
     constructor(parent:Person,name:String):this(name){
        parent.children.add(this);
    }
}
/*classes in kotlin are decleared final ,so in order to make the class can inheritaged ,we
should keep class open*/
open class BaseClass(val name:String){

}
//subclass inherit baseClass
class SubClass(p:String) :BaseClass(p){

}
class MyView : View {
    constructor(cxt: Context):super(cxt);
    constructor(cxt: Context,attrs:AttributeSet):super(cxt,attrs);
}

open class Shape{
     open fun draw(){

     }

    fun fill(){

    }
}
//定义cirCle类继承Shape类
class Circle():Shape(){
    override fun draw() {
        super.draw()
    }

}

//define a interface 定义一个接口
interface ShapeInter{
    val vertextCount:Int;
}
//定义一个类实现ShaperInter这个接口
class Rectangle (override val vertextCount:Int =4):ShapeInter{

}
class Polygon:ShapeInter{
    override var vertextCount:Int=9;
}

open class Base2Class (val name:String){
    init {
        println("Initializing class")
    }
    open val size:Int=name.length.also{
        println("Initializing size in Base:");
    }
}


class  Derived(name:String,val lastName:String):BaseClass(name){
  fun initArray(){
      val d= arrayOf("hello","kotlin");
      //数组遍历1
      for (i in 1..d.size){
          println("打印 d 中输出的数据为："+"${d[0]},${d[1]}");
          /*
          运行结果为：
          打印 d 中输出的数据为：hello,kotlin
          打印 d 中输出的数据为：hello,kotlin
          */
      }
      //数组遍历2
      d.forEach { element ->println(" 打印通过forEach 来遍历数组："+element);
          /*
           运行结果为：
           打印通过forEach 来遍历数组：hello
            打印通过forEach 来遍历数组：kotlin
            */
      }
      //数组遍历3
      for (i in d.indices){
          println(" 打印通过d.indices 来遍历数组："+i);
          /*
            运行结果为：
            打印通过d.indices 来遍历数组：0
            打印通过d.indices 来遍历数组：1
            */
      }
  }
   // ::initArray 表示一个方法的引用
    fun initArrayList(){
       val list=ArrayList<String>();
       list.add("11");
       list.add(::Person2.name);
       for (i in list.iterator()){
           println("遍历集合list的结果为："+i)
       }
       val getValue1 = list.get(0);
       println("输出获取的第一个值："+getValue1);
       list.add(::Base2Class.name)
       //list+=::Person.name;
   }
}

interface MyInterface{
    val pro:Int;
    fun bar();

    val propertyWithImplemention:String
    get()="honey";
    fun fool(){
        println(pro);
    }


}

class ChildSub() :MyInterface{
    override val pro:Int=29;
    override fun bar() {
    }
    constructor(name:String,age:Int) : this() {
        println("打印父类中的值："+super.propertyWithImplemention);
    }

}









