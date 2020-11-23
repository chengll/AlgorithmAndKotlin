package us.mifeng.demo.bottomdialog;

import android.app.Activity;
import android.content.Context;
import android.text.SpannableStringBuilder;
import android.text.TextUtils;
import android.text.method.LinkMovementMethod;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewParent;
import android.view.ViewTreeObserver;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.TextView;

import us.mifeng.demo.R;
import us.mifeng.demo.utils.Screen320Utils;

public class LPPromptDialog {

    private TextView mTvContent;
    private TextView mTvTitle;
    private RelativeLayout mLayoutBottomTwo, mLayoutBottom;
    private Button mBtnLeft, mBtnRight, mBtnCenter;
    private View mRootView;
    private ScrollView mScrollViewContent;
    private Activity mActivity;
    public LPAlertDialog mDialog;
    private WindowManager.LayoutParams mWindowLp;
    private Context mContetx;
    private Screen320Utils screen320Utils;


    public LPPromptDialog(Activity mActivity) {
        this.mActivity = mActivity;
        mContetx=mActivity;
        onInitView();
        onInitDialog();
        onInitListener();
    }

    public void onInitView() {
        mRootView = mActivity.getLayoutInflater().inflate(R.layout.bjdialog, null);

        mTvTitle = (TextView) mRootView.findViewById(R.id.tv_bjdialog_title);
        mScrollViewContent = (ScrollView) mRootView.findViewById(R.id.sv_bjdialog_content);
        mTvContent = (TextView) mRootView.findViewById(R.id.tv_bjdialog_content);
        mLayoutBottomTwo = (RelativeLayout) mRootView.findViewById(R.id.rl_bjdialog_bottomTwoLayout);
        mLayoutBottom = (RelativeLayout) mRootView.findViewById(R.id.rl_bjdialog_bottomOneLayout);
        mBtnLeft = (Button) mRootView.findViewById(R.id.btn_bjdialog_left);
        mBtnRight = (Button) mRootView.findViewById(R.id.btn_bjdialog_right);
        mBtnCenter = (Button) mRootView.findViewById(R.id.btn_bjdialog_center);
        screen320Utils = new Screen320Utils();
    }

    private void onInitDialog() {
        ViewParent parent = mRootView.getParent();
        if (null != parent) {
            ((ViewGroup) parent).removeView(mRootView);
        }
        mDialog = new LPAlertDialog(mActivity, R.style.DailogStyle, mRootView);
        mDialog.setCanceledOnTouchOutside(false);
        mDialog.setOwnerActivity(mActivity);
        mDialog.setContentView(mRootView);

        mWindowLp = mDialog.getWindow().getAttributes();
        mWindowLp.gravity = Gravity.CENTER;
        // mWindowLp.width= new Screen320Utils(mContetx).px_2px(320);
        mWindowLp.width = Screen320Utils.px_2px(247);
    }

    private void onInitListener() {
        ViewTreeObserver viewTreeObserver = mTvContent.getViewTreeObserver();
        viewTreeObserver.addOnPreDrawListener(new ViewTreeObserver.OnPreDrawListener() {
            boolean isHandle=false;
            @Override
            public boolean onPreDraw() {
                if (!isHandle){
                    int height=mTvContent.getMeasuredHeight();
                    // 130 -> content view 以外控件的总高度
                    int maxHeight=Screen320Utils.getScreenHeight()-Screen320Utils.getScaledValueX(130);
                    if (height>maxHeight){
                        RelativeLayout.LayoutParams layoutParams= (RelativeLayout.LayoutParams) mScrollViewContent.getLayoutParams();
                        layoutParams.height=maxHeight;
                        mScrollViewContent.setLayoutParams(layoutParams);
                    }
                    isHandle=true;
                }
                return false;
            }
        });
    }

    /**
     *
     * 1.弹出一个按钮的dialog,而且需要给该按钮设置确定事件的弹窗
     * @param title 标题
     * @param  content 提示内容
     * @param  btnTxt 按钮文本
     * @param  listener 按钮的监听
     * */

    public void dialog(Object title, String content, String btnTxt, final View.OnClickListener
            listener) {
        if (title == null || TextUtils.isEmpty(title.toString())) {
            mTvTitle.setVisibility(View.GONE);
        } else {
            mTvTitle.setText(title.toString());
        }

        mTvContent.setText(content == null ? "" : content);
        mBtnCenter.setText(btnTxt == null ? "" : btnTxt);

        if (listener != null) {
            mDialog.dismiss();
            mBtnCenter.setOnClickListener(listener);
        }

        mDialog.show();
    }

    /**
     * 1.弹出对话框 一个按钮的
     *
     * @param content     提示内容
     * @param btnText     按钮信息
     * @param callbackObj 按钮回调
     */
    public void alert(String content, String btnText, View.OnClickListener callbackObj) {
        dialog("提示", content, btnText, callbackObj);
    }

    /**
     * 弹出对话框
     *
     * @param title       标题
     * @param content     提示内容
     * @param btnTxt      按钮信息
     * @param listener    按钮回调
     */
    public void dialogSpannable(Object title, SpannableStringBuilder content, String btnTxt, final View.OnClickListener
            listener) {
        if (title == null || TextUtils.isEmpty(title.toString())) {
            mTvTitle.setVisibility(View.GONE);
        } else {
            mTvTitle.setText(title.toString());
        }
        mTvContent.setText(content);
        mTvContent.setMovementMethod(LinkMovementMethod.getInstance());
        mBtnCenter.setText(btnTxt == null ? "" : btnTxt);
        if (listener != null) {
            mDialog.dismiss();
            mBtnCenter.setOnClickListener(listener);
        }
        mDialog.show();
    }


    /**
     * 带有两个按钮的dialog
     *
     * @param title         标题
     * @param content       提示内容
     * @param leftText      左侧按钮信息
     * @param rightText     右侧按钮信息
     * @param leftListener  左侧按钮监听
     * @param rightListener 右侧按钮监听
     */
    public void dialog(Object title, String content, String leftText, String rightText,
                       View.OnClickListener leftListener, View.OnClickListener rightListener) {
        if (title == null || TextUtils.isEmpty(title.toString())) {
            mTvTitle.setVisibility(View.GONE);
        } else {
            mTvTitle.setText(title.toString());
        }

        mLayoutBottom.setVisibility(View.GONE);
        mLayoutBottomTwo.setVisibility(View.VISIBLE);

        mTvContent.setText(content == null ? "" : content);
        mBtnLeft.setText(leftText == null ? "" : leftText);
        mBtnRight.setText(rightText == null ? "" : rightText);

        if (leftListener != null) {
            mBtnLeft.setOnClickListener(leftListener);
        }

        if (rightListener != null) {
            mBtnRight.setOnClickListener(rightListener);
        }

        mDialog.show();
    }
}
