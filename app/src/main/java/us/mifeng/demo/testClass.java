package us.mifeng.demo;

import android.util.Log;

public class testClass {
    public static void main(String[] args) {
        String url=String.format("%s%s%s","https://baidu.coom","&openId=","12242424");
        String titleText = String.format("%s%s%s","热门活动（共","10","个)");
        String fileName=String.format("%s%s%s",System.currentTimeMillis(),".","hhtps://ww.bai.com/img.jpg");
        Log.d("gsgsg", "onClick: --拼接后url为---"+fileName);
    }
}
