package com.sample.zhanganl.ndkjnidemo3;

/**
 * Created by zhanganl on 2017/2/20.
 */

public class NdkJniUtils extends NdkJniUtilsParent {
    private String s;
    private static int n;
    public native String getCLanguageString(String aa);
    public native int sum(int [] arr);
    public native int[][] initInt2DArray(int size);
    public native void accessField();
    public native void accessStaticField();
    public native void nativeMethod();

    //访问构造方法
    public native void accessConstructMethod();

    //访问父类方法
    public native void accessParentMethod();

    public NdkJniUtils(String s1,int n1)
    {
        s=s1;
        n=n1;
    }

    private void callback() {
        System.out.println("In Java");
    }
    public void main()
    {
        s="abc";
        n=100;
    }
    public String getString()
    {
        return s;
    }
    public int getInt()
    {
        return n;
    }

    public void feildPrint()
    {
        System.out.println(s+"  "+n+"  "+m);
    }

    public void eat()
    {
        System.out.println("i am eating in son");
    }

    static {
        System.loadLibrary("YanboberJniLibName");   //defaultConfig.ndk.moduleName
    }
}
