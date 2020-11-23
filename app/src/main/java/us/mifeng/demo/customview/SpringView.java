package us.mifeng.demo.customview;

import android.content.Context;
import android.content.res.TypedArray;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.OverScroller;

import us.mifeng.demo.R;

/**
 * 自定义ViewGroup
 * */
public class SpringView extends ViewGroup {
    private LayoutInflater layoutInflater;
    private Context context;
    private OverScroller mScroller;
    private Type  type=Type.FOLLOW;
    private Give give=Give.BOTH;
    private int headerResourceId;
    private int footerResourceId;
    private View header;
    private View footer;
    //目标view ,被SpringView包裹的View
    private View contentLay;
    private View contentView;

    //拖拽类型
    public enum Type{
       OVERLAP,//重叠
        FOLLOW,//跟随
        DRAG , //拖拽
        SCROLL //滚动  目前该模式不支持ListView(建议使用RecyclerView代替，
        // 主要原因是由于ListView本身设计存在缺陷无法准确地计算出内容高度)
        //              ScrollView不支持6.0之前(建议使用NestedScrollView代替，
        //              主要原因是ScrollView的滚动接口只支持6.0之后的版本)
    }

    //是否需要回调接口
    public enum Give{
        TOP,   //只回调刷新
        BOTTOM,//只回调加载更多
        BOTH,  //都需要
        NOE    //都不
    }
    public SpringView(Context context) {
        this(context,null);
    }

    public SpringView(Context context, AttributeSet attrs) {
        this(context, attrs,0);
    }

    public SpringView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        this.context=context;
        layoutInflater=LayoutInflater.from(context);
        mScroller=new OverScroller(context);
        initAttributes(attrs);
    }
    //初始化自定义事件
    private void initAttributes(AttributeSet attrs) {
        TypedArray ta=context.obtainStyledAttributes(attrs,R.styleable.SearchView);
        if (ta.hasValue(R.styleable.SpringView_type)){
            int type_index = ta.getInt(R.styleable.SpringView_type, 0);
            type =Type.values()[type_index];
        }

        if (ta.hasValue(R.styleable.SpringView_give)){
            int give_index=ta.getInt(R.styleable.SpringView_give,0);
            give=Give.values()[give_index];
        }

        if (ta.hasValue(R.styleable.SpringView_footer)){
            headerResourceId=ta.getResourceId(R.styleable.SpringView_footer,0);
        }
        if (ta.hasValue(R.styleable.SpringView_footer)){
            footerResourceId=ta.getResourceId(R.styleable.SpringView_footer,0);
        }
        ta.recycle();
    }

    @Override
    protected void onFinishInflate() {
        super.onFinishInflate();
    }

    @Override
    protected void onLayout(boolean changed, int l, int t, int r, int b) {
        if (null!=contentLay){
            if (null!=header){

            }
        }

    }
}

