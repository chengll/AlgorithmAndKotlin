package us.mifeng.demo.kotlin.kotlinandjava.kotjiegou;


import io.reactivex.Observable;
import io.reactivex.ObservableSource;
import io.reactivex.functions.BiFunction;
import io.reactivex.functions.Consumer;
import io.reactivex.functions.Function;
import io.reactivex.functions.Predicate;

/**
 * 通过Rxjava将两个数组的元素组合成一个wifi的密码输出
 */
public class JavaRxjava {
    public static void main(String[] args) {
        /*final String numberStr[] = new String[]{"4", "0", "7", "i", "f", "w", "0", "9"};
        final Integer index[] = new Integer[]{5, 3, 9, 4, 8, 3, 1, 9, 2, 1, 7};
        Observable.just(index)
                .flatMap(new Function<Integer[], ObservableSource<?>>() {
                    @Override
                    public ObservableSource<?> apply(Integer[] integers) throws Exception {
                        return Observable.fromArray(integers);
                    }
                })
                .filter(new Predicate<Integer>() {

                    @Override
                    public boolean test(int integer) throws Exception {
                        return integer> numberStr.length;
                    }
                })
                .map(new Function<Integer, String>() {

                    @Override
                    public String apply(Integer integer) throws Exception {
                        return numberStr[integer];
                    }
                })
                .reduce(new BiFunction<String, String, String>() {
                    @Override
                    public String apply(String r, String r2) throws Exception {
                        return r + r2;
                    }
                })
                .subscriber(new Consumer<String>() {
                    @Override
                    public void accept(String r) throws Exception {
                        System.out.println("最终输出的密码是：" + r);
                    }
                });
*/
    }
}
