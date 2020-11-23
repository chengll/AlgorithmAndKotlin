package us.mifeng.demo;

import android.app.Application;
import android.content.Context;

public class BaseApplication extends Application {
    private static Context context;

    //获取上下文
    public static Context getInstance(){
        return context.getApplicationContext();
    }

    @Override
    public void onCreate() {
        super.onCreate();
        context = this;
    }
}
