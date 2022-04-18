package com.example.flutter_app_demo_2_0_0;


import android.content.Context;
import com.volcengine.mars.update.AbsAppCommonContext;
import com.volcengine.mars.update.DeviceWrapper;
import java.util.Map;
import org.jetbrains.annotations.NotNull;

public class AppCommonContextImpl extends AbsAppCommonContext {

    private Context mContext;

    public AppCommonContextImpl(Context context) {
        mContext = context;
    }
    @NotNull
    @Override
    public Context getContext() {
        return mContext;
    }

    @Override
    public String getStringAppName() {
        return "升级SDK Demo";
    }

    @NotNull
    @Override
    public String getDeviceId() {
//        DeviceWrapper deviceService = new DeviceWrapper();
        return "00000";
    }


    @Override
    public Map<String, String> getCustomKV() {
        return null;
    }
}
