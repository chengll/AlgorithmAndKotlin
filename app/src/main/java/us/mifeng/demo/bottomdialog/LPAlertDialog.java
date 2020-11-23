package us.mifeng.demo.bottomdialog;

import android.app.Dialog;
import android.content.Context;
import android.view.KeyEvent;
import android.view.View;

/**
 * <p>警告对话框。</p>
 * @author Chris
 */
public class LPAlertDialog extends Dialog {
    // 容器标记，一般由lua脚本指定
    private int tag_;
    private String title_;
    /**
     * <p>dialog里装载的view。</p>
     */
    public View view_;

    // 标示是否是window:showContent()的页面
    private boolean mIsShowContent;

    /**
     * <p>警告对话框的构造方法。</p>
     * @param context 应用程序上下文对象。
     * @param theme 应用的主题。
     * @param view dialog里装载的view。
     */
    public LPAlertDialog(Context context, int theme, View view) {
        super(context, theme);
        // 设置在Dialog外任意区域点击关闭Dialog
        setCanceledOnTouchOutside(true);
        view_ = view;
        title_ = "";
    }

    /*
     * (non-Javadoc)
     * 
     * @see android.app.Dialog#onKeyDown(int, android.view.KeyEvent)
     */
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        switch (keyCode) {
        case KeyEvent.KEYCODE_BACK:
            return super.onKeyDown(keyCode, event);
        default:
            return super.onKeyDown(keyCode, event);
        }
    }

    /**
     * <p>给警告对话框设置tag。</p>
     * @param tag 待设置的tag值。
     */
    public void setTag(int tag) {
        tag_ = tag;
    }

    /**
     * <p>获得警告对话框的tag值。</p>
     * @return 警告对话框的tag值。
     */
    public int getTag() {
        return tag_;
    }

    @Override
    public void dismiss() {
        super.dismiss();
    }

    /**
     * <p>设置对话框的title。</p>
     * @param title 待设置的title。
     */
    public void setTitle(String title) {
        title_ = title;
        super.setTitle(title);
    }

    /**
     * <p>获得对话框的title。</p>
     * @return 对话框的title。
     */
    public String getTitle() {
        return title_;
    }

    public void setIsShowContent(boolean isShowContent){
        mIsShowContent = isShowContent;
    }

    public boolean isShowContent(){
        return mIsShowContent;
    }

}
