package us.mifeng.demo.linechart;
/**
 * 线性列表
 * */

public interface IList<T> {
 //判断是否是空的
    boolean  isEmpty();
    //获取长度
    int length();
    /**
     * @param index 指定要插入的位置
     * @param data 需要插入的数据
     * 指定位置插入数据
     * */
    boolean add(int index,T data);
    /**
     * 将指定的元素插入到列表的末尾
     * @param data 插入的数据
     * */
    boolean add(T data);

    /**
     * 根据索引值移除元素
     * @param  index  根据索引移除
     * */
    T remove(int index);

    /**
     *移除值为data 的数据
     * @param data
     * */
    boolean remove(T data);
    /**
     * 移除所有的元素
     * */
    boolean  removeAll(T data);
    /**
     * 情况列表
     * */
    void clear();

    /**
     * 设置指定序列的值
     * @param index, 指定的位置
     * @param data  需要设置的值
     * */
    T set(int index,T data);

    /**
     * 是否包含值是data
     * @param data
     * */
    boolean contains(T data);

    /**
     * 根据值查询索引
     * @param  data 需要被查询的对象
     * */
    int indexOf(T data);

    /**
     * 根据data查询在列表中最后一次出现的索引值
     * @param data 需要被查询的对象
     * */
    int lastIndexOf(T data);

    /**
     * 获取指定索引的元素
     * @param index 指定的位置
     * */
    T get(int index);

     /**
      * 输出格式
      * */
     String toString();



}
