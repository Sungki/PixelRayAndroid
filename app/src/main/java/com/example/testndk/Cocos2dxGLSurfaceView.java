package com.example.testndk;

import android.content.Context;
import android.opengl.GLSurfaceView;

public class Cocos2dxGLSurfaceView extends GLSurfaceView {
    public Cocos2dxGLSurfaceView(Context context) {
        super(context);
        mRenderer = new Cocos2dxRenderer();
        setRenderer(mRenderer);
    }

    Cocos2dxRenderer mRenderer;
}
