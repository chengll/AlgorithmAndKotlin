package us.mifeng.demo.bean;

public class TestClass{
    /**
     * 虽然使用lambda表达式可以对某些接口进行简单的实现，不是所有的接口都可以使用lambda
     * 表达式来实现，Lambda规定接口只能有个一必须需要实现的方法，不是规定接口中只能有个
     * 一个方法
     * 注意：jdk 8z中另外有一个新特性，default 被default修饰的方法会默认有实现，
     * 不是必须实现的方法，所以不影响Lambda表达式的使用。
     * @FunctionInterface 注解的作用，专门来修饰函数式接口的，需求接口中的抽象方法只有一个，
     * 这个注释一般会和lambda 表达式一起作用
     *
     * Lambda的基础语法：
     *  语法形式为（）->{} ,其中 （）用来描述参数列表， {} 用来描述方法体，
     *   ->为lambda运算符，读作（goes to）
     * */
    @FunctionalInterface
    public interface NoReturnOneParam {
        void method(int a);
    }

    @FunctionalInterface
    public interface ReturnMultiParam{
        int method2(int a,int b);
    }

    @FunctionalInterface
    public interface ReturnNoParam{
        int mdthod3();
    }
    @FunctionalInterface
    public interface ReturnOneParam{
        int method4(int a);
    }
}