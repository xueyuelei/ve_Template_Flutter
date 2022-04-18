package com.example.flutter_app_demo_2_0_0;

import android.Manifest;
import android.Manifest.permission;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;
import com.volcengine.mars.update.OnUpdateStatusChangedListener;
import com.volcengine.mars.update.VEUpdate;
import com.volcengine.mars.update.UpdateConfig;
import com.volcengine.mars.update.UpdateDialogStyle;
import com.volcengine.mars.update.UpdateStrategyInfo;
import com.volcengine.mars.permissions.PermissionsManager;
import io.flutter.embedding.android.FlutterActivity;
import java.lang.ref.WeakReference;

public class MainActivity extends FlutterActivity {
    private static final String TAG = "UpdateHomeActivity";
    private Button mButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        String[] permissions = new String[]{
                permission.ACCESS_NETWORK_STATE,
                permission.READ_PHONE_STATE,
                permission.WRITE_EXTERNAL_STORAGE,
                permission.ACCESS_WIFI_STATE,
                permission.ACCESS_COARSE_LOCATION,
                permission.REQUEST_INSTALL_PACKAGES
        };
        PermissionsManager.getInstance().requestPermissionsIfNecessaryForResult(this, permissions,null);
        setContentView(R.layout.activity_main);
        mButton = findViewById(R.id.updateButton);
        UpdateConfig updateConfig = getUpdateConfig();
        VEUpdate.initialize(updateConfig);
        VEUpdate.setCheckSignature(false);
        mButton.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(final View v) {
                VEUpdate.checkUpdate(MainActivity.this, UpdateDialogStyle.STYLE_BIG_INNER, new OnUpdateStatusChangedListener() {
                    @Override
                    public void onUpdateStatusChanged(final int status) {
                        boolean isUpdateAvailable = VEUpdate.isRealCurrentVersionOut();
                        Log.d(TAG, "onUpdateStatusChanged status = " + status);
                    }

                    @Override
                    public void saveDownloadInfo(final int size, final String etag, final boolean pre) {
                        Log.d(TAG, "onUpdateStatusChanged saveDownloadInfo = " + pre);
                    }

                    @Override
                    public void updateProgress(final int byteSoFar, final int contentLength, final boolean pre) {
                        Log.d(TAG, "onUpdateStatusChanged updateProgress = " + pre);
                    }

                    @Override
                    public void downloadResult(final boolean isSuccess, final boolean pre) {
                        Log.d(TAG, "onUpdateStatusChanged downloadResult = " + isSuccess);
                    }

                    @Override
                    public void onPrepare(final boolean pre) {
                        Log.d(TAG, "onUpdateStatusChanged onPrepare = " + pre);
                    }
                },false);
            }
        });

    }
    public UpdateConfig getUpdateConfig() {
        int drawableRes = R.drawable.status_icon;

        String authority = "com.mars.android.update";

        return new UpdateConfig.Builder()
                .setAppCommonContext(new AppCommonContextImpl(this))
                .setIUpdateForceExit(new UpdateForceExitImpl())
                .setNotifyIcon(drawableRes)
                .setFormalAuthority(authority)
                .build();

    }
}