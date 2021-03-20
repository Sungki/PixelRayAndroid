package com.example.testndk;

import android.app.Activity;
import android.os.Bundle;
import android.util.DisplayMetrics;

public class Cocos2dxActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // get frame size
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        screenWidth = dm.widthPixels;
        screenHeight = dm.heightPixels;
    }

    public static int screenWidth;
    public static int screenHeight;
}
