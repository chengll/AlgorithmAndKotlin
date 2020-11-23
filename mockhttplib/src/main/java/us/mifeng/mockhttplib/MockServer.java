package us.mifeng.mockhttplib;

import android.content.Context;

import com.koushikdutta.async.AsyncServer;
import com.koushikdutta.async.http.server.AsyncHttpServer;

import org.jetbrains.annotations.NotNull;

import kotlin.jvm.internal.Intrinsics;

/**
 * mocky服务类
 * */
public class MockServer {
    private AsyncHttpServer asyncHttpServer;
    private AsyncServer asyncServer;
    private Context context;

    public void startServer(@NotNull Context context){
        this.context=context;
        Intrinsics.checkParameterIsNotNull(context, "context");
        asyncHttpServer=new AsyncHttpServer();
        asyncServer=new AsyncServer();
    }
}
