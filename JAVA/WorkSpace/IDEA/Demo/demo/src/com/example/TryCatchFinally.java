package com.example;

public class TryCatchFinally {
    public static int fimc(int i) {
        try {
            System.out.println("try block");
            if (i == 1) return 1;
            int res = 1/(i - 2);
            return res;
        } catch (Exception e) {
            System.out.println("catch block");
            return 2;
        } finally {
            System.out.println("finally block");
        }
    }

    public static void main(String[] args) {
        for(int i = 1; i < 4; i++){
            System.out.println(fimc(i));
        }
    }
}
