package us.mifeng.mockhttplib;

import com.google.gson.Gson;

import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;
import java.util.List;

/**
 * 模拟请求的实体类
 * */
public class MockEntity {
    @NotNull
    private String status;
    @NotNull
    private String code;
    @NotNull
    private String requestUrl;
    @NotNull
    private String requestMethod;
    @NotNull
    private String requestBody; //请求体
    @NotNull
    private String queryParams; //查询参数
    @NotNull
    private String responseHeader;
    @NotNull
    private String responseBody;

    //定义Gson,将实体类转化为gson
    private Gson gson=new Gson();
    private List<MockEntity> mockEntitiesList=new ArrayList<>(); //用来存放所有需要请求的实体类
    public String toJson(){
       // gson.toJson()
        return "";
    }



}
