package com.example.testndk;

import android.opengl.GLSurfaceView;
import android.os.Bundle;

public class ApplicationDemo extends Cocos2dxActivity {
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);

        mGLView = new Cocos2dxGLSurfaceView(this);
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
}
