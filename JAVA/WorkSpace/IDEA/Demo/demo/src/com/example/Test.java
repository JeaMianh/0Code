package com.example;

class MyThread extends Thread {
    @Override
    public void run () {
        System.out.println("这就是一个新线程了！");
    }
}
public class Test {
    public static void main(String[] args) {
        MyThread myThread = new MyThread();
        myThread.start();
    }
}