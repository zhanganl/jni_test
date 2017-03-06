package com.sample.zhanganl.ndkjnidemo3;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        System.out.println("aaaa");

        NdkJniUtils jni = new NdkJniUtils("",0);
        String aa="hello jni";
        String bb;
        for(int i=0;i<5;i++)
        {
            jni.getCLanguageString(aa);
            //aa=bb;
            System.out.println("zhanganl"+"  "+i +aa);
        }
        int arr[] = new int[100000];
        for (int i = 0; i < 100000; i++) {
            arr[i] = i;
        }
        System.out.println("sum" + jni.sum(arr));

        int[][] i2arr = jni.initInt2DArray(3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(" " + i2arr[i][j]);
            }
            System.out.println();
        }

        jni.main();
        jni.accessField();
        System.out.println(jni.getString());

        jni.accessStaticField();
        System.out.println(jni.getInt());

        jni.nativeMethod();

        jni.accessConstructMethod();

        jni.accessParentMethod();
    }
}
