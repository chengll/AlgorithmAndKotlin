package us.mifeng.demo;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.net.Uri;
import android.os.Bundle;
import android.provider.Settings;
import android.text.Spannable;
import android.text.SpannableStringBuilder;
import android.text.TextPaint;
import android.text.style.ClickableSpan;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.Toast;

import org.greenrobot.eventbus.EventBus;

import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;

import us.mifeng.demo.bottomdialog.LPAlertDialog;
import us.mifeng.demo.bottomdialog.LPPromptDialog;
import us.mifeng.demo.utils.GenerateValueFiles;
import us.mifeng.demo.utils.UtilAnim;
import us.mifeng.demo.utils.UtilBitmap;

import static us.mifeng.demo.utils.UtilBitmap.getDrawing;

public class MainActivity extends AppCompatActivity {

    private Button clickChange;
    private Button close;
    private RelativeLayout rl_popup_window;
    private ImageView iv_popup_window_back;
    private LPPromptDialog lpPromptDialog;
    private LPAlertDialog mDialog;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        supportRequestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_main);
        EventBus.getDefault().register(this);
        String wxPayUrl="https://wx.tenpay.com/cgi-bin/mmpayweb-bin/checkmweb?prepay_id=wx07100408168648515d3d6e631935503300&package=3808200414&redirect_url=https%3A%2F%2Fopen.chediandian.com%2Fpay%2Fresult%3ForderId%3D2020080710040804351%26serviceId%3D300006972";
        String encodeURl = null;
        try {
            encodeURl = URLEncoder.encode(wxPayUrl,"utf-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        String lanjieAnionPayurl="";
        Log.d("tags", "onCreate: -----编码拦截微信的url="+encodeURl);
        int arr[]=new int[]{1,3,5,5,8,10,12};
        //获取元素在数组中的位置
       // Log.d("testLocate", "onCreate: ----5在数组中的位置是--"+TheoryMatic.locate(arr,6));
      //  Log.d("testLocate", "onCreate: ----5在数组中的位置是--"+TheoryMatic.insertData(arr, 23,3,arr.length));

        clickChange = findViewById(R.id.clickChange);
        close = findViewById(R.id.close);
        rl_popup_window=findViewById(R.id.rl_popup_window);
        iv_popup_window_back=findViewById(R.id.iv_popup_window_back);
        lpPromptDialog = new LPPromptDialog(this);
        clickChange.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                clickChangeWindow(iv_popup_window_back);
            }
        });
        close.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
              // clickClosePopupWindow(rl_popup_window,iv_popup_window_back);
                //跳转到gps页面
                Intent intent = new Intent(Settings.ACTION_LOCATION_SOURCE_SETTINGS);
                startActivityForResult(intent, 0x12);

            }
        });

        //点击弹出框
        findViewById(R.id.mShow).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
               // showSimpleDialog();
               // showDiaColor();
                //showDoalodaDialog();
                //notForceUpdateDialog();
                openWx();
            }
        });

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode==0x12){
            Toast.makeText(MainActivity.this,"返回应用设置页了。。",Toast.LENGTH_SHORT).show();
        }
    }

    public void openWx(){
        Intent intent = new Intent();
        ComponentName cmp = new ComponentName("com.tencent.mm", "com.tencent.mm.ui.LauncherUI");
        intent.setAction(Intent.ACTION_MAIN);
        intent.addCategory(Intent.CATEGORY_LAUNCHER);
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        intent.setComponent(cmp);
        startActivity(intent);
    }


    //显示模糊高斯
    private void clickChangeWindow(ImageView imgeView) {
        // 获取截图的Bitmap
        Bitmap bitmap =getDrawing(this);

        if (bitmap != null) {
            // 将截屏Bitma放入ImageView
            imgeView.setImageBitmap(bitmap);
            // 将ImageView进行高斯模糊【25是最高模糊等级】【0x77000000是蒙上一层颜色，此参数可不填】
            UtilBitmap.blurImageView(this, imgeView, 25, 0x77000000);
        } else {
            // 获取的Bitmap为null时，用半透明代替
            imgeView.setBackgroundColor(0x77000000);
        }
        //打开弹窗
        UtilAnim.showToUp(rl_popup_window, imgeView);
    }


    /**
     * 关闭g高斯模糊弹窗
     */
    private void clickClosePopupWindow(View parent,View image) {
        UtilAnim.hideToDown(parent, image);

    }

    //简单带一个按钮的提示弹窗
    public void showSimpleDialog(){
        final View.OnClickListener clickListener = new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                lpPromptDialog.mDialog.dismiss();
                Toast.makeText(MainActivity.this,"go---",Toast.LENGTH_LONG).show();

            }
        };
        lpPromptDialog.alert("hahahhah",
                "确定",
                clickListener);
    }

    /**
     * 文本区域比较多，而且部分文本颜色改变的弹窗
     * */
     public void showDiaColor(){
         //改变dialog中部分字体颜色问题
          View.OnClickListener spannableClickListener=new View.OnClickListener() {
             @Override
             public void onClick(View v) {
                 lpPromptDialog.mDialog.dismiss();
             }
         };

         ClickableSpan clickableSpan = new ClickableSpan() {
             @Override
             public void onClick(View widget) {

             }

             @Override
             public void updateDrawState(TextPaint ds) {
                 //设置部分文字颜色
                 ds.setColor(Color.parseColor("#3A8CE0"));
                 //去除连接下划线
                 ds.setUnderlineText(false);
             }
         };
         final SpannableStringBuilder style = new SpannableStringBuilder();
         style.append(getResources().getString(R.string.privacy_dialog_tip));
         style.setSpan(clickableSpan, 93, 108, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
         //一个按钮的部分字体变色的设置
         lpPromptDialog.dialogSpannable("提示",style,"我知道了",spannableClickListener);
     }

    //两个按钮类似下载弹窗
     public void showDoalodaDialog(){


         View.OnClickListener mLeftClickListener = new View.OnClickListener() {
             @Override
             public void onClick(View v) {
                 lpPromptDialog.mDialog.dismiss();
             }
         };
         //点击确定按钮
         View.OnClickListener sureListener = new View.OnClickListener() {
             @Override
             public void onClick(View v) {
                 lpPromptDialog.mDialog.dismiss();
             }
         };
         lpPromptDialog.dialog("提示", "是否下载新版本？", "暂不更新", "立即更新", mLeftClickListener, sureListener);
     }


    public void notForceUpdateDialog() {

        View.OnClickListener mLeftClickListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                lpPromptDialog.mDialog.dismiss();
            }
        };

        //点击确定按钮
        View.OnClickListener sureListener = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                lpPromptDialog.mDialog.dismiss();
            }
        };
        lpPromptDialog.dialog("提示", "是否下载新版本？", "暂不更新", "立即更新", mLeftClickListener, sureListener);
    }



}
