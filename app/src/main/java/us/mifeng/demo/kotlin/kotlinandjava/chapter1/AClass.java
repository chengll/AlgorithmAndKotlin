package us.mifeng.demo.kotlin.kotlinandjava.chapter1;

public class AClass implements AInterface {
    public static final AClass aClass=new AClass();
    @Override
    public void printNum(int age) {
        System.out.println("int");
    }

    @Override
    public void printNum(Integer number) {
        System.out.println("Interger");
    }

    @Override
    public void systemNum(Integer number) {

    }

    public static String formatstr(String string){
        return string.isEmpty()?null:string;
    }
}
