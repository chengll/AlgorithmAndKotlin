package us.mifeng.demo.javareflect;

import android.os.Bundle;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Looper;
import android.os.Message;
import android.os.PersistableBundle;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class HandlerCase  extends AppCompatActivity {
    private Handler mHandler=new Handler(){
        @Override
        public void handleMessage(@NonNull Message msg) {
           // super.handleMessage(msg);
            switch (msg.what){

            }
        }
    };
    public void openThread(){
        //子线程和主线程通信
        new Thread(){
            @Override
            public void run() {
               Message msg=Message.obtain();
               msg.obj="子线程向主线程发送消息~";
               mHandler.sendMessage(msg);
            }
        }.start();
    }

  private MyThread myThread;
    @Override
    public void onCreate(@Nullable Bundle savedInstanceState, @Nullable PersistableBundle persistentState) {
        super.onCreate(savedInstanceState, persistentState);
        myThread=new MyThread();
        myThread.start();

        mHandler=new Handler(myThread.looper){
            @Override
            public void handleMessage(android.os.Message msg) {
                super.handleMessage(msg);
                Log.d("TAG", "handleMessage: ---当前的子线程为："+Thread.currentThread());
            }
        };
        //主线程向子线程发送消息
        mHandler.sendEmptyMessage(0);
        /**
         * 注意这里运行时报空，因为 Handler在主线程中初始化的时候，myThread.looper 还没有完成，
         * 所以报空，因此我们要用另外一种方式，Android 提供的HandlerThread 类来实现。
         * */
        HandlerThread handlerThread=new HandlerThread("handler thread");
        handlerThread.start();
        mHandler=new Handler(handlerThread.getLooper()){
            @Override
            public void handleMessage(android.os.Message msg) {
                super.handleMessage(msg);
                Log.d("TAG", "handleMessage: ---当前的子线程为："+Thread.currentThread());
            }
        };
        //主线程向子线程发送消息
        mHandler.sendEmptyMessage(1);
    }

    /***********主线程向子线程间的通信******/

    class MyThread extends Thread{
        private Looper looper;

        @Override
        public void run() {
            Looper.prepare();  //创建子线程的looper对象
            looper=Looper.myLooper(); //取出该子线程的Looper
            Looper.loop();          //调用该方法来不断轮询取出消息
        }

        private Handler mHandler; //将mHandler指定为轮询的Looper
    }


    //3.子线程向子线程通信
    Handler childHandler;
    public void createSubThread1(){
        //子线程1
        new Thread(new Runnable() {
            @Override
            public void run() {
                Looper.prepare();
                childHandler=new Handler(){
                    @Override
                    public void handleMessage(@NonNull Message msg) {
                        super.handleMessage(msg);
                        Log.d("TAG", "这个消息是从"+msg.obj+"发送过来的，在btn的子线程中执行的");
                    }
                };
                Looper.loop();
            }
        }).start();
    }

        //  子线程2
    public void createSubThread2(){
        new Thread(new Runnable() {
            @Override
            public void run() {
                Looper looper = Looper.myLooper();
                Message message = childHandler.obtainMessage();
                message.obj="btn当中的子线程";
                //子线程2 向子线程1 发送消息
                childHandler.sendMessage(message);
            }
        }).start();
    }

}
