package us.mifeng.demo.kotlin.kotlinandjava.chapter4;


/**
 * java调用companion对象的方法
 */
class JavaInvokeCom {
    public static void main(String[] args) {
        boolean empty = StringUtils.Companion.isEmpty("");
        System.out.println(empty);
    }
}

/**
 * result: false
 * */