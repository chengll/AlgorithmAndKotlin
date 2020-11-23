package us.mifeng.demo.utils;

import android.app.Activity;
import android.content.Context;
import android.os.Build;
import android.util.DisplayMetrics;
import android.view.WindowManager;

import us.mifeng.demo.BaseApplication;


public class Screen320Utils {

    private static int screenWidth = -1;
    private static int screenHeight = -1;
    private static int statusBarHeight = -1;
    private static float scale320 = -1;
    private static float scale = -1;
    private static float fontScale = -1;

    //字体缩放
    public static float SCALEDFONT;

    /**
     * 根据手机的分辨率从dp的单位转成为px(像素)
     */
    public static int dip2px(float dpValue) {
        if (scale == -1) {
            scale = BaseApplication.getInstance().getResources()
                    .getDisplayMetrics().density;
        }
        return (int) (dpValue * scale + 0.5f);
    }

    /**
     * 根据手机的分辨率从px(像素)的单位转成为dp
     */
    public static int px2dip(float pxValue) {
        if (scale == -1) {
            scale = BaseApplication.getInstance().getResources()
                    .getDisplayMetrics().density;
        }
        return (int) (pxValue / scale + 0.5f);
    }

    /**
     * 将px值转换为sp值，保证文字大小不变
     *
     * @param pxValue （DisplayMetrics类中属性scaledDensity）
     * @return
     */
    public static int px2sp(float pxValue) {
        if (fontScale == -1) {
            fontScale = BaseApplication.getInstance().getResources()
                    .getDisplayMetrics().scaledDensity;
        }
        return (int) (pxValue / fontScale + 0.5f);
    }

    /**
     * 将sp值转换为px值，保证文字大小不变
     *
     * @param spValue （DisplayMetrics类中属性scaledDensity）
     * @return
     */
    public static int sp2px(float spValue) {
        if (fontScale == -1) {
            fontScale = BaseApplication.getInstance().getResources()
                    .getDisplayMetrics().scaledDensity;
        }
        return (int) (spValue * fontScale + 0.5f);
    }

    public static int px2px_(float pxValue) {
        if (scale320 == -1) {
            scale320 = getScreenWidth() / 320;
        }
        return (int) (pxValue / scale320);
    }

//    public static int px_2sp(int px_Value) {
//        int px = Utils.getFontSize(px_Value);
//        return px2sp(px);
//    }

    public static int px_2px(float px_Value) {
        if (scale320 == -1) {
            scale320 = getScreenWidth() / 320f;
        }
        return (int) (px_Value * scale320);
    }

    /**
     * 获取屏幕宽度
     *
     * @return
     */
    public static int getScreenWidth() {
        if (screenWidth == -1) {
            WindowManager wm = (WindowManager) BaseApplication.getInstance()
                    .getSystemService(Context.WINDOW_SERVICE);
            screenWidth = wm.getDefaultDisplay().getWidth();

        }
        String manufacturer = Build.MANUFACTURER;
        String model = Build.MODEL;
        if (manufacturer != null && model != null) {
            if ("HUAWEI".equals(manufacturer)) {
                if ("TAH-AN00m".equals(model) || Screen320Utils.getScreenHeight()==2408) {
                    screenWidth = 1148;
                }
            }
        }
        return screenWidth;
    }

    /**
     * 获取屏幕高度（不含状态栏）
     *
     * @return
     */
    public static int getScreenHeight() {
        if (screenHeight == -1) {
            WindowManager wm = (WindowManager) BaseApplication.getInstance()
                    .getSystemService(Context.WINDOW_SERVICE);
            screenHeight = wm.getDefaultDisplay().getHeight()
                    - getStatusBarHeight();
        }
        return screenHeight;
    }

    /**
     * 获取状态栏高度
     *
     * @return
     */
    public static int getStatusBarHeight() {
        if (statusBarHeight == -1) {
            int resourceId = BaseApplication.getInstance().getResources()
                    .getIdentifier("status_bar_height", "dimen", "android");
            if (resourceId > 0) {
                statusBarHeight = BaseApplication.getInstance().getResources()
                        .getDimensionPixelSize(resourceId);
            }
        }
        return statusBarHeight;
    }

    /**
     * 获取适配值
     *
     * @param value
     * @return
     */
    public static int getScaledValueY(float value) {
        if (scale320 == -1) {
            scale320 = getScreenWidth() / 320f;
        }
        return (int) (value * scale320);
    }

    /**
     * 获取适配值
     *
     * @param value
     * @return
     */
    public static int getScaledValueX(float value) {
        if (scale320 == -1) {
            scale320 = getScreenWidth() / 320f;
        }
        return (int) (value * scale320);
    }

    public static int px_2sp(int px_Value) {
        int px = getFontSize(px_Value);
        return px2sp(px);
    }

    public final static int getFontSize(int size) {
        size = (int) (size * SCALEDFONT);
        return size;
    }

    public final static void calculateScreenSize(Activity activity) {

        DisplayMetrics dm = new DisplayMetrics();
        activity.getWindowManager().getDefaultDisplay().getMetrics(dm);

        SCALEDFONT = 1;
        int dw = dm.widthPixels;
        int dh = dm.heightPixels;
        float ds = dm.scaledDensity;

        // 普通屏幕。
        if (dw <= 480) {
            SCALEDFONT = dw / 360.0f;
            if (dw <= 240 && dh <= 320) {
                if (ds != 0.75f) {
                    SCALEDFONT = 0.75f / ds;
                }
            } else if (dw <= 320 && dh <= 500) {
                if (ds != 1f) {
                    SCALEDFONT = 1f / ds;
                }
            } else if (dw <= 480 && dh <= 900) {
                if (ds != 1.5f) {
                    SCALEDFONT = 1.5f / ds;
                }
            }
        }
        // 大屏幕。
        else {
            if (dw <= 600) {
                if (ds != 2f) {
                    SCALEDFONT = 2f / ds;
                }
            } else {
                SCALEDFONT = ds;
            }
        }
        // 特殊机型字号适配。
        String manufacturer = Build.MANUFACTURER;
        String model = Build.MODEL;
        if (manufacturer != null && model != null) {
            if ("Xiaomi".equals(manufacturer) && "MI 2S".equals(model)) {
                SCALEDFONT = dw / 360.0f;
            } else if ("samsung".equals(manufacturer)
                    && "GT-P5110".equals(model)) {
                SCALEDFONT = dw / 480.0f;
            } else if ("samsung".equals(manufacturer)
                    && "GT-N5110".equals(model)) {
                SCALEDFONT = dw / 480.0f;
            } else if ("asus".equals(manufacturer) && "Nexus 7".equals(model)) {
                SCALEDFONT = dw / 480.0f;
            }
        }

    }
}
