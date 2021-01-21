package us.mifeng.demo.javareflect;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

//通过反射动态的创建对象
public class JavaReflcet1 {
    public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, NoSuchMethodException, InvocationTargetException, NoSuchFieldException {
        Class userClass = Class.forName("us.mifeng.demo.javareflect.User");
        //1、通过class创建USer对象
        User mUser = (User) userClass.newInstance(); //本质是构造了User类中的午参数的构造方法
        System.out.println(mUser);
        //2.通过构造器创建对象
        Constructor constructor = userClass.getConstructor(String.class, int.class, int.class);
        User mUser2 = (User) constructor.newInstance("honey", 1, 21);
        System.out.println("name=" + mUser2.getName() + " age=" + mUser2.getAge() + "  id=" + mUser2.getId());

        System.out.println(new User());

        //3通过反射获取一个方法
        Method setNameMethod = userClass.getDeclaredMethod("setName", String.class);

        //4.通过反射获取的方法调用该setName方法  参数1.对象 参数2.传递的参数
        setNameMethod.invoke(mUser, "haha");

        //5.在创建一个对象
        User mUser3 = (User) userClass.newInstance();
        Field mName = userClass.getDeclaredField("name");//获取name属性
        mName.setAccessible(true);  //修改private属性可以被访问
        mName.set(mUser3, "hoho");  //给user4d对象的name字段赋值
        System.out.println("name3=" + mUser3.getName());
    }

    //通过反射的方式来检测一个方法最终执行的时长
    public void testProTime() throws NoSuchMethodException, InvocationTargetException, IllegalAccessException {
        User user = new User();
        Class userClass = user.getClass();
        Method getNameMethod = userClass.getDeclaredMethod("getName", null);
        getNameMethod.setAccessible(true);
        long startTime = System.currentTimeMillis();
        for (int i = 0; i < 10; i++) {
            getNameMethod.invoke(user, null);
        }
        long endTime = System.currentTimeMillis();
        System.out.println("总共耗费时间为：" + (endTime - startTime));
    }

}
