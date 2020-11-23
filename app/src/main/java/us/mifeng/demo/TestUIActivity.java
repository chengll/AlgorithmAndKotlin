package us.mifeng.demo;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.PersistableBundle;
import android.util.Log;
import android.view.View;

import me.wcy.mockhttp.MockHttp;
import me.wcy.mockhttp.MockHttpOptions;

public class TestUIActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_test_ui);
        findViewById(R.id.get_data).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String url=String.format("%s%s%s","https://baidu.coom","&openId=","12242424");
                Log.d("gsgsg", "onClick: --拼接后url为---"+url);
            }
        });
    }



    @Override
    public void onPostCreate(@Nullable Bundle savedInstanceState, @Nullable PersistableBundle persistentState) {
        super.onPostCreate(savedInstanceState, persistentState);

    }
}
