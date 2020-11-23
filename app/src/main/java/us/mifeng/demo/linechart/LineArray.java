package us.mifeng.demo.linechart;
/**
 * 线性表
 * */
public class LineArray<T> implements IList<T> {
    private Object[] datas;
    /**
     * 通过给定的数组创建线性表
     * */
 private LineArray(){};
    public static <T> LineArray<T> createLineArray(T[] objs){
        LineArray<T> array=new LineArray<>();
        array.datas=new Object[objs.length];
        for (int i=0;i<objs.length;i++){
            array.datas[i]=objs[i];
        }
        return array;
    }

    @Override
    public boolean isEmpty() {
        return datas.length==0;
    }

    @Override
    public int length() {
        return datas.length;
    }

    @Override
    public boolean add(int index, T data) {
        return false;
    }

    @Override
    public boolean add(T data) {
        return false;
    }

    @Override
    public T remove(int index) {
        return null;
    }

    @Override
    public boolean remove(T data) {
        return false;
    }

    @Override
    public boolean removeAll(T data) {
        return false;
    }

    @Override
    public void clear() {

    }

    @Override
    public T set(int index, T data) {
        if (index>0 && index<datas.length && null!=data){
            datas[index]=data;
        }
        return null;
    }

    @Override
    public boolean contains(T data) {
        return false;
    }

    @Override
    public int indexOf(T data) {
        return 0;
    }

    @Override
    public int lastIndexOf(T data) {
        return 0;
    }

    @Override
    public T get(int index) {
        return null;
    }
}
