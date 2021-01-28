package us.mifeng.demo.javareflect;

import java.lang.annotation.Annotation;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.lang.reflect.Field;

//发射如何来操作注解
public class ReflectHandleAnnotation {
    public static void main(String[] args) throws ClassNotFoundException, NoSuchFieldException {
        //1.通过反射拿到Studdent类的class
        Class  cl = Class.forName("us.mifeng.demo.javareflect.Student");
        //2.通过反射来拿到注解
        Annotation[] annotations = cl.getAnnotations();
        for (Annotation at:annotations){
            System.out.println(at);
            //result: @us.mifeng.demo.javareflect.TableKuang(value=db_student)
            //这里只是拿到了注解类，但是要获取注解的value，该进行什么操作了
        }
        TableKuang annotation =(TableKuang) cl.getAnnotation(TableKuang.class);
        String value = annotation.value();
        System.out.println("打印注解中的值："+value);

        //获得类指定的注解
        Field name = cl.getDeclaredField("name");
        name.getAnnotation(FieldKuang.class);

    }
}
@TableKuang("db_student")
class Student{
    @FieldKuang(columnName = "db_name",type="String",length = 20)
    private String name;
    @FieldKuang(columnName = "db_id",type = "int",length = 15)
    private int id;
    @FieldKuang(columnName = "db_age",type = "int",length = 12)
    private int age;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public Student(String name, int id, int age) {
        this.name = name;
        this.id = id;
        this.age = age;
    }
}

//自定义注解
//类名的注解
@Target(ElementType.TYPE)
@Retention(RetentionPolicy.RUNTIME)
@interface TableKuang{
 String value() default "honey";
}

//属性的注解
@Target(ElementType.FIELD)
@Retention(RetentionPolicy.RUNTIME)
@interface FieldKuang{
    String columnName();
    String type();
    int length();
}