package com.example.testndk;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.Log;

public class ApplicationDemo extends Cocos2dxActivity {
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        mGLView = new Cocos2dxGLSurfaceView(this);
        setContentView(mGLView);
    }

    @Override
    protected void onPause() {
        super.onPause();
//        mGLView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
//        mGLView.onResume();
    }

    private GLSurfaceView mGLView;

    static {
        System.loadLibrary("native-lib");
    }
}
