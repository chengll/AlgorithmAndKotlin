package us.mifeng.demo.javareflect;

import java.lang.reflect.Method;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.util.List;
import java.util.Map;

//通过反射来获取泛型的参数
public class TestGenericTypeReflect {
    public static void main(String[] args) throws NoSuchMethodException {
        //通过类的class 获取方法
        Method test01 = TestGenericTypeReflect.class.getMethod("test01", Map.class, List.class);
        //获取方法的泛型
        Type[] genericParameterTypes = test01.getGenericParameterTypes();
        //遍历输出泛型
        for(Type  mType :genericParameterTypes){
            System.out.println("获取到的泛型参数为:"+mType);
            if (mType instanceof ParameterizedType){
                Type[] actualTypeArguments = ((ParameterizedType) mType).getActualTypeArguments();//获取泛型真正的参数类型
                for (Type actualType:actualTypeArguments){
                    System.out.println("输出真正的参数为："+actualType);
                }
            }

        }
        
        //获取方法的返回值类型为
        Method test02Method = TestGenericTypeReflect.class.getMethod("test02", null);
        Type genericReturnType = test02Method.getGenericReturnType();
        if (genericReturnType instanceof ParameterizedType){
            Type[] actualTypeArguments = ((ParameterizedType) genericReturnType).getActualTypeArguments();
            for (Type returnType:actualTypeArguments){
                System.out.println("方法的返回值类型为："+returnType);
            }
        }

    }

    public void test01(Map<String,User> map,List<User>list){
        System.out.println("test01");
    }

    public Map<String,User>  test02(){
        System.out.println("test02");
        return null;
    }

}

/**
 *  result：
 *   获取到的泛型参数为:java.util.Map<java.lang.String, us.mifeng.demo.javareflect.User>
 *  输出真正的参数为：class java.lang.String
 *  输出真正的参数为：class us.mifeng.demo.javareflect.User
 *  获取到的泛型参数为:java.util.List<us.mifeng.demo.javareflect.User>
 *  输出真正的参数为：class us.mifeng.demo.javareflect.User
 *
 * */
