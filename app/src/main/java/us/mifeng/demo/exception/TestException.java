package us.mifeng.demo.exception;

import android.text.TextUtils;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

import us.mifeng.demo.exception.TestException2;

/**
 * 一个简单的测试java的异常的简单demo
 *
 * */
public class TestException {
    public static void main(String[] args) {
         String userName="sgsgsgs";
        /*
         1.Exception in thread "main" 用户名不满足条件，需要手动抛出异常
        us.mifeng.demo.kotlin.IlleagalException: heck
	    at us.mifeng.demo.kotlin.CustomService.regiseter(TestException.java:117)
	    at us.mifeng.demo.kotlin.TestException2.checkException(TestException2.java:6)
	    at us.mifeng.demo.kotlin.TestException.main(TestException.java:15)
        这种情况是: 使用throws抛出异常给jvm,如果jvm将程序停止，因此
         System.out.println("使用throws抛出异常给jvm,如果jvm将程序停止，则该句不会被执行，如果执行了，则无异常");
         这句没有被执行
         2.如果对main方法不抛出异常，使用try---catch来捕获异常，你会发现程序还会继续往下运行，
         us.mifeng.demo.kotlin.IlleagalException: sgsgsgs
	    at us.mifeng.demo.kotlin.CustomService.regiseter(TestException.java:132)
	    at us.mifeng.demo.kotlin.TestException2.checkException(TestException2.java:12)
	    at us.mifeng.demo.kotlin.TestException.main(TestException.java:27)
        使用throws抛出异常给jvm,如果jvm将程序停止，则该句不会被执行，如果执行了，则无异常

        这句话  System.out.println("使用throws抛出异常给jvm,如果jvm将程序停止，则该句不会被执行，如果执行了，则无异常");
        也被执行啦啦
         * */
        TestException2 testException2 = new TestException2(userName);
        try {
            testException2.checkException();
        } catch (IlleagalException e) {
            e.printStackTrace();
        }
        System.out.println("使用throws抛出异常给jvm,如果jvm将程序停止，则该句不会被执行，如果执行了，则无异常");

    /*    try {
            double c=getChu(1,0);
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("==========1======这里异常走了吧");
        };
        System.out.println("这里走了吗?");*/
        //情况2.只有try---finally，throws抛出了异常 的情况
        /*
        * 2这个种情况将异常抛给了JVM，没有处理，因此JVM只能将程序停止，
        * 但是finally语句还是被执行了，但是由于有异常，所以
        *   System.out.println("如果没有异常会走到这里的。。。。------");
        * 这句没有被执行到。
        *
        * */
        /**try{
            FileInputStream stream=new FileInputStream("/adbs.txt");
        }finally {
            System.out.println("finally中的语句------");
        }
        System.out.println("如果没有异常会走到这里的。。。。------");
         */
        //情况3： 我用catch捕获了异常，不抛出给jvm了，因此我的执行结果为：
        /*
        *   我用catch捕获异常，我不抛给jvm了
            finally中的语句------
            如果没有异常会走到这里的。。。。------
            会发现try...catch已经将异常处理了，程序可以继续往下运行
        * */
        try{
            FileInputStream stream=new FileInputStream("/adbs.txt");
        }catch (Exception e){
            System.out.println("我用catch捕获异常，我不抛给jvm了");
        }finally {
            System.out.println("finally中的语句------");
        }
        System.out.println("如果没有异常会走到这里的。。。。------");
        //情况4： System.out.println("调用m1()的结果为：" + m1());
        /**
         * 1.java异常总结，总之不能将异常抛给jvm,如果抛给jvm，jvm只能将程序停止
         * 这时候我们可以通过e.printStack（）方法来查看异常的堆栈信息。
         * 2.解决异常的两种方式是try---catch和throws，throws一直网上抛异常会导致程序崩溃。
         *3，自定义的异常，手动抛出异常使用的是throw关键字，不是throws.
         * 4.如果方法在声明时候就抛出了异常，那么在调用的地方遇到了一定是会有异常的。
         * */
    }

    /**
     * 一个很奇怪的问题，关于try---catch---finally的问题，在 try中处理完用return返回了，
     * 但是finally中的结果还是会走的，除非是在try中做完操作执行了System.exit(0)方法
     * 即，手动停掉jvm
     * final:final关键字修饰的方法不能被重写，修饰的类不能被重写，修饰的变量值不能在修改等等；
     * finalize:它是object类中的一个方法名称，压根不是关键字
     * finally: 它是异常机制中中最终处理异常用的。
     */
    public static int m1() {
        int i = 12;
        try {
            i = 10;
            // System.exit(0);
            return i;
        } catch (Exception e) {
            System.out.println("e的message是：" + e.toString() + " catch中i的值是：===" + i);
        } finally {
            System.out.println(" finally 中i的值是：===" + i);
        }
        return -121;
    }

    public static double getChu(int a, int b) {
        return a / b;
    }
}
//自定义异常类
class IlleagalException extends Exception {
    public IlleagalException() {
    }

    public IlleagalException(String userName) {
        super(userName);
    }
}

//业务类中去使用自定义异常
 class CustomService {
    public void regiseter(String userName) throws IlleagalException {
        if (userName.length() < 6) {
            System.out.println("用户名不满足条件，需要手动抛出异常");
            /*
             *  说明此处userName是不满足条件的，因此我们 手动向上抛出异常，
                使用的是throw 我们自定义的异常(new IlleagalException)，即
                (throw new IlleagalException(userName))异常。
                但是抛出去的异常谁来处理了 ，谁调用谁来处理，比如
                在下面的类中最终要调用CustomService的 register()方法，
               因此就需要它来处理这个register抛出的异常，当然它也可以选择不处理，继续往上抛；
               如果捕获则用try..catch,如果继续往上抛，则使用throws关键字，但是如果一层层往上抛
               不处理的话，异常最终抛给jvm，jvm只能将程序停掉。
             */
        }
        throw new IlleagalException(userName);
    }
    //System.out.println("这句如果能被执行，说明用户名是符合规则的，并没有抛出异常");
}

