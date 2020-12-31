package us.mifeng.demo.annotationbase;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/*
* 自定义注解
* 使用@interface来自定一个注解，自动继承了java.lang.annotation.Annotation接口；
* 分析：
* 格式：public @interface AnnotationName
* 其中的每一个方法实际上都是一个声明配置的参数
* 如果只有一个成员，则用value
* @Target表示注解作用的范围
* @RetentionPolicy表示注解在什么时候起作用，有runnTime ，Source和Class之分
* */

public class CustomizeAnnotation {
    @MyAnnotation(schools={"dss","sds"})
    public void test(){

    }
}

//自定义定义注解
@Target({ElementType.TYPE,ElementType.METHOD})
@Retention(RetentionPolicy.RUNTIME)
@interface MyAnnotation{
    //如果这里设置了默认值，则在使用的地方再不用去赋值了，如果没有默认值就要赋值，比如schools
    String name() default "honeyll";
    int age() default -1;
    String[] schools();
}
/*
   //一、反射中通过以下方式来获取class对象
* 1.Class class=Class.forName("类的全名");
* 2.Person person=new Person();
*   Class c=person.getClass();
* 3.Class c3=Person.class;
  4.Class c4=Integer.Type;

*
*
* */